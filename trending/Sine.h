/*
 * Copyright 2021 Yeolar
 */

#pragma once

#include "trending/Span.h"

namespace trending {

/*
 * a * sin(x * b)
 */

struct Sine {
  double a = 0;
  double b = 0;
  double sd = 0;
};

Sine sine(span<const double> sp);

} // namespace trending
