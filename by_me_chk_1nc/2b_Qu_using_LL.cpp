#include<bits/stdc++.h>
using namespace std;    
//typedef endl "\n";
typedef long long ll;           
typedef vector<int> vi;
typedef pair<int, int> pii;

// Queue creation using Linked List and class
// front = -1, rear = -1 means qu is empty,   // maxSize=4
// curr_size, isEmpty, isFull, enqueue, dequeue, display, size, getFront, getRear

class LLNode {
    public:
        int data;
        LLNode* next;
        // Constructors
        // Default constructor, initializes data to 0 and next to nullptr
        LLNode() : data(0), next(nullptr) {}  // Default constructor
        // Constructor to initialize a node with a value
        LLNode(int val) : data(val), next(nullptr) {}   
        // Constructor to initialize a node with a value and next pointer
        LLNode(int val, LLNode* nextNode) : data(val), next(nextNode) {}
};


class QueueUsingLinkedList {
    private:        
        LLNode* front;  // Pointer to the front of the queue
        LLNode* rear;   // Pointer to the rear of the queue
        int curr_size;  // Current size of the queue

    public:
        QueueUsingLinkedList() : front(nullptr), rear(nullptr), curr_size(0) {}

        bool isEmpty() {
            return (curr_size == 0);
        }

        bool isFull() {
            return false; // Linked list implementation does not have a fixed size, so it is never full
        }

        void isEmptyQueue() {
            cout << (isEmpty() ? "Queue is Empty" : "Queue is Not Empty") << endl;
        }

        void isFullQueue() {
            cout << (isFull() ? "Queue is Full" : "Queue is Not Full") << endl;
        }

        void enqueue(int val) {
            LLNode* newNode = new LLNode(val);
            if (isEmpty()) {
                front = rear = newNode; // Initialize both front and rear if queue is empty
            } else {
                rear->next = newNode; // Link the new node at the end of the queue
                rear = newNode;       // Update rear to point to the new node
            }
            curr_size++;
            cout << "Enqueued " << val << " to queue\n";
        }

        void dequeue() {
            if (isEmpty()) {
                isEmptyQueue(); 
                return;
            }
            cout << "Dequeued " << front->data << " from queue\n";

            LLNode* temp = front;
            front = front->next; // Move front to the next node
            
            delete temp;         // Free memory of the old front node
            curr_size--;
            
            // If the queue becomes empty after dequeuing, reset rear as well
            if (isEmpty()) {
                front = rear = nullptr;
            }
        }

        void display() {
            if (isEmpty()) {
                isEmptyQueue(); // "Queue is Empty\n";
                return;
            }
            cout << "Queue elements: " << endl;
            LLNode* current = front;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        int size() {
            return curr_size;
        }

        void getFront() {
            if (isEmpty()) {
                isEmptyQueue(); 
                return;
            }
            cout << "Front element: " << front->data << endl;
        }

        void getRear() {
            if (isEmpty()) {
                isEmptyQueue(); 
                return;
            }
            cout << "Rear element: " << rear->data << endl;
        }

        void clear() {
            while (!isEmpty()) {
                dequeue();
            }
            front = rear = nullptr; // Reset both pointers
            curr_size = 0;
            cout << "Queue cleared\n";
        }

        void reset() {
            clear(); // Clear the queue
            cout << "Queue reset\n";
        }   
};

class Queue {
    private:
        QueueUsingLinkedList queueObj;

    public:
        void enqueue(int val) {
            queueObj.enqueue(val);
        }

        void dequeue() {
            queueObj.dequeue();
        }

        void display() {
            queueObj.display();
        }

        void isEmpty() {
            queueObj.isEmptyQueue();
        }

        void isFull() {
            queueObj.isFullQueue();
        }

        void size() {
            cout << "Current size of queue: " << queueObj.size() << endl;        
        }   

        void getFront() {
            queueObj.getFront();
        }

        void getRear() {
            queueObj.getRear();
        }
};


class QueueMainClass {
    public:
        static void run() {
            Queue queue;

            int choice, value;

            while (true) {
                cout << "\nQueue Operations using Linked List\n";
                cout << "1. Enqueue\t 2. Dequeue\t 3. Display\t 4. Size" << endl; 
                cout << "5. Check Empty\t 6. Front Elt\t 7. Rear Elt\t 8. Exit \n";

                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter value to enqueue: ";
                        cin >> value;
                        queue.enqueue(value);
                        break;
                    case 2:
                        queue.dequeue();
                        break;
                    case 3:
                        queue.display();
                        break;
                    case 4:
                        queue.size();
                        break;
                    case 5: {
                        queue.isEmpty(); cout << endl;
                        break; }
                    case 6: {
                         //queue.isFull(); cout << endl;
                         queue.getFront(); cout << endl;
                         break; }
                    case 7: {
                        queue.getRear(); cout << endl;
                        break; }
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
    QueueMainClass::run();  // The :: is called the scope resolution operator in C++.
    // Because run() is a static function inside a class — 
    // we don't create an object of the class, so we call it directly using the class name.

    return 0;
}





// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit 
// Enter your choice: 2
// Queue is Empty

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit 
// Enter your choice: 3
// Queue is Empty

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 4
// Current size of queue: 0

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 5
// Queue is Empty


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 6
// Queue is Empty


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 7
// Queue is Empty


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 10
// Enqueued 10 to queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 20
// Invalid choice! Please try again.

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 20
// Enqueued 20 to queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 3
// Enqueued 3 to queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 3
// Queue elements:
// 10 20 3

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 4
// Current size of queue: 3

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 5
// Queue is Not Empty


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 6
// Front element: 10


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 7
// Rear element: 3


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 2
// Dequeued 10 from queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 3
// Queue elements:
// 20 3

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 2
// Dequeued 20 from queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 2
// Dequeued 3 from queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 4
// Current size of queue: 0

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 2
// Queue is Empty

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 3
// Queue is Empty

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 5
// Queue is Empty


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 6
// Queue is Empty


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 7
// Queue is Empty


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 12
// Enqueued 12 to queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 22
// Enqueued 22 to queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 33
// Enqueued 33 to queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 78
// Enqueued 78 to queue

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 3
// Queue elements:
// 12 22 33 78

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 4
// Current size of queue: 4

// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 5
// Queue is Not Empty


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 6
// Front element: 12


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 7
// Rear element: 78


// Queue Operations using Linked List
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Front Elt    7. Rear Elt     8. Exit
// Enter your choice: 8
// Exiting...