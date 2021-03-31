/*
 * Copyright 2021 Yeolar
 */

#include <cmath>
#include <gtest/gtest.h>
#include "trending/Sine.h"

using namespace trending;

TEST(Sine, sine) {
  {
    std::vector<double> v = {
      0,
      0.5,
      std::sqrt(3) / 2,
      1,
      std::sqrt(3) / 2,
      0.5,
      0
    };
    Sine result = sine(v);
    EXPECT_DOUBLE_EQ(1, result.a);
    EXPECT_NEAR(0.523598, result.b, 1e-6);
    EXPECT_NEAR(0.000000, result.sd, 1e-6);
  }
}
