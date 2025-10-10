#include <iostream>
using namespace std;
#define MAX 100

class Queue {
    int front, rear;
    int arr[MAX];

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();  // 10 20 30

    cout << "Front: " << q.peek() << endl;

    q.dequeue();
    q.display();  // 20 30

    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();  // Underflow

    return 0;
}
