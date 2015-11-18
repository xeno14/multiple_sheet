#include <cassert>

#include <iostream>

namespace multiple_sheet {

template <class T>
template <class InputIterator>
void MultipleSheet<T>::prepend_row(InputIterator first, InputIterator last) {
  std::vector<T> next;
  assert(num_ * cols_ == std::distance(first, last));
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
  assert(num_ * cols_ == std::distance(first, last));
  for (std::size_t n = 0; n < num_; n++) {
    next.insert(next.end(), iterator_at(n, 0, 0), iterator_at(n + 1, 0, 0));
    next.insert(next.end(), first + n * cols_, first + (n + 1) * cols_);
  }
  data_ = std::move(next);
  ++rows_;
}

}  // multiple_sheet
