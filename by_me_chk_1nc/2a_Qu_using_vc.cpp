#include<bits/stdc++.h>
using namespace std;
//typedef endl "\n";
typedef long long ll;   
typedef vector<int> vi;
typedef pair<int, int> pii;

// Queue creation using vector and class
// front = -1, rear = -1 means qu is empty,   // maxSize=4
// curr_size, isEmpty, isFull, enqueue, dequeue, display

class QueueUsingVector {
    private:    
        vi queueVec;
        const int maxSize = 4; 
        int front = -1, rear = -1;   
        int curr_size = 0;

    public:
        QueueUsingVector() {
            queueVec.resize(maxSize);
        }

        bool isEmpty() {
            //return (front == -1 && rear == -1);
            return (curr_size == 0);
        }

        bool isFull() {
            //return (rear == maxSize - 1);
            return (curr_size == maxSize);
        }
        
        void enqueue(int val) {
            if (isFull()) {
                isFullQueue();
                return;
            }
            if (isEmpty()) {
                front = 0; // Initialize front if queue is empty
            }
            rear = (rear + 1) % maxSize; // Circular increment
            curr_size++;

            queueVec[rear] = val;
            cout << "Enqueued " << val << " to queue\n";
        }   

        void dequeue() {
            if (isEmpty()) {
                isEmptyQueue();
                return;
            }
            cout << "Dequeued " << queueVec[front] << " from queue\n";
            front= (front + 1) % maxSize; // Circular increment
            curr_size--;
            // Reset front and rear if queue becomes empty
            if (curr_size == 0) { 
                front = rear = -1; // Reset both pointers
            }
            // Note: No need to clear the vector here, as it will be reused.    
            // If you want to clear the vector, you can do it here:
            // queueVec.clear();
            // queueVec.resize(maxSize); // Optional: Resize to maxSize if you want to reuse the same vector
            // Note: No need to reset front and rear here, as they will be reset in dequeue
            // if (front == rear) { // Reset the queue when all elements are dequeued   
            //     front = rear = -1;
            // }

            // if (front > rear) { // Reset the queue when all elements are dequeued
            //     front = rear = -1;
            // }
        }   

        void display() {
            if (isEmpty()) {
                isEmptyQueue();
                return;
            }
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << queueVec[i] << " ";
            }
            cout << endl;
        }   

        int size() {
            return curr_size;
        }

        void clear() {
            queueVec.clear();
            front = rear = -1;
            curr_size = 0;
            cout << "Queue cleared\n";
        }
        void getFront() {
            if (isEmpty()) {
                isEmptyQueue();
                return; // or throw an exception
            }
            cout << "Front element of queue: " << queueVec[front] << endl;
        }

        void getRear() {
            if (isEmpty()) {
                isEmptyQueue();
                return; // or throw an exception
            }
            cout << "Rear element of queue: " << queueVec[rear] << endl;
        }

        void getSize() {
            cout << "Current size of queue: " << curr_size << endl;
        }

        void isEmptyQueue() {
            cout << (isEmpty() ? "Queue is Empty" : "Queue is Not Empty") << endl;
        }

        void isFullQueue() {
            cout << (isFull() ? "Queue is Full" : "Queue is Not Full") << endl;
        }

        void reset() {
            front = rear = -1;
            curr_size = 0;
            cout << "Queue reset\n";
        }
};


class Queue {
    
    QueueUsingVector queueObj;

    public : 
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
                cout << "\nQueue Operations using Vector Class\n";
                cout << "1. Enqueue\t 2. Dequeue\t 3. Display\t 4. Size" << endl; 
                cout << "5. Check Empty\t 6. Check Full\t 7. Top Elts\t 8. Exit \n";

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
                         queue.isFull(); cout << endl;
                        break; }
                    case 7: {
                        queue.getFront() ; cout << endl;
                        queue.getRear() ; cout << endl;
                        break;
                        }
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




// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit 
// Enter your choice: 2
// Queue is Empty

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit 
// Enter your choice: 3
// Queue is Empty

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit 
// Enter your choice: 4
// Current size of queue: 0

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 5
// Queue is Empty


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 6
// Queue is Not Full


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 7
// Queue is Empty

// Queue is Empty


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 12
// Enqueued 12 to queue

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 89
// Enqueued 89 to queue

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 3
// Queue elements: 12 89

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 4
// Current size of queue: 2

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 5
// Queue is Not Empty


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 6
// Queue is Not Full


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 7
// Front element of queue: 12

// Rear element of queue: 89


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 12346
// Enqueued 12346 to queue

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 369
// Enqueued 369 to queue

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 1
// Enter value to enqueue: 7823
// Queue is Full

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 3
// Queue elements: 12 89 12346 369

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 4
// Current size of queue: 4

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 5
// Queue is Not Empty


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 6
// Queue is Full


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 7
// Front element of queue: 12

// Rear element of queue: 369


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 3
// Queue elements: 12 89 12346 369

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 2
// Dequeued 12 from queue

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 2
// Dequeued 89 from queue

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 2
// Dequeued 12346 from queue

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 3
// Queue elements: 369

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 2
// Dequeued 369 from queue

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 2
// Queue is Empty

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 2
// Queue is Empty

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 4
// Current size of queue: 0

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 5
// Queue is Empty


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 6
// Queue is Not Full


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 7
// Queue is Empty

// Queue is Empty


// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 3
// Queue is Empty

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 2
// Queue is Empty

// Queue Operations using Vector Class
// 1. Enqueue       2. Dequeue      3. Display      4. Size
// 5. Check Empty   6. Check Full   7. Top Elts     8. Exit
// Enter your choice: 8
// Exiting...