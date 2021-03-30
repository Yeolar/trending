/*
 * Copyright 2021 Yeolar
 */

#pragma once

#include "trending/Span.h"

namespace trending {

/*
 * a * x + b
 */

struct Linear {
  double a = 0;
  double b = 0;
  double sd = 0;
};

Linear linear(span<double> sp);

} // namespace trending
