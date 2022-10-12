add_demo_test(Vec3TestSuite Vec3TestSuite.cpp)

target_link_libraries(
    Vec3TestSuite.test
    GTest::gtest_main
)
