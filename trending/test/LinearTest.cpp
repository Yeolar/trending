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
    EXPECT_DOUBLE_EQ(0.99761904761904707, result.a);
    EXPECT_DOUBLE_EQ(1.0333333333333328, result.b);
    EXPECT_DOUBLE_EQ(0.18644544714705433, result.sd);
  }
  {
    std::vector<double> v8 = {1,2,3,4.4,5,6,7,8};
    Linear result = linear(v8);
    EXPECT_DOUBLE_EQ(0.99523809523809514, result.a);
    EXPECT_DOUBLE_EQ(1.0666666666666682, result.b);
    EXPECT_DOUBLE_EQ(0.37289089429433731, result.sd);
  }
  {
    std::vector<double> v8 = {1,2,3,4.6,5,6,7,8};
    Linear result = linear(v8);
    EXPECT_DOUBLE_EQ(0.99285714285714322, result.a);
    EXPECT_DOUBLE_EQ(1.0999999999999983, result.b);
    EXPECT_DOUBLE_EQ(0.55933634144141697, result.sd);
  }
}
