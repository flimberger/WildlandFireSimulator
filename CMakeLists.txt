cmake_minimum_required(VERSION 3.5)

project(WildlandFireSimulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    main.cpp
    fire.cpp
    firemap.cpp
    example_landscape.cpp
    simulation.cpp
    utility.cpp
    csvreader.cpp
    fireweather.cpp)
