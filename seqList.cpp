#include "seqList.h"

template <class T>
SeqList<T>::SeqList(int sz)
{
  if (sz > 0)
  {
    maxSize = sz;
    last = -1;
    data = new T[maxSize];
    if (data == NULL)
    {
      cerr << "存储器分配错误！" << endl;
      exit(1);
    }
  }
}

template <class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
  maxSize = L.size();
  last = L.length() - 1;
  T value;
  data = new T[maxSize];

  if (data == NULL)
  {
    cerr << "存储器分配错误！" << endl;
    exit(1);
  }

  for (int i = 1; i <= last + 1; i++)
  {
    L.getData(i, value);
    data[i - 1] = value;
  }
}