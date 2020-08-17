//
// Created by gaoxiang on 19-5-4.
//
#include "myslam/visual_odometry.h"
#include <chrono>
#include "myslam/config.h"

namespace simpleslam {

inline Vec2 toVec2(const cv::Point2f p) { return Vec2(p.x, p.y); } //simple helper function

VisualOdometry::VisualOdometry(std::string &config_path)
    : config_file_path_(config_path) {}

bool VisualOdometry::Init() {
    // read from config file
    if (Config::SetParameterFile(config_file_path_) == false) {
        return false;
    }

    io_ =IO::Ptr(new IO(Config::Get<std::string>("dataset_dir")));
    io_->SetRealtime(realtime_);
    CHECK_EQ(io_->Init(), true);
    // create components and links
    frontend_ = Frontend::Ptr(new Frontend);
    backend_ = Backend::Ptr(new Backend);
    map_ = Map::Ptr(new Map);
    viewer_ = Viewer::Ptr(new Viewer);
    //mapping_ = Mapping::Ptr(new Mapping());

    frontend_->SetBackend(backend_);
    frontend_->SetMap(map_);
    frontend_->SetViewer(viewer_);
    frontend_->SetCamera(io_->GetCamera(0));

    backend_->SetMap(map_);
    backend_->SetCamera(io_->GetCamera(0));

    viewer_->SetMap(map_);

    return true;
}

void VisualOdometry::Run() {

    while (1) {
        //LOG(INFO) << "VO is running";
        if (Step() == false) {
            break;
        }
    }

    backend_->Stop();
    viewer_->Close();

    LOG(INFO) << "VO exit";
}

bool VisualOdometry::Step() {
    auto t0 = std::chrono::steady_clock::now();
    Frame::Ptr new_frame = io_->NextFrame();
    if (new_frame == nullptr) return false;

#ifdef TEST_PERFORMANCE
    auto t1 = std::chrono::steady_clock::now();
    bool success = frontend_->AddFrame(new_frame);
    auto t2 = std::chrono::steady_clock::now();
    timer1  +=  std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
    timer2  +=  std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t0).count();
    if(io_->GetIndex() % 50 == 0)  //every 30 frames
    {
        LOG(INFO) << "VO cost time: " << timer1/50 << " seconds.";
        LOG(INFO) << "VO Computation Frame rate: " << 50/timer1 ;
        LOG(INFO) << "Frame rate: " << 50/timer2 ;
        timer1=timer2=timer3=0;
    }
#endif

#ifndef TEST_PERFORMANCE
    bool success = frontend_->AddFrame(new_frame);
#endif

    return success;
}


}  // namespace myslam
