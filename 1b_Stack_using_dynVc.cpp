#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> st;

public:
    void push(int x) {
        st.push_back(x);
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        st.pop_back();
    }

    int peek() {
        if (st.empty()) return -1;
        return st.back();
    }

    bool isEmpty() {
        return st.empty();
    }

    int size() {
        return st.size();
    }

    void display() {
        for (int i = st.size() - 1; i >= 0; i--) {
            cout << st[i] << " ";
        }
        cout << endl;
    }

    void clear() {
        st.clear();
        cout << "Stack cleared\n";
    }   

    void printSize() {
        cout << "Current stack size: " << size() << endl;
    }   

    void printTop() {
        int topElement = peek();
        if (topElement != -1) {
            cout << "Top element: " << topElement << endl;
        } else {
            cout << "Stack is empty\n";
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
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}


