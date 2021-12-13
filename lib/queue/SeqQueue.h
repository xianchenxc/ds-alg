#include <iostream>
#include "Queue.h"

using namespace std;

template <class T>
class SeqQueue : public Queue<T>
{
public:
  SeqQueue(int sz = 10);
  ~SeqQueue() { delete[] elements; };
  bool enqueue(const T &x);
  bool dequeue(const T &x);
  bool getFront(const T &x);
  void makeEmpty() { front = rear = 0; };
  bool isEmpty() const
  {
    return (front == rear) ? true : false;
  };
  bool isFull() const
  {
    return ((rear + 1) % maxSize == front) ? true : false;
  }
  int getSize() const
  {
    return (rear - front + maxSize) % maxSize;
  }
  friend ostream &operator<<(ostream &os, SeqQueue<T> &Q);

protected:
  // 左闭右开 [front, rear)
  int front, rear;
  T *elements;
  int maxSize;
};