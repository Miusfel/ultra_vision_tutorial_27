cmake_minimum_required(VERSION 3.16)
project(task_1 LANGUAGES CXX)

find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui videoio calib3d)
find_package(fmt CONFIG REQUIRED)

add_executable(task_1_app
    src/main.cpp
    src/detector.cpp
    src/solver.cpp
)
target_compile_features(task_1_app PRIVATE cxx_std_17)
target_link_libraries(task_1_app PRIVATE
    opencv_core
    opencv_imgproc
    opencv_highgui
    opencv_videoio
    opencv_calib3d
    fmt::fmt
)
