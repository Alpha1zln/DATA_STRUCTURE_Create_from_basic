#include<bits/stdc++.h>
using namespace std;

class LinkedListNode {
public:
    int data;
    LinkedListNode* next;

    // Default constructor
    LinkedListNode() : data(0), next(nullptr) {}
    // Constructor to initialize a node with a value
    LinkedListNode(int val) : data(val), next(NULL) {}
    // Constructor to initialize a node with a value and next pointer
    LinkedListNode(int val, LinkedListNode* nextNode) : data(val), next(nextNode) {}
};

class StackUsingLinkedList {
    private:
        LinkedListNode* topNode;  // tail
        LinkedListNode* headNode;
            
    public:
        StackUsingLinkedList() : topNode(nullptr), headNode(nullptr) {}

        bool isEmpty() {
            return topNode == NULL;
        }

        void push(int val) {
            LinkedListNode* newNode = new LinkedListNode(val);

            if (isEmpty()) {
                headNode = newNode; // Initialize headNode if stack is empty
                //topNode = newNode;
            } else {
                newNode->next = topNode;
            }
            topNode = newNode;
            cout << "Pushed " << val << " to stack\n";
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack is Empty\n";
                return;
            }
            cout << "Popped " << topNode->data << " from stack\n";
            LinkedListNode* temp = topNode;
            topNode = topNode->next;
            delete temp;

            // If the stack becomes empty after popping, reset headNode
            // This is optional, but helps in memory management
            if( topNode == NULL)  {
                clear(); // Reset head pointer
            }
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is Empty\n";
                return;
            }
            cout << "Stack elements: \n" ;
            LinkedListNode* current = topNode;
            while (current != NULL) {
                cout << current->data << endl;
                current = current->next;
            }
            cout << endl;
        }

        void getTop() {
            if (isEmpty()) {
                cout << "Stack is Empty\n";
                return;
            }
            cout << "Top element of stack: " << topNode->data << endl;
        }

        void clear() {
            while (!isEmpty()) {
                pop();
            }
            headNode = NULL;  // Reset head pointer
            cout << "Stack cleared\n";
        }

        int size() {
            int count = 0;
            LinkedListNode* current = topNode;
            while (current != NULL) {
                count++;
                current = current->next;
            }
            return count;
        }

        bool isFull() {
            // Linked list implementation does not have a fixed size, so it is never full
            return false;
        }
        
};


class Stack {
    private: 
        StackUsingLinkedList stackObj;

    public:
        void push(int val) {
            stackObj.push(val);
        }

        void pop() {
            stackObj.pop();
        }

        void display() {
            stackObj.display();
        }

        void getTop() {
            stackObj.getTop();
        }

        bool isEmpty() {
            return stackObj.isEmpty();
        }

        bool isFull() {
            return stackObj.isFull();
        }

        void size() {
            cout << "Current size of stack: " << stackObj.size() << endl;
        }
};


class StackMainClass {
    public:
        static void run() {
            Stack stack;

            int choice, value;

            while (true) {
                cout << "\nStack Operations using Linked List\n";
                cout << "1. Push\t\t 2. Pop\t\t 3. Display\t 4. Size" << endl; 
                cout << "5. Top Element\t 6. Check Empty\t 7. Check Full\t 8. Exit \n";

                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter value to push: ";
                        cin >> value;
                        stack.push(value);
                        break;
                    case 2:
                        stack.pop();
                        break;
                    case 3:
                        stack.display();
                        break;
                    case 4:
                        stack.size(); break;   
                    case 5:
                        stack.getTop();
                        break;
                    case 6:
                        cout << (stack.isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << endl;
                        break;
                    case 7:
                        cout << (stack.isFull() ? "Stack is Full" : "Stack is Not Full") << endl;
                        break;
                    case 8:
                        cout << "Exiting...\n";
                        return; // Exit the loop and program
                    default:
                        cout << "Invalid choice! Please try again.\n";
                }
            }
        }
};

int main() {
    StackMainClass::run();  // The :: is called the scope resolution operator in C++.
    // Because run() is a static function inside a class — 
    // we don't create an object of the class, so we call it directly using the class name.

    return 0;
}


// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit 
// Enter your choice: 1
// Enter value to push: 12
// Pushed 12 to stack

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit 
// Enter your choice: 1
// Enter value to push: 56
// Pushed 56 to stack

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 3
// Stack elements:
// 56
// 12


// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 4
// Current size of stack: 2

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 5
// Top element of stack: 56

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 6
// Stack is Not Empty

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 7
// Stack is Not Full

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 2
// Popped 56 from stack

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 3
// Stack elements:
// 12


// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 4
// Current size of stack: 1

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 1
// Enter value to push: 98
// Pushed 98 to stack

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 1
// Enter value to push: 759
// Pushed 759 to stack

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 1
// Enter value to push: 369
// Pushed 369 to stack

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 1
// Enter value to push: 459
// Pushed 459 to stack

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 7
// Stack is Not Full

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 4
// Current size of stack: 5

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 3
// Stack elements:
// 459
// 369
// 759
// 98
// 12


// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 6
// Stack is Not Empty

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 4
// Current size of stack: 5

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 5
// Top element of stack: 459

// Stack Operations using Linked List
// 1. Push          2. Pop          3. Display      4. Size
// 5. Top Element   6. Check Empty  7. Check Full   8. Exit
// Enter your choice: 8
// Exiting...