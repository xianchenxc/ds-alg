#include <iostream>
#include "linearList.h"

using namespace std;

const int defaultSize = 100;

template <class T>
class SeqList : public LinearList<T>
{
protected:
  T *data;                  // 存放数组
  int maxSize;              // 最大可容纳表项的项数
  int last;                 // 当前已存表项的最后一项
  void resize(int newSize); // 改变 data 数组空间大小

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
  void input();
  void output();
  SeqList<T> operator=(SeqList<T> &L);
};