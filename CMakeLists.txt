cmake_minimum_required(VERSION 3.5)

project(WildlandFireSimulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(FireModel
    utility.cpp
    fire.cpp)

add_executable(${PROJECT_NAME}
    main.cpp
    WFS_landscape.cpp
    WFS_fireweather.cpp
    WFS_output.cpp
    simulation.cpp
    csvreader.cpp)
target_link_libraries(${PROJECT_NAME} FireModel)
