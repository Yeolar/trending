/*
 * Copyright 2021 Yeolar
 */

#include <cmath>

#include "trending/Sine.h"

namespace trending {

const double pi = std::acos(-1);

Sine sine(span<double> sp) {
  Sine result;

  double xx = 0, xy = 0, yy = 0;
  size_t n = sp.size();
  result.b = pi / (n - 1);
  for (size_t x = 0; x < n; ++x) {
    double y = sp[x];
    x = x * result.b;
    xx += sin(x) * sin(x);
    xy += sin(x) * y;
    yy += y * y;
  }
  result.a = xy / xx;
  double aa = result.a * result.a;
  result.sd = sqrt(yy + aa * xx - 2 * result.a * xy);

  return result;
}

} // namespace trending
