/**
 * 基于数组的存储表示实现的栈称为顺序栈
 *
 */
#include <assert.h>
#include <iostream>
#include "Stack.h"

using namespace std;

const int stackIncreament = 20;

template <class T>
class SeqStack : public Stack<T>
{
public:
  SeqStack(int sz = 50);
  ~SeqStack() { delete[] elements; }
  void push(const T &x);
  bool pop(T &x);
  bool peak(T &x);
  bool isEmpty() const { return (top == -1) ? true : false; };
  bool isFull() const { return (top == maxSize - 1) ? true : false; };
  bool getSize() const { return top + 1; }
  void makeEmpty() { top = -1; }
  friend ostream &operator<<(ostream &os, SeqStack<T> &s) {}

private:
  T *elements;
  int top;                // 栈顶索引
  int maxSize;            // 栈的容量
  void overflowProcess(); // 栈溢出处理
};