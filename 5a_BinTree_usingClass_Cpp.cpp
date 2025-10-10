#include <iostream>
#include <queue>
using namespace std;

// Node class
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Binary Tree class
class BuildTree {
public:
    TreeNode* root;

    BuildTree() {
        root = nullptr;
    }

    // Create tree in level order from user
    void createTree() {
        cout << "Enter root value (-1 for no node): ";
        int val;
        cin >> val;
        if (val == -1) return;

        root = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            cout << "Enter left child of " << curr->data << " (-1 for no node): ";
            cin >> val;
            if (val != -1) {
                curr->left = new TreeNode(val);
                q.push(curr->left);
            }

            cout << "Enter right child of " << curr->data << " (-1 for no node): ";
            cin >> val;
            if (val != -1) {
                curr->right = new TreeNode(val);
                q.push(curr->right);
            }
        }
    }

    // Traversals
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(TreeNode* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(TreeNode* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Height of tree
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    // Count of nodes
    int countNodes(TreeNode* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Print all traversals
    void displayAll() {
        cout << "\nInorder: ";
        inorder(root);
        cout << "\nPreorder: ";
        preorder(root);
        cout << "\nPostorder: ";
        postorder(root);
        cout << "\nHeight: " << height(root);
        cout << "\nTotal Nodes: " << countNodes(root) << endl;
    }
};

// Main
int main() {
    BuildTree tree; 
    tree.createTree();

    cout << "\nBinary Tree :\n";
    tree.displayAll();
    return 0;
}


/*
op--

Enter root value (-1 for no node): 1
Enter left child of 1 (-1 for no node): 2 
Enter right child of 1 (-1 for no node): 3
Enter left child of 2 (-1 for no node): 4
Enter right child of 2 (-1 for no node): 5
Enter left child of 3 (-1 for no node): -1
Enter right child of 3 (-1 for no node): 6
Enter left child of 4 (-1 for no node): -1
Enter right child of 4 (-1 for no node): -1
Enter left child of 5 (-1 for no node): -1
Enter right child of 5 (-1 for no node): -1
Enter left child of 6 (-1 for no node): -1
Enter right child of 6 (-1 for no node): -1

Binary Tree :
Inorder: 4 2 5 1 3 6
Preorder: 1 2 4 5 3 6
Postorder: 4 5 2 6 3 1
Height: 3
Total Nodes: 6

    1
   / \
  2   3
 / \   \
4  5    6

*/



/*
🧠 Notes (C++):

Uses queue for level-order creation.

Each node is dynamically allocated (new).

Recursion is used for traversal, height, and node counting.

Time Complexity: O(n) for all basic traversals.

Space Complexity: O(h) (height of tree, for recursion stack).

*/



