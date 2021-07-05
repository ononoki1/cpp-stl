#include "List.h"

template <class t> class Queue {
private:
  List<t> _data;

public:
  void enter(t elem);
  t leave();
  int len();
  bool empty();
  t front();
  t back();
  void clear();
};