
// in 3a code ... 
// ✅ Summary: Why overriding happens?
// Code Version	        Handles Collision?	    Behavior When Collision
// vector<pair<>>	        ❌ No	                Overwrites value
// vector<list<pair<>>>	    ✅ Yes (Chaining)	    Adds to the list

// ******
// Collisions are natural due to hash function.

// To handle them safely, use:
    //1- Separate chaining using list/vector.
    //2- Open addressing (linear/quadratic probing).

// 🧠 Summary
// Method	        Description	                                    Pros	            Cons
// Chaining	          Each slot has a list of key-value pairs	Simple, flexible	Extra memory for lists
// Open Addressing	  Probes other slots on collision	        Space efficient	    Clustering, harder delete

// ✅ Standard Ways to Handle Collision:

// 1. Chaining (Separate Chaining using Linked List or Vector of pairs)
    // Each index of the vector stores a list of key-value pairs.
    // Collisions are handled by appending to the list at that index.

// 2. Open Addressing (Linear Probing, Quadratic Probing, Double Hashing)
    // If the hash index is occupied, probe the next index (or a calculated one) until a free spot is found.

// *********


// 3b_Map_using_vvi.cpp 
// Hashmap using "separate chaining" using vector of vector of pairs.  
// vector<vector<pair<int, string>>> mapA; // Vector of vector to store key-value pairs
// collsion handling using vector of vector of pairs
// 1. Insert        2. Get          3. Display 
// 4. Remove        5.Size          6. Exit


// slight err when add extra elts ...
#include <iostream>
#include <vector>   
#include <utility>   // for std::pair
#include <string>   
using namespace std;    
// Hashmap creation using vector of vector pair and class

class HashMap {
    private:
        vector<vector<pair<int, string>>> mapVvp; // Vector of vector to store key-value pairs
        int capacity; // Size of the hashmap
        int current_size; // Current size of the hashmap

        // Hash function to calculate index
        int hash(int key) {
            int index = 1 + (key % capacity); // Hash function to find index
            return index; // Simple modulo hash function
        }

    public:
        // Constructor to initialize the hashmap with a given capacity
        HashMap(int cap) : capacity(cap+1) {
            mapVvp.resize(capacity+1); // Resize the vector to the specified capacity
            current_size = 0; // Initialize current size to 0
        }

        // Insert key-value pair into the hashmap
        void insert(int key, const string& value) {
            int index = hash(key);

            for (auto& pair : mapVvp[index]) {    //  pr     :  vc
                if (pair.first == key) { // If key already exists, update value
                    pair.second = value;
                    cout << "Updated key " << key << " with value " << value << endl;
                    return;
                }
            }
            // If key does not exist, add new key-value pair
            current_size++;
            mapVvp[index].emplace_back(key, value); // Add new key-value pair
            cout << "Inserted key " << key << " with value " << value << endl;
        }

        // Get value by key from the hashmap
        string getValueByKey(int key) {
            int index = hash(key);

            for (const auto& pair : mapVvp[index]) {
                if (pair.first == key) {
                    return pair.second; // Return the value if key is found
                }
            }
            return ""; // Return empty string if key not found
        }

        // Display all elements in the hashmap
        void display() {
            int current_size = size(); // Get current size of the hashmap
            if (current_size == 0) {
                cout << "Hashmap is empty\n";
                return;
            }
            cout << "Hashmap elements:\n";
            for (const auto& bucket : mapVvp) {    // bkt = vc
                for (const auto& pair : bucket) {
                    if (pair.first != -1 && pair.first != 0) { // Skip empty slots
                        cout << pair.first << ": " << pair.second << endl; // Display key-value pairs
                    }
                }
            }
        }

        // Remove key from the hashmap
        void remove(int key) {  
            int index = hash(key);
            auto& bucket = mapVvp[index];  // vc of pair = bkt

            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (it->first == key) {
                    bucket.erase(it); // Remove the key-value pair from vector bkt ?
                    cout << "Removed key " << key << endl;
                    current_size--; // Decrease current size
                    return;
                }
            }
            cout << "Key: " << key << " not found for removal in map\n"; // Key not found
        }

        // Get the size of the hashmap
        int size() {    
//            int count = 0;
            // for (const auto& bucket : mapVvp) {
            //     for (const auto& pair : bucket) {
            //         if (pair.first != -1 && pair.first != 0) { // Assuming -1,0 is not a valid key
            //             count++;
            //         }
            //     }
            //}
            int count = current_size; // Return the current size of the hashmap
            return count; // Return the number of elements in the hashmap
        }

        
        // Clear the hashmap
        void clear() {
            for (auto& bucket : mapVvp) {
                bucket.clear(); // Clear each bucket
            }
            current_size = 0; // Reset current size
            cout << "Hashmap cleared\n";
        }


        // Reset the hashmap
        void reset() {      
            clear(); // Clear the hashmap
            cout << "Hashmap reset\n";
        }


        // Check if the hashmap is empty
        bool isEmpty() {    
            return current_size == 0; // Return true if current size is 0
        }

        // Check if the hashmap is full
        bool isFull() {
            return current_size == capacity; // Return true if current size equals capacity
        }

        // Get the current size of the hashmap
        int getCurrentSize() {
            return current_size; // Return the current size of the hashmap
        }

        // Get the capacity of the hashmap
        int getCapacity() { 
            return capacity; // Return the capacity of the hashmap
        }   

        // Get the vector of vector of pairs (for testing purposes)
        // vector<vector<pair<int, string>>> getMap() {
           // return mapVvp; // Return the vector of vector of pairs
        //  .}// 

        // Get the vector of vector of pairs (for testing purposes)
        vector<vector<pair<int, string>>> getMap() {
            return mapVvp; // Return the vector of vector of pairs
        }

        void getIndexVectors() {
            cout << "Hashmap index and vector pairs in it :\n";
            for (int i = 1; i < mapVvp.size(); ++i) {
                cout << "Index " << i << ": ";
                if (mapVvp[i].empty()) {
                    cout << "Empty\n"; // If the vector at index is empty
                    continue;
                }
                cout << "Contains pairs: ";
                // Iterate through the vector at index i and print pairs
                for (const auto& pair : mapVvp[i]) {
                    cout << "{" << pair.first << ", " << pair.second << "} ";
                }
                cout << endl;
            }
        }

    }; // End of HashMap class


// Main function to demonstrate the HashMap operations
int main() {
    HashMap mpp(4); // Create a HashMap with capacity 4

    int choice, key;
    string value;
    while (true) {
        cout << "\nHashmap operations using vector of vector of pairs\n";
        cout << "1. Insert\t 2. GetValue\t 3. Display\t 4. isEmpty\t 5.IndexVector \n"  ;
        cout << "6. isFull\t 7. Remove\t 8.Curr_Size\t  9.Capacity\t 10. Exit\n";

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
                if (mpp.getValueByKey(key) != "") 
                    cout << "Value: " << mpp.getValueByKey(key) << endl;
                else
                    cout << "Key not found\n";
                break;
            case 3:
                mpp.display();
                break;
            case 4:
                cout << (mpp.isEmpty() ? "Hashmap is empty\n" : "Hashmap is not empty\n");
                break;
            case 5:
                mpp.getIndexVectors();
                break;
            case 6:
                cout << (mpp.isFull() ? "Hashmap is full\n" : "Hashmap is not full\n");
                break;
            case 7:
                cout << "Enter key to remove: ";
                cin >> key;
                mpp.remove(key);
                break;
            case 8:
                cout << "Current size of hashmap: " << mpp.getCurrentSize() << endl;
                break;

                // cout << "Size of hashmap: " << mpp.size() << endl; // Assuming size() method exists
                // break;
            case 9:
                cout << "Capacity of hashmap: " << mpp.getCapacity() << endl; // Assuming getCapacity() method exists
                break;
            case 10:
                cout << "Exiting...\n";
                return 0; // Exit the program
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}







// 
// auto& bucket = mapVvp[index];

// for (auto it = bucket.begin(); it != bucket.end(); ++it) {
    //  This line starts a loop to traverse all key-value pairs in the bucket.
    // it is an iterator pointing to each pair<int, string> in the bucket.
    // We're scanning each element to find the one matching the key to be deleted.
//     if (it->first == key) {       .. like it.first ...
//         bucket.erase(it); // Remove the key-value pair
//         cout << "Removed key " << key << endl;
//         return;
//     }
// }



// qs and ans ^^^^^^^^^^^
//   string value vs const string& value ... *** ques ans
// ✅ Summary Table
// Parameter Type	    Copies String?	    Can Modify?	    Performance
// string value	            ✅ Yes	        ✅ Yes	        Slower
// const string& value	    ❌ No	        ❌ No           	Faster



// qs and ans ^^^^^^^^^^^
// emplace_back       vs      push_back

// ChatGPT said:
// Great! Let's compare emplace_back vs push_back in C++ — especially in STL containers like vector, deque, etc.

// ✅ 1. push_back()
// It adds a copy (or move) of an element to the end of a container.
// You have to create the object before inserting it.

// vector<pair<int, string>> v;
// v.push_back(make_pair(1, "abc")); // OK

// Internally:
// // This creates a pair object and then copies (or moves) it into the vector
// pair<int, string> p(1, "abc");
// v.push_back(p);


// ✅ 2. emplace_back()
// It constructs the object directly inside the container using the arguments.
// More efficient because it avoids temporary object creation and copying.

// vector<pair<int, string>> v;
// v.emplace_back(1, "abc"); // Constructs pair<int, string> in-place

// Internally:
// // No need to make a pair manually — done inside vector's memory

// 🧪 Code Example
// #include <iostream>
// using namespace std;

// int main() {
//     vector<pair<int, string>> v;

//     // push_back requires pair or make_pair
//     v.push_back(make_pair(1, "push"));

//     // emplace_back directly takes constructor args
//     v.emplace_back(2, "emplace");

//     for (auto& p : v)
//         cout << p.first << " => " << p.second << endl;
// }
// Output:

// 1 => push  
// 2 => emplace

// 🏁 Rule of Thumb:
// Use emplace_back by default — it’s cleaner, faster, and safer when inserting new objects.


//**************************** *