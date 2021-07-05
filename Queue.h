#pragma once
#include "Queue_decl.h"

template <class t> void Queue<t>::enter(t elem) { _data.add(elem); }
template <class t> t Queue<t>::leave() {
  if (empty())
    return 0;
  t ret = _data[0];
  _data.del(ret);
  return ret;
}
template <class t> int Queue<t>::len() { return _data.size(); }
template <class t> bool Queue<t>::empty() { return _data.empty(); }
template <class t> t Queue<t>::front() {
  if (empty())
    return 0;
  return _data[0];
}
template <class t> t Queue<t>::back() {
  if (empty())
    return 0;
  return _data[_data.size() - 1];
}
template <class t> void Queue<t>::clear() { _data.clear(); }