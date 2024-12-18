#include <iostream>
#include <system_error>

template <typename T> class Queue {
private:
  T *queue;
  int size, front, rear;

public:
  Queue(int _size) : size(_size) {
    queue = new T[size];
    rear = -1;
    front = 0;
  }

  ~Queue() { delete[] queue; }

  void enqueue(T element) {
    if (rear == size - 1) {
      std::cout << "queue full\n";
      return;
    } else {
      queue[++rear] = element;
      std::cout << "added " << element << "\n";
    }
  }

  T deque() {
    if (front > rear || front == -1) {
      std::cout << "queue empty\n";
      return -1;
    } else {
      std::cout << "removed: " << queue[front++] << "\n";
      return -1;
    }
  }
};

int main() {
  Queue q = Queue<int>(3);
  q.enqueue(5);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.deque();
  q.deque();
  q.deque();
  q.deque();
  q.deque();
  return 0;
}
