/*
 * Copyright 2021 Yeolar
 */

#include "trending/Linear.h"

namespace trending {

Linear linear(span<double> sp) {
  Linear result;

  double xx = 0, nx = 0, xy = 0, ny = 0, yy = 0;
  size_t n = sp.size();

  if (n < 2) {
    return result;
  }

  for (size_t x = 0; x < n; ++x) {
    double y = sp[x];
    xx += x * x;
    xy += x * y;
    yy += y * y;
    nx += x;
    ny += y;
  }
  result.a = (xy * n  - nx * ny) / (xx * n - nx * nx);
  result.b = (xx * ny - nx * xy) / (xx * n - nx * nx);
  double aa = result.a * result.a;
  double bb = result.b * result.b;
  double ab = result.a * result.b;
  result.sd = sqrt(yy + aa * xx + bb * n
                   + 2 * ab * nx
                   - 2 * (result.a * xy + result.b * ny));

  return result;
}

} // namespace trending
