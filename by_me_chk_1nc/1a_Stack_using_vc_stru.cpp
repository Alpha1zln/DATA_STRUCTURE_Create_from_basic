#include<bits/stdc++.h>
using namespace std;
//typedef endl "\n";
typedef long long ll;

// stack using array

// top = -1 means stack is empty,   // maxSize=4 
// push, pop, top, isEmpty, isFull

vector<int> stackVec;
const int maxSize = 4;  int top = -1;

bool isEmpty() {
    if (top == -1) {
        cout << "Stack is Empty\n";
        return true;
    } else {
        cout << "Stack is not Empty\n";
    }
    return false;
}   



bool  isFull() {
    if (top == maxSize - 1) {
        cout << "Stack is Full\n";
        return true;
    } else {
        cout << "Stack is not Full\n";
    }
    return false;
}


void push(int val) {
    if (isFull()) {
        return;
    }
    if(top==-1) {
        stackVec.clear();
        stackVec.resize(maxSize);
    }
    top++;
    stackVec[top] = val;
    cout << "Pushed " << val << " to stack\n";
    
}


void pop() {
    if (isEmpty()) {
        return;
    }
    cout << "Popped " << stackVec[top] << " from stack\n";
    top--;
}

void display() {
    if (isEmpty()) {
        return;
    }
    cout << "Stack elements: " << endl;
    for (int i = top; i >= 0; i--) {
        cout << stackVec[i] << endl;
    }
    cout << endl;
}

void topElement() {
    if (isEmpty()) {
        return;
    }
    else 
        cout << "Top element is: " << stackVec[top] << endl;
}



int main() {
    int choice, value;
    while (true) {
        cout << "1. Push\t\t 2. Pop\t\t 3. Display\t" << endl; 
        cout << "4. Top Element\t 5. Check Empty\t 6. Check Full\t 7. Exit \n";
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                topElement();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}