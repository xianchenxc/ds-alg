#include <iostream>
#include "./linearList.h"

using namespace std;

const int defaultSize = 100;

template <class T>
class SeqList : public LinearList<T>
{
protected:
  T *data;                  // 存放数组
  int maxSize;              // 最大可容纳表项的项数
  int last;                 // 当前已存表项的最后一项
  void reSize(int newSize); // 改变 data 数组空间大小

public:
  SeqList(int sz = defaultSize);          // 构造函数
  SeqList(SeqList<T> &L);                 // 复制构造函数
  ~SeqList() { delete[] data; }           // 析构函数
  int Size() const { return maxSize; }    // 计算表最大可容纳表项个数
  int Length() const { return last + 1; } // 计算表长度
  int Search(T &x) const;
  int Locate(int i) const;
  bool getData(int i, T &x) const
  {
    if (i > 0 && i <= last + 1)
    {
      x = data[i - 1];
      return true;
    }
    else
      return false;
  }
  void setData(int i, T &x)
  {
    if (i > 0 && i <= last + 1)
      data[i - 1] = x;
  }
  bool Insert(int i, T &x);
  bool Remove(int i, T &x);
  bool isEmpty() { return (last == -1) ? true : false; }
  bool isFull() { return (last == maxSize - 1) ? true : false; }
  void input(){};
  void output(){};
  SeqList<T> operator=(SeqList<T> &L);
};

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

template <class T>
void SeqList<T>::reSize(int newSize)
{
  if (newSize < 0)
  {
    cerr << "invalid size" << endl;
    return;
  }

  if (newSize != maxSize)
  {
    T *newArray = new T[newSize];
    if (newArray == NULL)
    {
      cerr << "alloc failed" << endl;
      exit(1);
    }

    int n = last + 1;
    T *srcptr = data;
    T *destptr = newArray;
    while (n--)
      *destptr++ = *srcptr++;
    delete[] data;
    data = newArray;
    maxSize = newSize;
  }
}

template <class T>
int SeqList<T>::Search(T &x) const
{
  for (int i = 0; i < last; i++)
    if (data[i] == x)
      return i + 1;

  return 0;
}

template <class T>
int SeqList<T>::Locate(int i) const
{
  if (i >= 1 && i <= last + 1)
    return i;
  else
    return 0;
}

template <class T>
bool SeqList<T>::Insert(int i, T &x)
{
  if (last == maxSize - 1)
    return false;
  if (i < 0 || i > last + 1)
    return false;
  for (int j = last; j >= i; j--)
    data[j + 1] = data[j];
  data[i] = x;
  last++;

  return true;
}

template <class T>
bool SeqList<T>::Remove(int i, T &x)
{
  if (last == -1)
    return false;
  if (i < 1 || i > last + 1)
    return false;
  x = data[i - 1];
  for (int j = i; j <= last; j++)
    data[j - 1] = data[j];
  last--;
  return true;
}

template <class T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L)
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
