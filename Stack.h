#pragma once
#include "Stack_decl.h"

template <class t> void Stack<t>::push(t elem) { _data.add(elem); }
template <class t> t Stack<t>::top() {
  if (empty())
    return 0;
  return _data[_data.size() - 1];
}
template <class t> bool Stack<t>::pop() {
  if (empty())
    return false;
  return _data.del(_data.size() - 1);
}
template <class t> bool Stack<t>::empty() { return _data.empty(); }
template <class t> void Stack<t>::clear() { _data.clear(); }