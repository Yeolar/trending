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
  double a;
  double b;
  double sd;
};

Linear linear(span<double> sp);

} // namespace trending
