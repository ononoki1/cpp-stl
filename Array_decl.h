template <class t> class Array {
private:
  t *_data;
  int _len, _size;
  void _increase();

public:
  Array();
  void add(t elem);
  int size();
  t &operator[](int index);
  void clear();
  bool del(int index);
  bool insert(int index, t elem);
  int search(t elem);
  bool empty();
  t *begin();
  t *end();
  void erase();
};