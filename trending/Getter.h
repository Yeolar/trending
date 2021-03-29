/*
 * Copyright 2021 Yeolar
 */

#pragma once

#include <vector>

#include "trending/Span.h"

namespace trending {

/*
 * array[-k-n:-k]
 */
template <class T>
std::vector<double> getLatest(T& array, int k, int n) {
  std::vector<double> result;
  for (k = array.size() - k - 1; k >= 0 && n > 0; --k, --n) {
    double v = array[k];
    result.push_back(v);
  }
  return result;
}

template <class T, class F>
std::vector<double> getLatest(T& array, int k, int n, F get) {
  std::vector<double> result;
  for (k = array.size() - k - 1; k >= 0 && n > 0; --k, --n) {
    double v = get(array[k]);
    result.push_back(v);
  }
  return result;
}

template <class T>
std::vector<double> getLatestLt0(T& array, int k, int n) {
  std::vector<double> result;
  for (k = array.size() - k - 1; k >= 0 && n > 0; --k, --n) {
    double v = array[k];
    if (v >= 0) break;
    result.push_back(v);
  }
  return result;
}

template <class T, class F>
std::vector<double> getLatestLt0(T& array, int k, int n, F get) {
  std::vector<double> result;
  for (k = array.size() - k - 1; k >= 0 && n > 0; --k, --n) {
    double v = get(array[k]);
    if (v >= 0) break;
    result.push_back(v);
  }
  return result;
}

} // namespace trending
