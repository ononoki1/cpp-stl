#pragma once
#include "Array_decl.h"

template <class t> Array<t>::Array() {
  _len = 0;
  _size = 8;
  _data = new t[_size]{0};
}
template <class t> void Array<t>::_increase() {
  t *newData = new t[_size * 2]{0};
  for (int i = 0; i < _len; i++)
    newData[i] = _data[i];
  delete[] _data;
  _data = newData;
  _size *= 2;
}
template <class t> void Array<t>::add(t elem) {
  if (_len == _size - 1)
    _increase();
  _data[_len] = elem;
  _len++;
}
template <class t> int Array<t>::size() { return _len; }
template <class t> t &Array<t>::operator[](int index) {
  if (index < 0 || index > _len - 1)
    return _data[_len];
  return _data[index];
}
template <class t> void Array<t>::clear() { _len = 0; }
template <class t> bool Array<t>::del(int index) {
  if (index < 0 || index > _len - 1)
    return false;
  for (int i = index; i < _len - 1; i++)
    _data[i] = _data[i + 1];
  _len--;
  return true;
}
template <class t> bool Array<t>::insert(int index, t elem) {
  if (index < 0 || index > _len - 1)
    return false;
  if (_len == _size - 1)
    _increase();
  for (int i = _len; i > index; i--)
    _data[i] = _data[i - 1];
  _data[index] = elem;
  _len++;
  return true;
}
template <class t> int Array<t>::search(t elem) {
  int index;
  for (index = 0; index < _len; index++)
    if (_data[index] == elem)
      break;
  return index;
}
template <class t> bool Array<t>::empty() { return !_len; }
template <class t> t *Array<t>::begin() { return _data; }
template <class t> t *Array<t>::end() { return _data + _len; }
template <class t> void Array<t>::erase() {
  for (int i = _len; i < _size; i++)
    _data[i] = 0;
}