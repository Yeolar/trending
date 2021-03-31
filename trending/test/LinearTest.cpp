/*
 * Copyright 2021 Yeolar
 */

#include <gtest/gtest.h>
#include "trending/Linear.h"

using namespace trending;

TEST(Linear, linear) {
  {
    std::vector<double> v8 = {0,1,2,3,4,5,6,7};
    Linear result = linear(v8);
    EXPECT_DOUBLE_EQ(1, result.a);
    EXPECT_DOUBLE_EQ(0, result.b);
    EXPECT_DOUBLE_EQ(0, result.sd);
  }
  {
    std::vector<double> v8 = {1,2,3,4,5,6,7,8};
    Linear result = linear(v8);
    EXPECT_DOUBLE_EQ(1, result.a);
    EXPECT_DOUBLE_EQ(1, result.b);
    EXPECT_DOUBLE_EQ(0, result.sd);
  }
  {
    std::vector<double> v8 = {1,2,3,4.2,5,6,7,8};
    Linear result = linear(v8);
    EXPECT_NEAR(0.997619, result.a, 1e-6);
    EXPECT_NEAR(1.033333, result.b, 1e-6);
    EXPECT_NEAR(0.186445, result.sd, 1e-6);
  }
  {
    std::vector<double> v8 = {1,2,3,4.4,5,6,7,8};
    Linear result = linear(v8);
    EXPECT_NEAR(0.995238, result.a, 1e-6);
    EXPECT_NEAR(1.066666, result.b, 1e-6);
    EXPECT_NEAR(0.372890, result.sd, 1e-6);
  }
  {
    std::vector<double> v8 = {1,2,3,4.6,5,6,7,8};
    Linear result = linear(v8);
    EXPECT_NEAR(0.992857, result.a, 1e-6);
    EXPECT_NEAR(1.099999, result.b, 1e-6);
    EXPECT_NEAR(0.559336, result.sd, 1e-6);
  }
}
