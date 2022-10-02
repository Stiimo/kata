include(GoogleTest)
add_executable(test_calculator test_calculator.cpp)
target_link_libraries(test_calculator PRIVATE calculator GTest::gtest GTest::gtest_main)
gtest_add_tests(TARGET test_calculator)
