// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// class HashMap {
// private:
//     vector<vector<pair<int, string>>> mapVvp;
//     int capacity;
//     int current_size;

//     int hash(int key) {
//         return key % capacity;
//     }

// public:
//     HashMap(int cap) : capacity(cap), current_size(0) {
//         mapVvp.resize(capacity);
//     }

//     void insert(int key, const string& value) {
//         int index = hash(key);
//         for (auto& p : mapVvp[index]) {
//             if (p.first == key) {
//                 p.second = value;
//                 cout << "🔁 Updated key " << key << " with value \"" << value << "\"\n";
//                 return;
//             }
//         }
//         mapVvp[index].emplace_back(key, value);
//         current_size++;
//         cout << "✅ Inserted key " << key << " with value \"" << value << "\"\n";
//     }

//     void get(int key) {
//         int index = hash(key);
//         for (auto& p : mapVvp[index]) {
//             if (p.first == key) {
//                 cout << "🔍 Found: " << key << " → " << p.second << "\n";
//                 return;
//             }
//         }
//         cout << "❌ Key " << key << " not found\n";
//     }

//     void remove(int key) {
//         int index = hash(key);
//         auto& bucket = mapVvp[index];
//         for (auto it = bucket.begin(); it != bucket.end(); ++it) {
//             if (it->first == key) {
//                 bucket.erase(it);
//                 current_size--;
//                 cout << "🗑️  Removed key " << key << "\n";
//                 return;
//             }
//         }
//         cout << "❌ Key " << key << " not found\n";
//     }

//     void display() {
//         if (current_size == 0) {
//             cout << "⚠️  HashMap is empty\n";
//             return;
//         }
//         cout << "📦 HashMap contents:\n";
//         for (int i = 0; i < capacity; ++i) {
//             for (auto& p : mapVvp[i]) {
//                 cout << "  [" << i << "] " << p.first << " → " << p.second << "\n";
//             }
//         }
//     }

//     void status() {
//         cout << "📊 Size: " << current_size << " / " << capacity << "\n";
//         cout << (isFull() ? "🚫 HashMap is full\n" : "🟢 HashMap has space\n");
//     }

//     bool isFull() {
//         return current_size == capacity;
//     }

//     bool isEmpty() {
//         return current_size == 0;
//     }
// };

// // Terminal UI
// void printMenu() {
//     cout << "\n====== HASHMAP MENU ======\n";
//     cout << "1. Insert\t";
//     cout << "2. Get Value\t";
//     cout << "3. Remove Key\t \n";
//     cout << "4. Display All\t";
//     cout << "5. Status\t";
//     cout << "6. Exit\t \n";
//     cout << "=============================\n";
//     cout << "Choose an option (1-6): ";
// }

// int main() {
//     int cap;
//     cout << "🔧 Enter capacity of HashMap: ";
//     cin >> cap;

//     HashMap hm(cap);

//     while (true) {
//         printMenu();
//         int choice;
//         cin >> choice;

//         if (choice == 6) {
//             cout << "👋 Exiting... Goodbye!\n";
//             break;
//         }

//         int key;
//         string val;

//         switch (choice) {
//             case 1:
//                 // cout << "➕ Enter key (int) and value (string): ";
//                 // cin >> key >> val;
//                 cout << "Enter key (int): ";
//                 //cin >> key; // if string is entered then error .. so do input validation
//                 while (!(cin >> key)) {
//                     cout << "❌ Invalid input! Please enter a valid integer: ";
//                     cin.clear();
//                     cin.ignore(1000, '\n');
//             }
//                 cin.ignore(); // Clear the newline character left in the input buffer

//                 cout << "Enter value (string with spaces allowed): ";
//                 getline(cin, val);
//                 hm.insert(key, val);
//                 break;
//             case 2:
//                 cout << "🔍 Enter key to search: ";
//                 cin >> key;
//                 hm.get(key);
//                 break;
//             case 3:
//                 cout << "🗑️  Enter key to remove: ";
//                 cin >> key;
//                 hm.remove(key);
//                 break;
//             case 4:
//                 hm.display();
//                 break;
//             case 5:
//                 hm.status();
//                 break;
//             default:
//                 cout << "❌ Invalid choice! Please enter 1–6.\n";
//         }
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <utility> // for std::pair
#include <string>
using namespace std;

// Hashmap creation using vector of vector of pairs and class
class HashMap {
private:
    vector<vector<pair<int, string>>> mapVvp; // Buckets to store key-value pairs
    int capacity;       // Total number of buckets
    int current_size;   // Total number of key-value pairs stored

    // Hash function to calculate index
    int hash(int key) {
        return (key % capacity); // Basic hash function
    }

public:
    // Constructor to initialize the hashmap with given bucket count
    HashMap(int cap) : capacity(cap) {
        mapVvp.resize(capacity); // Resize the vector to the specified capacity
        current_size = 0;
    }

    // Insert or update key-value pair
    void insert(int key, const string& value) {
        int index = hash(key);

        for (auto& pair : mapVvp[index]) {
            if (pair.first == key) {
                pair.second = value;
                cout << "Updated key " << key << " with value '" << value << "'\n";
                return;
            }
        }

        mapVvp[index].emplace_back(key, value);
        current_size++;
        cout << "Inserted key " << key << " with value '" << value << "'\n";
    }

    // Get value for a given key
    string getValueByKey(int key) {
        int index = hash(key);

        for (const auto& pair : mapVvp[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "";
    }

    // Display all key-value pairs
    void display() {
        if (current_size == 0) {
            cout << "Hashmap is empty\n";
            return;
        }

        cout << "Hashmap contents:\n";
        for (const auto& bucket : mapVvp) {
            for (const auto& pair : bucket) {
                cout << pair.first << ": " << pair.second << endl;
            }
        }
    }

    // Remove a key-value pair
    void remove(int key) {
        int index = hash(key);
        auto& bucket = mapVvp[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                current_size--;
                cout << "Removed key " << key << endl;
                return;
            }
        }
        cout << "Key " << key << " not found\n";
    }

    int size() {
        return current_size;
    }

    void clear() {
        for (auto& bucket : mapVvp) {
            bucket.clear();
        }
        current_size = 0;
        cout << "Hashmap cleared\n";
    }

    void reset() {
        clear();
        cout << "Hashmap reset\n";
    }

    bool isEmpty() {
        return current_size == 0;
    }

    bool isFull() {
        return current_size == capacity; // Full in terms of total key-value pairs
    }

    int getCurrentSize() {
        return current_size;
    }

    int getCapacity() {
        return capacity;
    }

    void getIndexVectors() {
        cout << "Hashmap Buckets and Their Contents:\n";
        for (int i = 0; i < mapVvp.size(); ++i) {
            cout << "Bucket " << i << ": ";
            if (mapVvp[i].empty()) {
                cout << "Empty\n";
                continue;
            }
            for (const auto& pair : mapVvp[i]) {
                cout << "{" << pair.first << ", " << pair.second << "} ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap hm(4);
    int choice, key;
    string value;

    while (true) {
        cout << "\n--- HashMap Menu ---\n";
        cout << "1. Insert\t2. Get Value\t3. Display\t4. isEmpty\t5. Show Buckets\n";
        cout << "6. isFull\t7. Remove\t8. Current Size\t9. Capacity\t10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key (int): ";
                while (!(cin >> key)) {
                    cout << "Invalid input. Enter a valid integer: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                //✅ Added cin.clear() and cin.ignore() to avoid infinite loops from invalid input.
                cin.ignore();
                cout << "Enter value (string with spaces allowed): ";
                getline(cin, value);
                hm.insert(key, value);
                break;

            case 2:
                cout << "Enter key to get value: ";
                cin >> key;
                value = hm.getValueByKey(key);
                if (!value.empty())
                    cout << "Value: " << value << endl;
                else
                    cout << "Key not found\n";
                break;

            case 3:
                hm.display();
                break;

            case 4:
                cout << (hm.isEmpty() ? "Hashmap is empty\n" : "Hashmap is not empty\n");
                break;

            case 5:
                hm.getIndexVectors();
                break;

            case 6:
                cout << (hm.isFull() ? "Hashmap is full\n" : "Hashmap is not full\n");
                break;

            case 7:
                cout << "Enter key to remove: ";
                cin >> key;
                hm.remove(key);
                break;

            case 8:
                cout << "Current number of elements: " << hm.getCurrentSize() << endl;
                break;

            case 9:
                cout << "Total bucket capacity: " << hm.getCapacity() << endl;
                break;

            case 10:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}


// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 3
// Hashmap is empty

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 4
// Hashmap is empty

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 5
// Hashmap Buckets and Their Contents:
// Bucket 0: Empty
// Bucket 1: Empty
// Bucket 2: Empty
// Bucket 3: Empty

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 6
// Hashmap is not full

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 8
// Current number of elements: 0

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 9
// Total bucket capacity: 4

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 1
// Enter key (int): 12
// Enter value (string with spaces allowed): sdf
// Inserted key 12 with value 'sdf'

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 10
// Exiting program...
// PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\dsa\by me> asdfcd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\dsa\by me\" ; if ($?) { g++ 3b_Map_using_vvp_bygpt.cpp -o 3b_Map_using_vvp_bygpt } ; if ($?) { .\3b_Map_using_vvp_bygpt }
// asdfcd : The term 'asdfcd' is not recognized as the name of a cmdlet, function, script file, or operable 
// program. Check the spelling of the name, or if a path was included, verify that the path is correct and try     
// again.
// At line:1 char:1
// + asdfcd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\c ...
// + ~~~~~~
//     + CategoryInfo          : ObjectNotFound: (asdfcd:String) [], CommandNotFoundException
//     + FullyQualifiedErrorId : CommandNotFoundException

// PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\dsa\by me> cd "f:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\dsa\by me\" ; if ($?) { g++ 3b_Map_using_vvp_bygpt.cpp -o 3b_Map_using_vvp_bygpt } ; if ($?) { .\3b_Map_using_vvp_bygpt }

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 1
// Enter key (int): 10
// Enter value (string with spaces allowed): sdf
// Inserted key 10 with value 'sdf'

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 1
// Enter key (int): 11
// Enter value (string with spaces allowed): asdf
// Inserted key 11 with value 'asdf'

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 1
// Enter key (int): 3
// Enter value (string with spaces allowed): wew
// Inserted key 3 with value 'wew'

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 1
// Enter key (int): 4
// Enter value (string with spaces allowed): fghfg
// Inserted key 4 with value 'fghfg'

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 5
// Hashmap Buckets and Their Contents:
// Bucket 0: {4, fghfg}
// Bucket 1: Empty
// Bucket 2: {10, sdf}
// Bucket 3: {11, asdf} {3, wew}

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 1
// Enter key (int): 5
// Enter value (string with spaces allowed): klkk
// Inserted key 5 with value 'klkk'

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 3
// Hashmap contents:
// 4: fghfg
// 5: klkk
// 10: sdf
// 11: asdf
// 3: wew

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 5
// Hashmap Buckets and Their Contents:
// Bucket 0: {4, fghfg}
// Bucket 1: {5, klkk}
// Bucket 2: {10, sdf}
// Bucket 3: {11, asdf} {3, wew}

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 1
// Enter key (int): 7
// Enter value (string with spaces allowed): ;k;k;
// Inserted key 7 with value ';k;k;'

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 9
// Total bucket capacity: 4

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 8
// Current number of elements: 6

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 6
// Hashmap is not full

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 5
// Hashmap Buckets and Their Contents:
// Bucket 0: {4, fghfg}
// Bucket 1: {5, klkk}
// Bucket 2: {10, sdf}
// Bucket 3: {11, asdf} {3, wew} {7, ;k;k;}

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 2
// Enter key to get value: 10
// Value: sdf

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 2
// Enter key to get value: 2131313
// Key not found

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 7
// Enter key to remove: 7
// Removed key 7

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 5
// Hashmap Buckets and Their Contents:
// Bucket 0: {4, fghfg}
// Bucket 1: {5, klkk}
// Bucket 2: {10, sdf}
// Bucket 3: {11, asdf} {3, wew}

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 8
// Current number of elements: 5

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 9
// Total bucket capacity: 4

// --- HashMap Menu ---
// 1. Insert       2. Get Value    3. Display      4. isEmpty      5. Show Buckets
// 6. isFull       7. Remove       8. Current Size 9. Capacity     10. Exit
// Enter your choice: 10
// Exiting program...