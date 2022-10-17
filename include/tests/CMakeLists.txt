add_demo_test(Vec3TestSuite Vec3TestSuite.cpp)

target_link_libraries(
    Vec3TestSuite.test
    GTest::gtest_main
)

target_include_directories(Vec3TestSuite.test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
