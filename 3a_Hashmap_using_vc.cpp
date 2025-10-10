#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
    vector<int> map;
    const int DEFAULT = -1;
public:
    MyHashMap() : map(1e6 + 1, DEFAULT) {}

    void put(int key, int value) {
        map[key] = value;
    }

    int get(int key) {
        return map[key];
    }

    void remove(int key) {
        map[key] = DEFAULT;
    }
};

int main() {
    MyHashMap hm;
    hm.put(1, 10);
    hm.put(2, 20);
    cout << "Get key 1: " << hm.get(1) << endl;  // 10
    cout << "Get key 3: " << hm.get(3) << endl;  // -1
    hm.put(2, 30);
    cout << "Updated key 2: " << hm.get(2) << endl;  // 30
    hm.remove(2);
    cout << "After removal key 2: " << hm.get(2) << endl;  // -1
    return 0;
}
