#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define endl '\n'


class Stack {
    int top= -1;
    int arr[MAX];

    public:

    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top <= -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top <= -1) {
            cout << "Stack is empty\n";
            return -1; // Indicating stack is empty
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: " << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void clear() {
        top = -1; // Resetting the stack
        cout << "Stack cleared\n";
    }

    int size() {
        return top + 1; // Returns the number of elements in the stack
    }

    void printSize() {
        cout << "Current stack size: " << size() << endl;
    }


    void printTop() {
        int topElement = peek();
        if (topElement != -1) {
            cout << "Top element: " << topElement << endl;
        }
    }


};

// public class Mainfunction {

int main() {
    Stack s;
    int choice, value;
    cout << "Welcome to Stack Operations using Array\n";
    cout << "Choose an operation to perform:\n";
    do {
        cout << "1. Push\t\t 2. Pop\t\t 3. Peek\n";
        cout << "4. Display\t 5. Clear Stack\t 6. Check if Empty\n";
        cout << "7. Print Size\t 8. Print Top Element\t 9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                {
                int topElement = s.peek();
                if (topElement != -1)
                    cout << "Top element: " << topElement << endl;
                break;
                }
            case 4:
                s.display();
                break;
            case 5:
                s.clear();
                break;
            case 6:
                cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 7:
                s.printSize();
                break;
            case 8:
                s.printTop();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 9);

    return 0;
}

