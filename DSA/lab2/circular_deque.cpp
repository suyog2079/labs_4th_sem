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
    front = -1;
  }

  ~Queue() { delete[] queue; }

  void enqueue_rear(T element) {
    if ((rear + 1) % size == front) {
      std::cout << "queue full\n";
      return;
    } else {
      if (front == -1)
        front = 0;
      rear = (rear + 1) % size;
      queue[rear] = element;
      std::cout << "added " << element << "\n";
    }
  }

  void enqueue_front(T element) {
    if (front == rear + 1 || (front == 0 && rear == size - 1)) {
      std::cout << "queue full\n";
      return;
    } else {
      if (front == -1) {
        front = 0;
        rear = 0;
      } else {
        front = (front - 1 + size) % size;
      }
      queue[front] = element;
      std::cout << "added " << element << "\n";
    }
  }

  T deque_front() {
    if (front == -1) {
      std::cout << "queue empty\n";
    } else {
      std::cout << "removed: " << queue[front] << "\n";
      if (front == rear) {
        front = -1;
        rear = -1;
      } else {
        front = (front + 1) % size;
      }
    }
    return -1;
  }

  T deque_rear() {
    if (front == -1) {
      std::cout << "queue empty\n";
    } else {
      std::cout << "removed: " << queue[rear] << "\n";
      if (front == rear) {
        front = -1;
        rear = -1;
      } else {
        rear = (rear - 1 + size) % size;
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
