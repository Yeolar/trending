/*
 * Copyright 2021 Yeolar
 */

#include <gtest/gtest.h>
#include <vector>
#include "trending/Avg.h"

using namespace trending;

TEST(Avg, avg) {
  std::vector<double> v0;
  EXPECT_DOUBLE_EQ(0, avg(v0));

  std::vector<double> v8 = {1,2,3,4,5,6,7,8};
  EXPECT_DOUBLE_EQ(4.5, avg(v8));
}

TEST(Avg, lastRateOfAvg) {
  std::vector<double> v0;
  EXPECT_DOUBLE_EQ(0, lastRateOfAvg(v0));

  std::vector<double> v8 = {1,2,3,4,5,6,7,8};
  EXPECT_DOUBLE_EQ(8 / 4.5, lastRateOfAvg(v8));
}

TEST(Avg, ma) {
  std::vector<double> v8 = {1,2,3,4,5,6,7,8};
  auto v = ma<5>(v8);
  EXPECT_EQ(4, v.size());
  EXPECT_DOUBLE_EQ(3, v[0]);
  EXPECT_DOUBLE_EQ(4, v[1]);
  EXPECT_DOUBLE_EQ(5, v[2]);
  EXPECT_DOUBLE_EQ(6, v[3]);
}
