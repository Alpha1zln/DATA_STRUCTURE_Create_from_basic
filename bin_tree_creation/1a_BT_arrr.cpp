#include <bits/stdc++.h>
using namespace std;

// Tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Recursive function to build binary tree from vector
Node* buildTree(const vector<int>& arr, int i) {
    // Base case: if index is out of range
    if (i >= arr.size()) return NULL;

    // Create current node
    Node* root = new Node(arr[i]);

    // Build left and right subtrees recursively
    root->left = buildTree(arr, 2 * i + 1);
    root->right = buildTree(arr, 2 * i + 2);

    return root;
}

/*
🔁 Key Recursion Idea

For node at index i:

Left child → 2*i + 1

Right child → 2*i + 2

Recursion naturally builds subtrees until the index exceeds arr.size().
*/

// Inorder traversal to verify tree structure
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60};

    Node* root = buildTree(arr, 0); // Start from index 0

    cout << "Inorder Traversal of Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}



// op =
// Inorder Traversal of Tree: 40 20 50 10 60 30


/*
data
Index:  0   1   2   3   4   5
Value: 10  20  30  40  50  60

        10
       /  \
     20    30
    /  \   /
  40   50 60

*/


/*
note--

🧠 Summary of Difference Between struct and class
Feature	                    struct               	   class
Default access specifier	public	                  private
Syntax	                struct Node { ... };	     class Node { public: ... };
Purpose (by convention)	For simple data containers	 For encapsulated objects / OOP design





*/