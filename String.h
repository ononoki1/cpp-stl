#pragma once
#include "String_decl.h"

String String::operator+(char c) {
  String ret;
  for (char i : _data)
    ret._data.add(i);
  ret._data.add(c);
  return ret;
}
String String::operator+(String s) {
  String ret;
  for (char i : _data)
    ret._data.add(i);
  for (char i : s._data)
    ret._data.add(i);
  return ret;
}
void String::operator+=(char c) { _data.add(c); }
void String::operator+=(String s) {
  for (char i : s._data)
    _data.add(i);
}
int String::len() { return _data.size(); }
void String::clear() {
  _data.clear();
  _data.erase();
}
bool String::empty() { return _data.empty(); }
char *String::begin() { return _data.begin(); }
char &String::operator[](int index) { return _data[index]; }
int String::search(char c) {
  int i;
  for (i = 0; i < len(); i++)
    if (_data[i] == c)
      break;
  return i;
}
bool String::operator==(String s) {
  if (len() != s.len())
    return false;
  for (int i = 0; i < len(); i++)
    if (_data[i] != s._data[i])
      return false;
  return true;
}
String &String::operator=(String s) {
  clear();
  for (char i : s._data)
    _data.add(i);
  return *this;
}
String::String() = default;
String::String(char *c) {
  while (*c) {
    _data.add(*c);
    c++;
  }
}