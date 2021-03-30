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
    EXPECT_DOUBLE_EQ(0.52359877559829882, result.b);
    EXPECT_DOUBLE_EQ(0.000000029802322387695312, result.sd);
  }
}
