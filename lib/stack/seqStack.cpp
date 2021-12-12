#include "SeqStack.h"

template <class T>
SeqStack<T>::SeqStack(int sz) : top(-1), maxSize(sz)
{
  elements = new T[maxSize];
  assert(elements != NULL);
};

template <class T>
void SeqStack<T>::overflowProcess()
{
  T *newArray = new T[maxSize + stackIncreament];
  if (newArray == NULL)
  {
    cerr << "存储器分配失败！" << endl;
    exit(1);
  }
  for (int i = 0; i <= top; i++)
  {
    newArray[i] = elements[i];
  }

  maxSize += stackIncreament;
  delete[] elements;
  elements = newArray;
}

template <class T>
void SeqStack<T>::push(const T &x)
{
  if (isFull() == true)
    overflowProcess();

  elements[++top] = x;
};

template <class T>
bool SeqStack<T>::pop(T &x)
{
  if (isEmpty() == true)
    return false;
  x = elements[top--];
  return true;
};

template <class T>
bool SeqStack<T>::peak(T &x)
{
  if (isEmpty() == true)
    return false;

  x = elements[top];
  return true;
};

template <class T>
ostream &operator<<(ostream &os, SeqStack<T> &s)
{
  os << "top =" << s.top << endl;
  for (int i = 0; i <= s.top; i++)
    os << i << ":" << s.elements[i] << endl;
  return os;
};