#include "multiple_sheet.h"

using multiple_sheet::MultipleSheet;

void append(MultipleSheet<int>& sheet, std::initializer_list<int> l) {
  sheet.append_row(std::begin(l), std::end(l));
}

void prepend(MultipleSheet<int>& sheet, std::initializer_list<int> l) {
  sheet.prepend_row(std::begin(l), std::end(l));
}

int main() {
  MultipleSheet<int> sheet(2, 0, 2);
  assert(sheet.size() == 0);

  append(sheet, {1, 2, 3, 4});
  assert(sheet.size() == 4);
  assert(sheet.at(0, 0, 0) == 1);
  assert(sheet.at(0, 0, 1) == 2);
  assert(sheet.at(1, 0, 0) == 3);
  assert(sheet.at(1, 0, 1) == 4);

  append(sheet, {5, 6, 7, 8});
  assert(sheet.size() == 8);
  assert(sheet.at(0, 0, 0) == 1);
  assert(sheet.at(0, 0, 1) == 2);
  assert(sheet.at(1, 0, 0) == 3);
  assert(sheet.at(1, 0, 1) == 4);
  assert(sheet.at(0, 1, 0) == 5);
  assert(sheet.at(0, 1, 1) == 6);
  assert(sheet.at(1, 1, 0) == 7);
  assert(sheet.at(1, 1, 1) == 8);

  assert(*sheet.iterator_at(0, 0, 1) == 2);
  assert(sheet[1] == 2);

  prepend(sheet, {9, 10, 11, 12});
  assert(sheet.at(0, 0, 0) == 9);
  assert(sheet.at(0, 0, 1) == 10);
  assert(sheet.at(1, 0, 0) == 11);
  assert(sheet.at(1, 0, 1) == 12);
  assert(sheet.at(0, 1, 0) == 1);
  assert(sheet.at(0, 1, 1) == 2);
  assert(sheet.at(1, 1, 0) == 3);
  assert(sheet.at(1, 1, 1) == 4);
  assert(sheet.at(0, 2, 0) == 5);
  assert(sheet.at(0, 2, 1) == 6);
  assert(sheet.at(1, 2, 0) == 7);
  assert(sheet.at(1, 2, 1) == 8);

  return 0;
}
