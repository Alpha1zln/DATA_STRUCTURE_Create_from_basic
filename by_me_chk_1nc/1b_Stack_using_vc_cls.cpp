#include<bits/stdc++.h>
using namespace std;

//typedef endl "\n";
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// stack creation using vector and class
// top = -1 means stack is empty,   // maxSize=4
// push, pop, top, isEmpty, isFull, display

class Stack {
    private:    
        vi stackVec;
        const int maxSize = 4; 
        int top = -1;   

    public:
        Stack() {
            stackVec.resize(maxSize);
        }

        bool isEmpty() {
            if (top == -1) {
                return true;
            }
            return false;
        }

        bool isFull() {
            if (top == maxSize - 1) {
                return true;
            }
            return false;
        }
        
        void push(int val) {
            if (isFull()) {
                cout << "Stack is Full\n";
                return;
            }
            top++;
            stackVec[top] = val;
            cout << "Pushed " << val << " to stack\n";
        }   

        void pop() {
            if (isEmpty()) {
                cout << "Stack is Empty\n";
                return;
            }
            cout << "Popped " << stackVec[top] << " from stack\n";
            top--;
            if(top==-1) {
                void clear();
            }
        }   

        void display() {
            if (isEmpty()) {
                cout << "Stack is Empty\n";
                return;
            }
            cout << "Stack elements: " << endl;
            for (int i = top; i >= 0; i--) {
                cout << stackVec[i] << endl;
            }
            cout << endl;
        }

        void getTop() {
            if (isEmpty()) {
                cout << "Stack is Empty\n";
                return; // or throw an exception
            }
            cout << "Top elt of stack : " <<  stackVec[top] << endl;
        }

        void clear() {
            stackVec.clear();
            top = -1;
            cout << "Stack cleared\n";
        }

};

class StackUsingVector {
    //private:
        Stack stackObj;

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

        void topElement() {
            stackObj.getTop();
        }

        bool isEmpty() {
            stackObj.isEmpty();
        }

        bool isFull() {
            return stackObj.isFull();
        }
};

// 🔍 Why use class StackUsingVector when class Stack already exists?
// You're absolutely right to ask — it feels like a wrapper, right?

// Let’s break it down simply:

// ✅ Reason 1: Abstraction / Clean Interface
// The StackUsingVector class is acting like a middleman or facade to the actual Stack.

// You can think of it like this:

// "I don’t want the user to worry about the internal working (top, vector, etc). Just give them push, pop, topElement()."

// Example:

// StackUsingVector myStack;
// myStack.push(10);
// myStack.pop();
// Clean and simple.

// ✅ Reason 2: Future flexibility
// Let’s say tomorrow you want to change the internal data structure from vector to deque, or maybe add logging or custom behavior — you can do it inside Stack, and StackUsingVector won't change much.

// It's like saying:

// “Let me hide the complex kitchen and just give you the waiter. You order food, and it’s served — what’s inside the kitchen can change.”

// ✅ Reason 3: Segregation of responsibilities
// Stack handles how stack works internally.

// StackUsingVector handles how people use it.

// (Think of it like: engine vs dashboard controls)

// 🤔 Do we really need StackUsingVector?
// If your project is small or you're just learning — no, not mandatory at all!

// You can just use Stack directly:


// Stack st;
// st.push(10);
// st.pop();
// But in larger projects or when writing libraries, such wrappers are common.

// TL;DR (Friend’s way):
// 💡 Without Wrapper (Stack)	🍔 With Wrapper (StackUsingVector)
// More direct, less code	Cleaner interface for users
// Less flexible	Easier to update/extend later
// Best for small use	Best when hiding internals

// If you’re just building and learning, use just Stack.
// Once you want to make it “clean and professional”, wrap it with StackUsingVector 😎


class stackMainClass {
    public:
        static void run() {
            StackUsingVector stack;

            int choice, value;

            while (true) {
                cout << "Stack Operations using Vector Class\n";
                cout << "1. Push\t\t 2. Pop\t\t 3. Display\t" << endl;
                cout << "4. Top Element\t 5. Check Empty\t 6. Check Full\t 7. Exit \n";
            
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
                        stack.topElement();
                        break;
                    case 5:
                        cout << (stack.isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << endl;
                        break;
                    case 6:
                        cout << (stack.isFull() ? "Stack is Full" : "Stack is Not Full") << endl;
                        break;
                    case 7:
                        cout << "Exiting...\n";
                        return; // Exit the loop and program
                    default:
                        cout << "Invalid choice! Please try again.\n";
                }
            }

        }
};

int main() {
    stackMainClass :: run();  // The :: is called the scope resolution operator in C++.
    // Because run() is a static function inside a class — 
    // we don't create an object of the class, so we call it directly using the class name.

    return 0;
}

// or ***************** 
// replace int main() and class mainFunc with below code ...  

// int main() {
//     StackUsingVector stack;
//     stack.push(10);
//     stack.push(20);
//     stack.push(30);
//     stack.push(40);
//     stack.display();
//     stack.topElement();
//     stack.pop();
//     stack.display();
//     stack.push(50); // This should indicate that the stack is full
//     stack.display();

//     return 0;
// }


// ***********
// 🔍 What is :: in mainFunction::run();?
// The :: is called the scope resolution operator in C++.

// It means:

// "Access the run function defined in the mainFunction class."

// 🤔 Why do we need it?
// Because run() is a static function inside a class — we don't create an object of the class, so we call it directly using the class name.

// That’s why:

// cpp
// Copy
// Edit
// mainFunction::run();
// means: “Run the run() method that belongs to mainFunction class.”

// ✅ When to use :::
// Accessing static members of a class:

// cpp
// Copy
// Edit
// ClassName::staticFunction();
// Referring to global variables/functions when there's a name conflict

// Accessing enum or nested class types

// 🚫 When not needed:
// If run() wasn’t static, you’d need to do:

// cpp
// Copy
// Edit
// mainFunction obj;
// obj.run(); // object needed
// 🧠 Memory Tip (Friend-style 😄):
// ":: is like saying 'from that class' —
// so mainFunction::run() just says 'run() from mainFunction'."