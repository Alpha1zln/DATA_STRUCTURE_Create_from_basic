#include<bits/stdc++.h>
using namespace std;    
//typedef endl "\n";
typedef long long ll;           
typedef vector<int> vi;
typedef pair<int, int> pii;

// Queue creation using Linked List and class
// front = -1, rear = -1 means qu is empty,   // maxSize=4
// curr_size, isEmpty, isFull, enqueue, dequeue, display, size, getFront, getRear

class Qu{
public : 
    stack<int> s1, s2;
    int currSize, size;

    Qu(int sz) {
        currSize = 0;  size = sz;
    }

    void pushElt(int elt) {
        if(isFull()){
            cout << "Qu is full " << endl;
            return;
        }
        // else {
            s1.push(elt);
            currSize++;
        // }
        
    }

    int frontElt() {
        if(isEmpty()) {
            cout << "Qu is empty" << endl;
            return -1;
        }
        // If s2 has elements, front is in s2
        // if(!s2.empty()) 
        //     return s2.top();
        // else  
        //{  
        if(s2.empty()) { // ... means elts move from s1 to s2
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    void pop() {
        if(isEmpty()) {
            cout << "Qu is empty" << endl;
            return;
        }

        // If s2 is empty, refill from s1
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int frontElt = s2.top();
        cout << frontElt;

        s2.pop();
        currSize--;
        
        // repettition of steps... simplified ths in above code
        // if(!s2.empty()) {
        //     int tp = s2.top();
        //     cout << tp;
        //     s2.pop();
        // }
        // else // if (s2.empty())
        // {
        //     frontElt();

        //     int tp = s2.top();
        //     cout << tp;
        //     s2.pop();

        // }
        
    }


    bool isEmpty() {
        // if(currSize == 0) return true;
        // return false;
        return currSize == 0;
    }

    bool isFull() {
        // if(currSize == size) return true;
        // return false;
        return currSize == size;
    }

    int sizeOfQu() {
        return currSize;
    }

};


int main() {

    Qu qu(3);
    qu.pushElt(1);
    qu.pushElt(2);
    qu.pushElt(3);
/*
cases ... 
    3      1                    -   1               6       1
    2      2                    -   2               5       2
    1      3                    -   3               4       3
    s1 ... s2       or         s1   s2    or        s1      s2
*/

    cout << "Size of qu: " << qu.sizeOfQu() << endl; // 
    cout << "Empty? " << (qu.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (qu.isFull() ? "Yes" : "No") << endl; 

    cout << "Front: " << qu.frontElt() << endl; // 
    cout << "Pop: " ;   qu.pop();   cout<< endl; // 



    // cout << "Front: " << qu.frontElt() << endl; // 
    cout << "Pop: " ;   qu.pop();   cout  << endl; // 
    cout << "Pop: " ;   qu.pop();   cout  << endl; // 
    cout << "Size of qu: " << qu.sizeOfQu() << endl; // 
    cout << "Pop: " ;   qu.pop();   cout  << endl; // 
    


    cout << "Front: " << qu.frontElt() << endl; // 
    cout << "Pop: " ;   qu.pop();   cout << endl; // 



    cout << "Size of qu: " << qu.sizeOfQu() << endl; //     
    cout << "Empty? " << (qu.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (qu.isFull() ? "Yes" : "No") << endl;
    cout << "Size of qu: " << qu.sizeOfQu() << endl; //     

    qu.pushElt(4);
    qu.pushElt(5);
    qu.pushElt(44);
    cout << "Size of qu: " << qu.sizeOfQu() << endl; //     
    qu.pushElt(55);
    cout << "Front: " << qu.frontElt() << endl; // 
    cout << "Pop: " ;   qu.pop();   cout << endl; // 
    cout << "Size of qu: " << qu.sizeOfQu() << endl; //     
    


    qu.pushElt(6);

    cout << "Empty? " << (qu.isEmpty() ? "Yes" : "No") << endl;
    cout << "Full? " << (qu.isFull() ? "Yes" : "No") << endl;
    cout << "Size of qu: " << qu.sizeOfQu() << endl; //     
    

    cout << "Front: " << qu.frontElt() << endl; // 
    cout << "Pop: " ;   qu.pop();   cout << endl; //
    cout << "Size of qu: " << qu.sizeOfQu() << endl; //     
    

    cout << "Front: " << qu.frontElt() << endl; // 
    cout << "Pop: " ;   qu.pop();   cout << endl; // 
    cout << "Size of qu: " << qu.sizeOfQu() << endl; //     
    cout << "Front: " << qu.frontElt() << endl; // 
    
    return 0;
}


/*
if 3 elts added ... qu is full now .. 1 2 3
Size of qu: 3
Empty? No
Full? Yes
Front: 1

Pop: 1
Pop: 2
Pop: 3
Size of qu: 0
Pop: Qu is empty

Qu is empty
Front: -1
Pop: Qu is empty

Size of qu: 0
Empty? Yes
Full? No
Size of qu: 0

if 3 elts added ... 4 5 44
Size of qu: 3
Qu is full

Front: 4
Pop: 4
Size of qu: 2   ... 5 44

if 6 is added
Empty? No
Full? Yes
Size of qu: 3     ... 5 44 6

Front: 5
Pop: 5
Size of qu: 2  ... 44 6

Front: 44
Pop: 44
Size of qu: 1 ... 6
Front: 6
*/