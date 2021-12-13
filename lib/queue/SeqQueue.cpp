#include "SeqQueue.h"

template <class T>
SeqQueue<T>::SeqQueue(int sz) : front(0), rear(0), maxSize(sz)
{
  elements = new T[maxSize];
  assert(elements != NULL);
};

template <class T>
bool SeqQueue<T>::enqueue(const T &x)
{
  if (isFull() == true)
  {
    return false;
  }

  elements[rear] = x;
  rear = (rear + 1) % maxSize;
  return true;
};

template <class T>
bool SeqQueue<T>::dequeue(const T &x)
{
  if (isEmpty() == true)
  {
    return false;
  }

  x = elements[front];
  front = (front + 1) % maxSize;
  return true;
};

template <class T>
bool SeqQueue<T>::getFront(const T &x)
{
  if (isEmpty() == true)
  {
    return false;
  }

  x = elements[front];
  return true;
};

template <class T>
ostream &operator<<(ostream &os, SeqQueue<T> &Q)
{
  os << "front =" << Q.front << ". rear =" << Q.rear << endl;
  for (int i = front; i != rear; i = (i + 1) % maxSize)
  {
    os << i << ":" << Q.elements[i] << endl;
  }

  return os;
};
