#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    // ****  only 1 qu is used .. optimized ver of stack using 1 qu ********
    
    void push(int x) {
        q.push(x);
        int sz = q.size();

        // Rotate: move previous elements behind new element
        for(int i = 1; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if(q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


int main() {

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;  // 30
    cout << "Pop: " << st.pop() << endl;  // 30

    cout << "Top: " << st.top() << endl;  // 20
    cout << "Pop: " << st.pop() << endl;  // 20

    st.push(99);
    cout << "Top: " << st.top() << endl;  // 99

    cout << "Pop: " << st.pop() << endl;  // 99
    cout << "Pop: " << st.pop() << endl;  // 10

    cout << "Empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}


/*
Top: 30
Pop: 30
Top: 20
Pop: 20
Top: 99
Pop: 99
Pop: 10
Empty? Yes
*/
