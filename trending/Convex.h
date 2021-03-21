/*
 * Copyright 2021 Yeolar
 */

#pragma once

#include "trending/Span.h"

namespace trending {

struct Convex {
  int range;
  double slop;
  double diff;
};

Convex convex(span<double> sp);

} // namespace trending
