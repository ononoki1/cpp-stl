#include "Array.h"

class String {
private:
  Array<char> _data;

public:
  String operator+(char c);
  String operator+(String s);
  void operator+=(char c);
  void operator+=(String s);
  int len();
  void clear();
  bool empty();
  char *begin();
  char &operator[](int index);
  int search(char c);
  bool operator==(String s);
  String();
  explicit String(char *c);
  String &operator=(String s);
};