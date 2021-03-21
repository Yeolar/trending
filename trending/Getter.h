/*
 * Copyright 2021 Yeolar
 */

#pragma once

#include <vector>

#include "trending/Span.h"

namespace trending {

/*
 * sp[-k-n:-k]
 */
template <class T, class F>
std::vector<double> getLatest(F get, span<T> sp, int k, int n) {
  std::vector<double> result;
  for (; k < sp.size() && n > 0; ++k, --n) {
    result.push_back(get(sp[k]));
  }
  return result;
}

template <class T, class F>
std::vector<double> getLatestLt0(F get, span<T> sp, int k, int n) {
  std::vector<double> result;
  for (; k < sp.size() && n > 0; ++k, --n) {
    double v = get(sp[k]);
    if (v >= 0) break;
    result.push_back(v);
  }
  return result;
}

} // namespace trending
