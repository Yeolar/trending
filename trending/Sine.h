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
  double a;
  double b;
  double sd;
};

Sine sine(span<double> sp);

} // namespace trending
