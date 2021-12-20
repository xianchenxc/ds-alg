#include <iostream>
#include "../linkedList.h"
#include "Queue.h"

using namespace std;

template <class T>
class LinkedQueue : public Queue<T>
{
public:
  LinkedQueue() : rear(NULL), front(NULL) {}
  ~LinkedQueue(makeEmpty());
  bool enqueue(const T &x);
  bool dequeue(T &x);
  bool getFront(T &x) const;
  void makeEmpty();
  bool isEmpty() const { return (front == NULL ? true : false); };
  int getSize() const;
  friend ostream &operator<<(ostream &os, LinkedQueue<T> &Q);

protected:
  LinkNode<T> *front, *rear;
};