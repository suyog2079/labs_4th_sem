#include <iostream>
using namespace std;

class LinearQueue {
private:
    int *queue;
    int front, rear, size;

public:
    LinearQueue(int s) {
        size = s;
        queue = new int[size];
        front = 0;
        rear = -1;
    }

    ~LinearQueue() {
        delete[] queue;
    }

    void enqueue(int val) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        queue[++rear] = val;
        cout << val << " enqueued\n";
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << queue[front++] << " dequeued\n";
    }

    void display() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    LinearQueue q(size);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.display();

    return 0;
}

