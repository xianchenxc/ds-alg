#include "LinkedQueue.h"

template <class T>
void LinkedQueue<T>::makeEmpty()
{
  LinkNode<T> *p;

  while (front != rear)
  {
    p = front;
    front = front->link;
    delete p;
  }
};

template <class T>
bool LinkedQueue<T>::enqueue(const T &x)
{
  if (front == NULL)
  {
    front = rear = new LinkNode<T>(x);
    if (front == NULL)
    {
      return false;
    }
  }
  else
  {
    rear->link = new LinkNode<T>(x);
    if (rear->link == NULL)
    {
      return false;
    }
    rear = rear->link;
  }

  return true;
};

template <class T>
bool LinkedQueue<T>::dequeue(T &x)
{
  if (isEmpty() == true)
  {
    return false;
  }

  LinkNode<T> *p = front;
  x = front->data;
  front = front->link;
  delete p;

  return true;
};

template <class T>
bool LinkedQueue<T>::getFront(T &x) const
{
  if (isEmpty() == true)
  {
    return false;
  }

  x = front->data;
  return true;
};

template <class T>
int LinkedQueue<T>::getSize() const
{
  LinkNode<T> *p = front;
  int i = 0;
  while (p != NULL)
  {
    p = p->link;
    i++;
  }

  return i;
}

template <class T>
ostream &operator<<(ostream &os, LinkedQueue<T> &Q)
{
  os << "队列中元素个数有" << Q.getSize() << endl;
  LinkNode<T> *p = Q.front;
  int i = 0;

  while (p != NULL)
  {
    os << ++i << ":" << p->data << endl;
    p = p->link;
  }

  return os;
};
