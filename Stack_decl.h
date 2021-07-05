#include "Array.h"

template <class t> class Stack {
private:
  Array<t> _data;

public:
  void push(t elem);
  t top();
  bool pop();
  bool empty();
  void clear();
};