/*
 * Copyright 2021 Yeolar
 */

#pragma once

#include "trending/Span.h"

namespace trending {

struct Convex {
  int range = 0;
  double slop = 0;
  double diff = 0;
};

Convex convex(span<const double> sp);

} // namespace trending
