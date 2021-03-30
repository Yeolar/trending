/*
 * Copyright 2021 Yeolar
 */

#include <gtest/gtest.h>
#include "trending/Convex.h"

using namespace trending;

TEST(Convex, convex) {
  {
    std::vector<double> v0;
    Convex result = convex(v0);
    EXPECT_DOUBLE_EQ(0, result.range);
    EXPECT_DOUBLE_EQ(0, result.slop);
    EXPECT_DOUBLE_EQ(0, result.diff);
  }
  {
    std::vector<double> v1 = {1};
    Convex result = convex(v1);
    EXPECT_DOUBLE_EQ(1, result.range);
    EXPECT_DOUBLE_EQ(0, result.slop);
    EXPECT_DOUBLE_EQ(0, result.diff);
  }
  {
    std::vector<double> v2 = {1,2};
    Convex result = convex(v2);
    EXPECT_DOUBLE_EQ(2, result.range);
    EXPECT_DOUBLE_EQ(1, result.slop);
    EXPECT_DOUBLE_EQ(0, result.diff);
  }
  {
    std::vector<double> v3 = {1,2.5,3};
    Convex result = convex(v3);
    EXPECT_DOUBLE_EQ(3, result.range);
    EXPECT_DOUBLE_EQ(1, result.slop);
    EXPECT_DOUBLE_EQ(0.5, result.diff);
  }
  {
    std::vector<double> v4 = {1,2.5,2.8,4};
    Convex result = convex(v4);
    EXPECT_DOUBLE_EQ(3, result.range);
    EXPECT_DOUBLE_EQ(0.75, result.slop);
    EXPECT_DOUBLE_EQ(-0.45, result.diff);
  }
  {
    std::vector<double> v8 = {1,2,3,3.5,5,6.5,8,8};
    Convex result = convex(v8);
    EXPECT_DOUBLE_EQ(5, result.range);
    EXPECT_DOUBLE_EQ(1.125, result.slop);
    EXPECT_DOUBLE_EQ(1.125, result.diff);
  }
}
