#pragma once

#include <algorithm>

#include "trending/Span.h"

namespace trending {

template <class T, class F>
double avg(span<T> sp, F get) {
  double sum = 0;
  for (auto& v : sp) {
    sum += get(v);
  }
  return sp.empty() ? 0 : sum / sp.size();
}

template <size_t R, class T, class F>
std::vector<double> ma(span<T> sp, F get) {
  std::vector<double> out;
  for (size_t i = R - 1; i < sp.size(); ++i) {
    out.push_back(avg(sp.subspan(i, R), get));
  }
  return out;
}

}  // namespace trending
