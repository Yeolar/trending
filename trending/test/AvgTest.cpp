/*
 * Copyright 2021 Yeolar
 */

#include <gtest/gtest.h>
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
