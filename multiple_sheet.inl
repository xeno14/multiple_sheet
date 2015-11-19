#include <cassert>

#include <iostream>

namespace multiple_sheet {

template <class T>
template <class InputIterator>
void MultipleSheet<T>::prepend_row(InputIterator first, InputIterator last) {
  std::vector<T> next;
  assert(num_ * cols_ == static_cast<std::size_t>(std::distance(first, last)));
  for (std::size_t n = 0; n < num_; n++) {
    next.insert(next.end(), first + n * cols_, first + (n + 1) * cols_);
    next.insert(next.end(), iterator_at(n, 0, 0), iterator_at(n + 1, 0, 0));
  }
  data_ = std::move(next);
  ++rows_;
}

template <class T>
template <class InputIterator>
void MultipleSheet<T>::append_row(InputIterator first, InputIterator last) {
  std::vector<T> next;
  assert(num_ * cols_ == static_cast<std::size_t>(std::distance(first, last)));
  for (std::size_t n = 0; n < num_; n++) {
    next.insert(next.end(), iterator_at(n, 0, 0), iterator_at(n + 1, 0, 0));
    next.insert(next.end(), first + n * cols_, first + (n + 1) * cols_);
  }
  data_ = std::move(next);
  ++rows_;
}

template <class T>
std::vector<std::tuple<std::size_t, std::size_t, std::size_t, std::size_t>>
    MultipleSheet<T>::list_index() const {
  std::vector<std::tuple<std::size_t, std::size_t, std::size_t, std::size_t>>
      res;
  for (std::size_t n = 0; n < num(); n++) {
    auto tmp = list_index(n);
    res.insert(res.end(), tmp.begin(), tmp.end());
  }
  return res;
}

template <class T>
std::vector<std::tuple<std::size_t, std::size_t, std::size_t, std::size_t>>
    MultipleSheet<T>::list_index(std::size_t n) const {
  std::vector<std::tuple<std::size_t, std::size_t, std::size_t, std::size_t>>
      res;
  for (std::size_t i = 0; i < rows(); i++) {
    for (std::size_t j = 0; j < cols(); j++) {
      res.emplace_back(index(n, i, j), n, i, j);
    }
  }
  return res;
}
}  // multiple_sheet
