cmake_minimum_required(VERSION 3.5)

project(WildlandFireSimulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    main.cpp
    fire.cpp
    WFS_landscape.cpp
    WFS_fireweather.cpp
    WFS_output.cpp
    month.cpp
    simulation.cpp
    utility.cpp
    csvreader.cpp)

add_executable(test_month
    test_month.cpp
    month.cpp)

enable_testing()

add_test(MonthTest test_month)
