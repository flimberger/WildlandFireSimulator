add_executable(test_month
    test_month.cpp
    ../month.cpp
    test_base.cpp)

add_test(MonthTest test_month)
