/**
 * 队列是另一种限定存储位置的线性表。
 * 特性：先进先出
 */
const int maxSize = 50;

template <class T>
class Queue
{
public:
  Queue();
  ~Queue();
  virtual void enqueue(const T &x) = 0; // 入队
  virtual bool dequeue(T &x) = 0;       // 出队
  virtual bool getFront(T &x) = 0;      // 读取队首元素
  virtual bool isEmpty() const = 0;
  virtual bool isFull() const = 0;
  virtual int getSize() const = 0;
};
