#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Recursive function to build tree
Node* buildTree() {
    int val;
    cout << "Enter node value (-1 for no node): ";
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);

    cout << "Enter left child of " << val << ":\n";
    root->left = buildTree();

    cout << "Enter right child of " << val << ":\n";
    root->right = buildTree();

    return root;
}

// Inorder traversal to check the tree
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "Build your binary tree:\n";
    Node* root = buildTree();

    cout << "\nInorder traversal of tree: ";
    inorder(root);
    cout << endl;

    return 0;
}


/*
enter-
Build your binary tree:
Enter node value (-1 for no node): 10
Enter left child of 10:
Enter node value (-1 for no node): 20
Enter left child of 20:
Enter node value (-1 for no node): 30
Enter left child of 30:
Enter node value (-1 for no node): -1
Enter right child of 30:
Enter node value (-1 for no node): -1
Enter right child of 20:
Enter node value (-1 for no node): 40
Enter left child of 40:
Enter node value (-1 for no node): -1
Enter right child of 40:
Enter node value (-1 for no node): -1
Enter right child of 10:
Enter node value (-1 for no node): 50
Enter left child of 50:
Enter node value (-1 for no node): 60
Enter left child of 60:
Enter node value (-1 for no node): -1
Enter right child of 60:
Enter node value (-1 for no node): -1
Enter right child of 50:
Enter node value (-1 for no node): 70
Enter left child of 70:
Enter node value (-1 for no node): -1
Enter right child of 70:
Enter node value (-1 for no node): -1


op-
Inorder traversal of tree: 30 20 40 10 60 50 70

        10
     /       \
    20        50
   /  \     /   \
  30  40   60    70

*/