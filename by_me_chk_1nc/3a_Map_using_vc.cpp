#include<bits/stdc++.h>
using namespace std;

// Hashmap creation using vector and class

// colliosn happening here ... simple hashmap implementation using vector and class
// 

class HashMap {
    private:
        vector<pair<int, string>> mapA; // Vector to store key-value pairs
        int capacity; // Maximum size of the hashmap

            // Simple hash function
        int hash(int key) {
            return (1+ (key % capacity)); // Hash function to find index
            // return key % capacity; // Simple hash function
        }

    public:
        HashMap(int size) : capacity(size+1) {
            mapA.resize(capacity+1); // Resize the vector to the specified capacity
        }

        void insert(int key, string value) {
            int index = hash(key); // key % capacity; // Hash function to find index
            
            // check if the key already exists
            if (mapA[index].first == key) 
            {
                cout << "collision detected for key: " << key << endl;
                mapA[index].second = value; // Update value if key already exists
                cout << "Updated key " << key << " with value " << value << endl;
                return;
            } 
            
            // Key not found, insert new pair
            // table[idx].push_back({key, value});
            mapA[index] = make_pair(key, value); // Insert key-value pair
        }

        // Get value for a key
        string get(int key) {
            int index = hash(key);    // key % capacity; // Hash function to find index
            if (mapA[index].first == key) {
                return mapA[index].second; // Return value if key matches
            }
            cout << "Key : " << key << " not found"; // Return message if key does not match
            return ""; // Return empty string if key not found
        }

        void display() {
            int current_size = size(); // Get current size of the hashmap
            if (current_size == 0) {
                cout << "Hashmap is empty\n";
                return;
            }
            //for (int i = 0; i < current_size; i++) {
                //auto& pair = mapA[i];
                //if (pair.first == 0) continue; // Skip empty slots  
            cout << "Hashmap elements:\n";
            for(auto pair : mapA) { // Iterate through the vector
                if (pair.first == -1 || pair.first==0) continue; // Skip empty slots
                // Display key-value pairs             
                cout << pair.first << ": " << pair.second << endl; // Display all key-value pairs
            }
             //cout << endl;
        }

        // Remove key-value pair
        void remove(int key) {
            int idx = hash(key);
                if (mapA[idx].first == key) {
                    mapA[idx].first = -1; // Assuming 0 is not a valid key
                    mapA[idx].second = ""; // Clear the value
                    return;
                }
                else {
                    cout << "Key : " << key << " not found for removal in map\n";
                }
            }
        

        // size of the hashmap
        int size() {
            int count = 0;
            for (auto pair : mapA) {
                if (pair.first != -1 && pair.first != 0) { 
                    // Assuming -1,0 is not a valid key
                    count++;
               }
            }
            return count; // Return the number of elements in the hashmap
        }
};





int main() {
    HashMap mpp(4);



    int choice, key;
    string value;
    while (true) {
        cout << "\nHashmap operations using vector and class\n";
        cout << "1. Insert\t 2. Get\t\t 3. Display\t \n";
        cout << "4. Remove\t 5.Size\t\t 6. Exit\t \n";
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key{int} and value{string} : ";
                cin >> key >> value;
                mpp.insert(key, value);
                break;
            case 2:
                cout << "Enter key to get value: ";
                cin >> key;
                if (mpp.get(key) != "") {
                    cout << "Value: " << mpp.get(key) << endl;    
                }
                break;
            case 3:
                mpp.display();
                break;
            case 4:
                cout << "Enter key to remove: ";
                cin >> key;
                mpp.remove(key);
                break;
            case 5:
                cout << "Size of hashmap: " << mpp.size() << endl; // Assuming size() method exists
                break;
            case 6:
                cout << "Exiting...\n";
                return 0; // Exit the program
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}




// Hashmap elements:
// 1: co
// 78: abv
// 99: tim

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 1
// Enter key{int} and value{string} : 44 gh

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 3
// Hashmap elements:
// 1: co
// 78: abv
// 44: gh

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 1
// Enter key{int} and value{string} : 35 asdf

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 3
// Hashmap elements:
// 35: asdf
// 1: co
// 78: abv
// 44: gh

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 1
// Enter key{int} and value{string} : 32 yak

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 3
// Hashmap elements:
// 35: asdf
// 1: co
// 32: yak
// 78: abv
// 44: gh

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 2
// Enter key to get value: 1
// Value: co

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 5
// Size of hashmap: 5

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 4
// Enter key to remove: 1

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 5
// Size of hashmap: 4

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 3
// Hashmap elements:
// 35: asdf
// 32: yak
// 78: abv
// 44: gh

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 1
// Enter key{int} and value{string} : 11 iop

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 3
// Hashmap elements:
// 35: asdf
// 11: iop
// 32: yak
// 78: abv
// 44: gh

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 4
// Enter key to remove: 123
// Key : 123 not found for removal in map

// Hashmap operations using vector and class
// 1. Insert        2. Get          3. Display
// 4. Remove        5.Size          6. Exit
// Enter your choice: 6
// Exiting...