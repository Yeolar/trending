/*
 * Copyright 2021 Yeolar
 */

#include "trending/Avg.h"

namespace trending {

double avg(span<double> sp) {
  double sum = 0;
  for (auto& v : sp) {
    sum += v;
  }
  return sp.empty() ? 0 : sum / sp.size();
}

double lastRateOfAvg(span<double> sp) {
  return sp.empty() ? 0 : sp.back() / avg(sp);
}

} // namespace trending
