
// HashMap using Linked Lists in C++ ************

// A clean implementation of a simple HashMap using 
// Linked Lists for separate chaining (handling collisions). 

// It includes a user-friendly terminal menu like the vector version:

#include <iostream>
#include <string>
using namespace std;

// Node structure for linked list
struct Node {
    int key;
    string value;
    Node* next;
    Node(int k, string val) : key(k), value(val), next(nullptr) {}
};

// HashMap class using Linked List (separate chaining)
class HashMapLL {
private:
    int bucketCount;
    Node** table;
    int numElements;

    int hashFunction(int key) {
        return key % bucketCount;
    }

public:
    HashMapLL(int buckets = 4) {
        bucketCount = buckets;
        table = new Node*[bucketCount];
        for (int i = 0; i < bucketCount; ++i)
            table[i] = nullptr;
        numElements = 0;
    }

    void insert(int key, string value) {
        int idx = hashFunction(key);
        Node* head = table[idx];

        while (head != nullptr) {
            if (head->key == key) {
                head->value = value;
                cout << "Updated key " << key << " with value " << value << endl;
                return;
            }
            head = head->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = table[idx];
        table[idx] = newNode;
        numElements++;
        cout << "Inserted key " << key << " with value " << value << endl;
    }

    string get(int key) {
        int idx = hashFunction(key);
        Node* head = table[idx];
        while (head != nullptr) {
            if (head->key == key) return head->value;
            head = head->next;
        }
        return "";
    }

    void remove(int key) {
        int idx = hashFunction(key);
        Node* head = table[idx];
        Node* prev = nullptr;

        while (head != nullptr) {
            if (head->key == key) {
                if (prev == nullptr)
                    table[idx] = head->next;
                else
                    prev->next = head->next;

                delete head;
                numElements--;
                cout << "Removed key " << key << endl;
                return;
            }
            prev = head;
            head = head->next;
        }
        cout << "Key " << key << " not found.\n";
    }

    void display() {
        if (numElements == 0) {
            cout << "HashMap is empty.\n";
            return;
        }
        cout << "HashMap Contents:\n";
        for (int i = 0; i < bucketCount; ++i) {
            Node* head = table[i];
            cout << "Bucket " << i << ": ";
            while (head != nullptr) {
                cout << "(" << head->key << ", " << head->value << ") ";
                head = head->next;
            }
            cout << endl;
        }
    }

    int size() {
        return numElements;
    }

    int capacity() {
        return bucketCount;
    }

    bool isEmpty() {
        return numElements == 0;
    }

    void clear() {
        for (int i = 0; i < bucketCount; ++i) {
            Node* head = table[i];
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            table[i] = nullptr;
        }
        numElements = 0;
        cout << "HashMap cleared.\n";
    }

    ~HashMapLL() {
        clear();
        delete[] table;
    }
};

// Main menu interface
int main() {
    HashMapLL hashmap(4); // Create a HashMap with 4 buckets
    int choice, key;
    string value;

    while (true) {
        cout << "\n--- HashMap using Linked List ---\n";
        cout << "1. Insert\t2. Get\t\t3. Remove\t4. Display\t5. Size\n";
        cout << "6. Capacity\t7. isEmpty\t8. Clear\t9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid input! Try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter key (int): ";
                cin >> key;
                cin.ignore();
                cout << "Enter value (string): ";
                getline(cin, value);
                hashmap.insert(key, value);
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                value = hashmap.get(key);
                if (value == "") cout << "Key not found.\n";
                else cout << "Value: " << value << endl;
                break;
            case 3:
                cout << "Enter key to remove: ";
                cin >> key;
                hashmap.remove(key);
                break;
            case 4:
                hashmap.display();
                break;
            case 5:
                cout << "Size: " << hashmap.size() << endl;
                break;
            case 6:
                cout << "Bucket count (capacity): " << hashmap.capacity() << endl;
                break;
            case 7:
                cout << (hashmap.isEmpty() ? "HashMap is empty.\n" : "HashMap is not empty.\n");
                break;
            case 8:
                hashmap.clear();
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}




// Great question! *****************************************

// Node** table;          // ptr to a ptr ... 

// ✅ Meaning:
// This is a pointer to a pointer — 
//in this case, a pointer to an array of pointers to Node objects.

// 💡 In context:
// We are creating a hash table where each index (bucket) stores a 
//linked list of Nodes.

// So:
// table is an array of pointers to Node.
// Node* table[i] → points to the head of a linked list at index i.

// Hence:
// Node** table → allows us to dynamically create an array of linked lists.

// 🧠 Example Visualization
// Let’s say bucketCount = 4:

// table
//  ↓
// +-------+-------+-------+-------+
// |   *   |   *   |  NULL |   *   |   ← array of pointers (size 4)
// +-------+-------+-------+-------+
//    ↓       ↓               ↓
//  Node     Node           Node
//   ↓         ↓               ↓
//  NULL     Node           NULL
//            ↓
//          NULL

// Each table[i] is a Node*, and table is a Node** — a pointer to the array of Node*.

// 🛠 Allocation in Code:
// table = new Node*[bucketCount];
// Allocates memory for an array of Node* of size bucketCount.









// ✅ Key Differences from Vector Version:

// Feature	             Vector of Vectors	        Linked List Chaining
// Collision	          Stored in sub-vectors	    Stored in linked list
// Dynamic resizing	          Easy	                Manual memory mgmt
// Memory usage	          More compact	            More flexible (per node)
// Deletion	              Vector erase        	      Node pointer manipulation




// **********

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 4
// HashMap is empty.

// --- HashMap using Linked List ---
// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 5
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 5
// Size: 0

// --- HashMap using Linked List ---
// Size: 0

// --- HashMap using Linked List ---
// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 6
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 6
// Bucket count (capacity): 10
// Bucket count (capacity): 10


// --- HashMap using Linked List ---
// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 9
// Enter your choice: 9
// Exiting...
// HashMap cleared.
// PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\dsa\by me> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\dsa\by me\" ; if ($?) { g++ 3c_Map_using_LL.cpp -o 3c_Map_using_LL } ; if ($?) { .\3c_Map_using_LL }

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 1
// Enter key (int): 12
// Enter value (string): 564
// Inserted key 12 with value 564

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 1
// Enter key (int): 565
// Enter value (string): 1313
// Inserted key 565 with value 1313

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 1
// Enter key (int): 56
// Enter value (string): 65464645
// Inserted key 56 with value 65464645

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 4
// HashMap Contents:
// Bucket 0:
// Bucket 1:
// Bucket 2: (12, 564)
// Bucket 3:
// Bucket 4:
// Bucket 5: (565, 1313)
// Bucket 6: (56, 65464645)
// Bucket 7:
// Bucket 8:
// Bucket 9:

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 5
// Size: 3

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 6
// Bucket count (capacity): 10

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 7
// HashMap is not empty.

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 8
// HashMap cleared.

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 4
// HashMap is empty.

// --- HashMap using Linked List ---
// 1. Insert       2. Get          3. Remove       4. Display      5. Size
// 6. Capacity     7. isEmpty      8. Clear        9. Exit
// Enter your choice: 9
// Exiting...
// HashMap cleared.