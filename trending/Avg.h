/*
 * Copyright 2021 Yeolar
 */

#pragma once

#include <vector>

#include "trending/Span.h"

namespace trending {

double avg(span<const double> sp);

double lastRateOfAvg(span<const double> sp);

template <size_t R>
std::vector<double> ma(span<const double> sp) {
  std::vector<double> out;
  for (size_t i = 0; i + R <= sp.size(); ++i) {
    out.push_back(avg(sp.subspan(i, R)));
  }
  return out;
}

}  // namespace trending
