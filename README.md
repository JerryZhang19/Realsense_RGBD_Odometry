# A simple Visual Odometry system using Intel Realsense D435i

Use Optical Flow tracking and g2o optimization.Currently runs at 30-80 fps on i7-9750H


## Related work
A simple RGB-D Reconstruction system: https://github.com/JerryZhang19/Simple-RGBD-Reconstruction

It's still in progress and uses similar code structure.

## Future Work
Add IMU Fusion.

Loop Closure

Mapping Loading 

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

* Pangolin, 

        https://github.com/stevenlovegrove/Pangolin.git
        
* g2o, 

        https://github.com/RainerKuemmerle/g2o
        
* librealsense, 

        https://github.com/IntelRealSense/librealsense
       
      
