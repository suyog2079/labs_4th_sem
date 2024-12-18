#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    // Add at the beginning
    void addFront(int value) {
        if (size == capacity) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) { // If the deque is empty
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity; // Circular move
        }
        arr[front] = value;
        size++;
    }

    // Add at the end
    void addEnd(int value) {
        if (size == capacity) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) { // If the deque is empty
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity; // Circular move
        }
        arr[rear] = value;
        size++;
    }

    // Delete from beginning
    void deleteFront() {
        if (size == 0) {
            cout << "Deque is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity; // Circular move
        size--;
    }

    // Delete from end
    void deleteEnd() {
        if (size == 0) {
            cout << "Deque is empty!" << endl;
            return;
        }
        rear = (rear - 1 + capacity) % capacity; // Circular move
        size--;
    }

    // Print the deque
    void printDeque() {
        if (size == 0) {
            cout << "Deque is empty!" << endl;
            return;
        }
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque dq(5); // Create a deque with capacity 5

    // a. Add at the beginning
    dq.addFront(10);
    cout << "After adding at beginning: ";
    dq.printDeque();

    // b. Add at the end
    dq.addEnd(20);
    cout << "After adding at end: ";
    dq.printDeque();

    // c. Delete from beginning
    dq.deleteFront();
    cout << "After deleting from beginning: ";
    dq.printDeque();

    // d. Delete from end
    dq.deleteEnd();
    cout << "After deleting from end: ";
    dq.printDeque();

    return 0;
}

