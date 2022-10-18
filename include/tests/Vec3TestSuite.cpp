#include <gtest/gtest.h>
#include <cmath>

#include "Vec3.hpp"

namespace {
const Vec3d dummyVec { 1.0, 1.0, 2.0 };
const Vec3d crossResultVec { -1.0, 1.0, 0.0 };
const Vec3d integerVec { 1.5, 1.5, 1.5 };
constexpr auto EXPECTED_DOT_VALUE = 9;
constexpr auto EXPECTED_VALUE = 1.0;
constexpr auto INVALID_INDEX = 4;
constexpr auto EXPECTED_LENGTH_SQUARED = 6.0;
}

TEST(Vec3dTestSuite, VectorShouldReturnExpectedValue)
{
    ASSERT_EQ(dummyVec.at(0), EXPECTED_VALUE);
}

TEST(Vec3dTestSuite, VectorShouldThrowExceptionWhenAccesedWithInvalidIndex)
{
    ASSERT_THROW(dummyVec.at(INVALID_INDEX), std::out_of_range);
}

TEST(Vec3dTestSuite, VectorShouldReturnDotValue)
{
    auto dotVec = Vec3d { 2.0, 1.0, 3.0 };
    ASSERT_EQ(dummyVec.dot(dotVec), EXPECTED_DOT_VALUE);
}

TEST(Vec3dTestSuite, VectorShouldReturnCrossProduct)
{
    auto crossVec = Vec3d { 1.0, 1.0, 1.0 };
    ASSERT_EQ(dummyVec.cross(crossVec), crossResultVec);
}

TEST(Vec3dTestSuite, VectorShouldReturnLengthSquared)
{
    ASSERT_EQ(dummyVec.length_squared(), EXPECTED_LENGTH_SQUARED);
}

TEST(Vec3dConversionTestSuite, IntegerVectorShouldReturnCopyOfSelf)
{
    auto integerVecCopy = Utils::getIntegralVector(integerVec);
}
