#pragma once
#include "List_decl.h"

template <class t> List<t>::List() {
  _begin = new Node<t>;
  _begin->data = 0;
  _begin->pre = 0;
  _begin->next = _end;
  _end = new Node<t>;
  _end->data = 0;
  _end->pre = _begin;
  _end->next = 0;
  _size = 0;
}
template <class t> void List<t>::add(t elem) {
  auto *p = new Node<t>;
  p->data = elem;
  p->pre = _end->pre;
  p->next = _end;
  _end->pre->next = p;
  _end->pre = p;
  _size++;
}
template <class t> bool List<t>::insert(t obj, t elem) {
  Node<t> *p = search(obj);
  if (p == _end)
    return false;
  auto *q = new Node<t>;
  q->data = elem;
  q->pre = p->pre;
  q->next = p;
  p->pre->next = q;
  p->pre = q;
  _size++;
  return true;
}
template <class t> Node<t> *List<t>::search(t elem) {
  Node<t> *p = _begin->next;
  while (p->data != elem) {
    if (p == _end)
      break;
    p = p->next;
  }
  return p;
}
template <class t> bool List<t>::del(t elem) {
  Node<t> *p = search(elem);
  if (p == _end)
    return false;
  p->pre->next = p->next;
  p->next->pre = p->pre;
  delete p;
  _size--;
  return true;
}
template <class t> t &List<t>::operator[](int index) {
  if (index < 0 || index > _size - 1)
    return _end->data;
  Node<t> *p;
  if (index < _size / 2) {
    p = _begin->next;
    for (int i = 0; i < index; i++)
      p = p->next;
  } else {
    p = _end->pre;
    for (int i = _size - 1; i > index; i--)
      p = p->pre;
  }
  return p->data;
}
template <class t> int List<t>::size() { return _size; }
template <class t> void List<t>::clear() {
  Node<t> *p = _begin->next;
  while (p != _end) {
    _begin->next = p->next;
    delete p;
    p = _begin->next;
  }
  _end->pre = _begin;
  _size = 0;
}
template <class t> bool List<t>::empty() { return !_size; }