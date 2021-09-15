#include "linkedList.h"

template <class T>
List<T>::List(List<T> &L)
{
  // 复制构造函数
  T value;
  LinkNode<T> *srcptr = L.getHead();
  LinkNode<T> *destptr = first = new LinkNode<T>;

  while (srcptr->link != NULL)
  {
    value = srcptr->link->data;
    destptr->link = new LinkNode<T>(value);
    destptr = destptr->link;
    srcptr = srcptr->link;
  }

  destptr->link = NULL;
}

template <class T>
void List<T>::makeEmpty()
{
  LinkNode<T> *q;
  while (first->link != NULL)
  {
    q = first->link;
    first->link = q->link;
    delete q;
  }
}

template <class T>
int List<T>::Length() const
{
  int count = 0;
  LinkNode<T> *p = first->link;

  while (p != NULL)
  {
    p = p->link;
    count++;
  }
}