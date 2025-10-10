#include <iostream>
using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node(int val) : data(val), next(nullptr) {}
// };

// In struct, members are public by default.

// In class, members are private by default.



class Node {
    // In class, members are private by default. ,,, vip
    int data;
    Node* next;

public:
    Node(int val) : data(val), next(nullptr) {}

    // Make Stack a friend so it can access private members
    friend class Stack;
};

class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (!top) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (!top) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* curr = top;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top) {
            pop();
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); // Should print 30 20 10

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.display(); // Should print 20 10

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    s.pop();
    s.pop();
    s.pop(); // Should print "Stack Underflow"

    return 0;
}
