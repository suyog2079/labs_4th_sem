#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int front, rear, size;

public:
    CircularQueue(int s) {
        size = s + 1; // Extra space to distinguish full and empty
        queue = new int[size];
        front = 0;
        rear = 0;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        queue[rear] = val;
        rear = (rear + 1) % size;
        cout << val << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << queue[front] << " dequeued\n";
        front = (front + 1) % size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i != rear; i = (i + 1) % size) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue cq(size);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();

    cq.dequeue();
    cq.display();

    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();

    cq.enqueue(60); // Should show overflow
    cq.dequeue();
    cq.enqueue(70); // Wrap-around case
    cq.display();

    return 0;
}

