# A simple Visual Odometry with Intel Depth Camera D435i

The visual frontend uses optical flow tracking. Backend optimization is implemented in g2o.

It runs at 300 fps on i7-10875H.

A simple RGB-D Reconstruction system can be found at: https://github.com/JerryZhang19/Simple-RGBD-Reconstruction


# Usage
For live realsense camera tracking, in run_realsense.cpp set vo->SetRealtime(true) .
Camera intrinsics is loaded from data/calib.txt. By default, 640x480 @60fps is used, and corresponding intrinsics is provided.

For pre-recorded RGB-D videos, set vo->SetRealtime(false) .
Please place RGB image in data/color, and place depth image in data/depth. Image format is 00000.png,00001.png.
You can download a sample dataset from [google drive](https://drive.google.com/file/d/1sRiMUDsCblOJvfsJIYqycoguT74RjG8h/view?usp=sharing) or
change dataset directory in config/default.yaml.

You can enable timing test by uncommenting #define TEST_PERFORMANCE in common_include.h

## Limitations and potential for extension
Loop Closure: A BoW visual loop closure detection can be integrated into the system. To this end, repeatable corners (FAST,SIFT) should be detected and descriptors should be computed. A pose graph will be needed in the system to perform global pose graph optimization.

For better accuracy, structures that enable mid-term data association like Covisibility Graph introduced in ORB-SLAM could be added.

For IMU fusion, methods introduced in VINS-MONO could be integrated.

## Reference
slambook2 https://github.com/gaoxiang12/slambook2 which gives a great introduction to Visual SLAM.

Code framework inherited from a simple stereo odometry in slambook2.


## DEPENDENCY

* CMake,

        sudo apt-get install cmake

* google-glog + gflags,

        sudo apt-get install libgoogle-glog-dev
        
* Eigen3,

        sudo apt-get install libeigen3-dev

* SuiteSparse and CXSparse,

        sudo apt-get install libsuitesparse-dev

* Boost,

        sudo apt-get install libboost-dev libboost-filesystem-dev
        
* OpenCV 3 or OpenCV 4

* Pangolin, 

        https://github.com/stevenlovegrove/Pangolin.git
        
* g2o, 

        https://github.com/RainerKuemmerle/g2o
        
* librealsense, 

        https://github.com/IntelRealSense/librealsense
       
      
