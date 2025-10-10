#include <iostream>
#include <list>
#include <vector>
using namespace std;

const int SIZE = 1009; // A prime number to reduce collisions

class MyHashMap {
    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        table.resize(SIZE);
    }

    void put(int key, int value) {
        int idx = hash(key);
        for (auto& p : table[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[idx].emplace_back(key, value);
    }

    int get(int key) {
        int idx = hash(key);
        for (auto& p : table[idx]) {
            if (p.first == key) return p.second;
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        table[idx].remove_if([&](auto& p) { return p.first == key; });
    }
};

int main() {
    MyHashMap hm;
    hm.put(1, 10);
    hm.put(1001, 50);  // Collision with 1 (if SIZE = 1000), but handled

    cout << "Get 1: " << hm.get(1) << endl;        // 10
    cout << "Get 1001: " << hm.get(1001) << endl;  // 50

    hm.put(1, 99);
    cout << "Updated 1: " << hm.get(1) << endl;    // 99

    hm.remove(1);
    cout << "After removal 1: " << hm.get(1) << endl; // -1
    return 0;
}


// 🤔 How Collision Is Handled in HashMaps?
// When two keys hash to the same index, it’s called a collision. Since two values can't live in the same array cell directly, we need a collision resolution technique.

// ✅ There are Two Main Ways:
// 1. Separate Chaining (Used in your Linked List version)
// Each bucket stores a list of key-value pairs.

// All keys that hash to the same index are stored in a linked list (or vector, or any collection).

// When inserting:

// If key exists → update value

// Else → append to list

// Example:

// cpp
// Copy
// Edit
// hash(1) → index 9
// hash(1001) → index 9  // collision

// bucket[9] = [ (1, 10), (1001, 50) ]
// ✅ This is how C++ STL unordered_map works internally.

// 2. Open Addressing (Not used above — but common)
// Instead of storing lists at each index:

// If a spot is taken, it probes for the next available spot

// Types:

// Linear Probing: try next index

// Quadratic Probing: try i^2 jumps

// Double Hashing: use second hash