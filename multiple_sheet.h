/**
 * @file multiple_sheet.h
 * @brief Add description here
 */
#pragma once

#include <vector>

namespace multiple_sheet {

template <class T>
class MultipleSheet {
 public:
  MultipleSheet(std::size_t num, std::size_t rows, std::size_t cols)
      : data_(num * rows * cols), num_(num), rows_(rows), cols_(cols) {}
  std::size_t offset(std::size_t n) const { return n * rows_ * cols_; }
  std::size_t index(std::size_t n, std::size_t i, std::size_t j) const {
    return offset(n) + j + i * cols_;
  }
  std::size_t size() const { return offset(num_); }
  auto begin() { return data_.begin(); }
  auto begin() const { return data_.begin(); }
  auto end() { return data_.end(); }
  auto end() const { return data_.end(); }
  auto iterator_at(std::size_t n, std::size_t i, std::size_t j) {
    return begin() + index(n, i, j);
  }
  auto iterator_at(std::size_t n, std::size_t i, std::size_t j) const {
    return begin() + index(n, i, j);
  }

  T& operator[](std::size_t n) { return data_[n]; }
  const T& operator[](std::size_t n) const { return data_[n]; }
  T& at(std::size_t n, std::size_t i, std::size_t j) {
    return data_.at(index(n, i, j));
  }
  const T& at(std::size_t n, std::size_t i, std::size_t j) const {
    return data_.at(index(n, i, j));
  }

  template <class InputIterator>
  void prepend_row(InputIterator first, InputIterator last);
  template <class Range>
  void prepend_row(const Range& r) {
    prepend_row(std::begin(r), std::end(r));
  }

  template <class InputIterator>
  void append_row(InputIterator first, InputIterator last);
  template <class Range>
  void append_row(const Range& r) {
    append_row(std::begin(r), std::end(r));
  }

 private:
  std::vector<T> data_;
  std::size_t num_, rows_, cols_;
};

}  // namespace multiple_sheet

#include "multiple_sheet.inl"