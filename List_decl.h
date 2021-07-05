template <class t> class Node {
public:
  t data;
  Node *pre, *next;
};

template <class t> class List {
private:
  Node<t> *_begin, *_end;
  int _size;

public:
  List();
  void add(t elem);
  bool insert(t obj, t elem);
  Node<t> *search(t elem);
  bool del(t elem);
  t &operator[](int index);
  int size();
  void clear();
  bool empty();
};