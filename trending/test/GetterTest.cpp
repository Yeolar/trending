/*
 * Copyright 2021 Yeolar
 */

#include <gtest/gtest.h>
#include "trending/Avg.h"
#include "trending/Getter.h"

using namespace trending;

TEST(Getter, getLatest) {
  std::vector<double> v8 = {1,2,3,4,5,6,7,8};
  {
    auto v = getLatest(v8, 0, 8);
    EXPECT_DOUBLE_EQ(4.5, avg(v));
  }
  {
    auto v = getLatest(v8, 3, 8);
    EXPECT_DOUBLE_EQ(3.0, avg(v));
  }
  {
    auto v = getLatest(v8, 3, 3);
    EXPECT_DOUBLE_EQ(4.0, avg(v));
  }
}

