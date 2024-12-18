
#include <iostream>
#include <system_error>

template <typename T> class Queue {
private:
  T *queue;
  int size, front, rear;

public:
  Queue(const Queue &) = delete;
  Queue(Queue &&) = delete;
  Queue &operator=(const Queue &) = delete;
  Queue &operator=(Queue &&) = delete;
  Queue(int _size) : size(_size) {
    queue = new T[size];
    rear = -1;
    front = -1;
  }

  ~Queue() { delete[] queue; }

  void enqueue_rear(T element) {
    if (rear == size - 1) {
      std::cout << "queue full\n";
      return;
    } else {
      queue[++rear] = element;
      std::cout << "added at rear" << element << "\n";
      if (rear == 0)
        front = 0;
    }
  }

  void enqueue_front(T element) {
    if (front <= 0) {
      std::cout << "underflow\n";
      return;
    } else {
      queue[--front] = element;
      std::cout << "added at front" << element << "\n";
    }
  }

  T deque_front() {
    if (front == rear && rear == -1) {
      std::cout << "queue empty\n";
    } else {
      std::cout << "removed value from front: " << queue[front++] << "\n";
    }
    return -1;
  }

  T deque_rear() {
    if (rear == -1) {
      std::cout << "queue empty\n";
    } else {
      std::cout << "removed value form rear: " << queue[rear--] << "\n";
      if (front == rear) {
        front = -1;
        rear = -1;
      }
    }
    return -1;
  }
};

int main() {
  Queue q = Queue<int>(3);
	q.enqueue_rear(2);
	q.enqueue_rear(4);
	q.enqueue_rear(9);
	q.deque_rear();
	q.deque_front();
	q.enqueue_front(3);
	q.enqueue_front(5);
	q.enqueue_front(6);

	return 0;
}
