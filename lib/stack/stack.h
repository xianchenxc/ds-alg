const int maxSize = 50;

template <class T>
class Stack
{
public:
  Stack();
  virtual void push(const T &x) = 0;
  virtual bool pop(T &x) = 0;
  virtual bool peak(T &x) const = 0;
  virtual bool isEmpty() const = 0;
  virtual bool isFull() const = 0;
  virtual int getSize() const = 0;
};
