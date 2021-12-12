#include <assert.h>
#include <iostream>
#include "../linkedList.h"
#include "Stack.h"

using namespace std;

template <class T>
class LinkedStack : public Stack<T>
{
public:
  LinkedStack() : top(NULL){};
  ~LinkedStack() { makeEmpty(); };
  void push(const T &x);
  bool pop(T &x);
  bool peak(T &x) const;
  bool isEmpty() const { return (top == NULL) ? true : false; };
  int getSize() const;
  void makeEmpty();
  friend ostream &operator<<(ostream &os, LinkedStack<T> &s);

private:
  LinkNode<T> *top;
}