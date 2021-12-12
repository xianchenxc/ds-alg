#include "LinkedStack.h"

template <class T>
void LinkedStack<T>::makeEmpty()
{
  LinkNode<T> *p;

  while (top != NULL)
  {
    p = top;
    top = top->link;
    delete p;
  }
};

template <class T>
void LinkedStack<T>::push(const T &x)
{
  top = new LinkNode<T>(x, top);
  assert(top != NULL);
};

template <class T>
bool LinkedStack<T>::pop(T &x)
{
  if (isEmpty() == true)
  {
    return false;
  }
  LinkNode<T> *p = top;
  top = top->link;
  x = p->data;
  delete p;

  return true;
}

template <class T>
bool LinkedStack<T>::peak(T &x) const
{
  if (isEmpty() == = true)
  {
    return false;
  }

  x = top->data;
  return true;
}

template <class T>
int LinkedStack<T>::getSize() const
{
  LinkNode<T> *p = top;
  int i = 0;

  while (p != NULL)
  {
    p = p->link;
    i++;
  }

  return i;
}

template <class T>
ostream &operator<<(ostream &os, LinkedStack<T> &s)
{
  os << "栈中元素个数" << s.getSize() << endl;
  LinkNode<T> *p = top;
  int i = 0;
  while (p != NULL)
  {
    os << ++i << ":" << p->data << endl;
    p = p->link;
  }

  return os;
}