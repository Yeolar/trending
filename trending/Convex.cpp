/*
 * Copyright 2021 Yeolar
 */

#include <vector>

#include "trending/Convex.h"

namespace trending {

enum Direction {
  kUnInit,
  kInit,
  kConvex,
  kConcave
};

static double slope(double y1, double y2, int a, int b) {
  return (y1 - y2) / (a - b);
}

Convex convex(span<double> sp) {
  Convex result;
  result.slop = 0;
  result.diff = 0;

  double current = sp.back();
  std::vector<double> values;
  Direction direction = kUnInit;
  int k0 = sp.size() - 1;
  int k = k0;

  for (--k; k >= 0; --k) {
    double value = sp[k];
    values.push_back(value);
    double s = slope(value, current, k, k0);
    switch (direction) {
      case kUnInit:
        direction = kInit;
        result.slop = s;
        break;
      case kInit:
        if (s > result.slop) {
          direction = kConvex;
        } else if (s < result.slop) {
          direction = kConcave;
        }
        result.slop = s;
        break;
      case kConvex:
        if (s >= result.slop) {
          result.slop = s;
        } else {
          ++k;
          goto kEnd;
        }
        break;
      case kConcave:
        if (s <= result.slop) {
          result.slop = s;
        } else {
          ++k;
          goto kEnd;
        }
        break;
    }
  }

kEnd:
  result.range = k0 - k;
  for (int i = 0; i < result.range; ++i) {
    double d = values[i] - (current - result.slop * (i + 1));
    if ((d > result.diff && direction == kConvex) ||
        (d < result.diff && direction == kConcave)) {
      result.diff = d;
    }
  }

  return result;
}

} // namespace trending
