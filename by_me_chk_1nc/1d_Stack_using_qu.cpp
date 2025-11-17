#include <bits/stdc++.h>
using namespace std;

class StackUsingQu {
public:
    queue<int> q1, q2;
    int currSize, size;

    StackUsingQu(int sz) {
        currSize = 0;  size = sz;
    }

    void push(int et) {
        if(isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        // Step 1: push to empty q1
        // let newest elt be in q1 first ... then mv rest elts in q1 
        q1.push(et);

        // Step 2: move rest elts from q2 → q1, all above newest elt
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        // now q2 is empty ... and all elts in q1 now

        // Step 3: swap q1 & q2 ... 
        //so q1 is empty now, all els in q2 now 
        swap(q1, q2);
        currSize++;
        // repeat this step again .. 
        // so newest elt will be at bottom of q2 always
    }

    void pop() {
        if(q2.empty()) {
            cout << "Stack is empty";
            return;
        }
        int frontElt = q2.front();
        cout << frontElt;
        q2.pop();
        currSize--;
    }

    int top() {
        if(q2.empty()) {
            // cout << " Stack is empty ";
            return -1;
        }
        return q2.front();
    }

    bool isEmpty() {
        return q2.empty();
    }

    bool isFull() {
        return size == currSize;
    }

    int sizeQ() {
        return currSize;
    }
};



int main() {

    StackUsingQu stk(3);  // 2 qu

    stk.push(10);
    stk.push(20);
    stk.push(30);
    cout << endl;

    cout << "Size: " << stk.sizeQ() << endl;
    cout << "Top: " << stk.top() << endl;  // 
    cout << "Empty? " << (stk.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (stk.isFull() ? "Yes" : "No") << endl;
    cout << endl;

    cout << "Pop: " ; stk.pop() ; cout << endl;  // 
    cout << "Pop: " ; stk.pop() ; cout << endl;  // 
    cout << "Pop: " ; stk.pop() ; cout << endl;  // 
    cout << "Pop: " ; stk.pop() ; cout << endl;  // 
    cout << "Size: " << stk.sizeQ() << endl;
    cout << "Empty? " << (stk.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (stk.isFull() ? "Yes" : "No") << endl;
    cout << endl;
    
    
    cout << "Top: " << stk.top() << endl;  // 
    cout << "Pop: " ; stk.pop() ; cout << endl;  // 
    cout << "Size: " << stk.sizeQ() << endl;
    cout << "Empty? " << (stk.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (stk.isFull() ? "Yes" : "No") << endl;
    cout << endl;
    

    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.push(7);

    cout << "Top: " << stk.top() << endl;  // 
    cout << "Size: " << stk.sizeQ() << endl;
    cout << "Empty? " << (stk.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (stk.isFull() ? "Yes" : "No") << endl;
    cout << endl;
    

    cout << "Pop: " ; stk.pop() ; cout << endl;  // 
    cout << "Pop: " ; stk.pop() ; cout << endl;  // 
    cout << "Size: " << stk.sizeQ() << endl;
    cout << "Empty? " << (stk.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (stk.isFull() ? "Yes" : "No") << endl;
    cout << "Top: " << stk.top() << endl;  // 
    return 0;
}


/*
op---------
3 elts r added ... 10 20 30[newest] .
                    .. q2 -> 3 2 1 .. q1 empty

Size: 3 
Top: 30
Empty? No
Full? Yes

Pop: 30
Pop: 20
Pop: 10     .. all elts rmvd ... 
            //q2 empty now...q1 always empty after push oprtnsh
Pop: Stack is empty
Size: 0
Empty? Yes
Full? No

Top: -1     .. no top.. empty
Pop: Stack is empty
Size: 0
Empty? Yes
Full? No

// add elts 4 5 6 ... q2 has 6 5 4 .. .q1 empty
Stack is full
Top: 6  ... q2 has 6 5 4
Size: 3
Empty? No
Full? Yes

Pop: 6    ... q2 has 6 5 4 ... now 5 4 
Pop: 5
Size: 1     ... q2 .. 4
Empty? No
Full? No
Top: 4
*/
