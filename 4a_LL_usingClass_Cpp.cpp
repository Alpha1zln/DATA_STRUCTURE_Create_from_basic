#include <iostream>
using namespace std;

// Node class
class LinkedNode {
public:
    int data;
    LinkedNode* next;

    LinkedNode(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked list operations
class BuildLinkedList {
public:
    LinkedNode* head;

    BuildLinkedList() {
        head = nullptr;
    }

    // Create list from user input
    void createList() {
        int n, val;
        cout << "Enter number of nodes: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
        }
    }

    // Insert at end
    void insertAtEnd(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        LinkedNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Insert at any position (1-based)
    void insertAtPos(int pos, int val) {
        LinkedNode* newNode = new LinkedNode(val);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        LinkedNode* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
        if (!temp) {
            cout << "Position out of bounds.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at position (1-based)
    void deleteAtPos(int pos) {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        LinkedNode* temp = head;
        if (pos == 1) {
            head = head->next;
            delete temp;
            return;
        }
        LinkedNode* prev = nullptr;
        for (int i = 1; i < pos && temp; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of bounds.\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Length of list
    int length() {
        int count = 0;
        LinkedNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Print list
    void display() {
        LinkedNode* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main class
int main() {
    BuildLinkedList list;

    list.createList();
    list.display();

    list.insertAtPos(2, 99);
    cout << "After insertion at position 2:\n";
    list.display();

    list.deleteAtPos(1);
    cout << "After deletion at position 1:\n";
    list.display();

    cout << "Length of list: " << list.length() << endl;

    return 0;
}


/*
op **************

Enter number of nodes: 4
Enter value: 4
Enter value: 10 20 30 40
Enter value: Enter value: 4 -> 10 -> 20 -> 30 -> NULL
After insertion at position 2:
4 -> 99 -> 10 -> 20 -> 30 -> NULL
After deletion at position 1:
99 -> 10 -> 20 -> 30 -> NULL
Length of list: 4

*/