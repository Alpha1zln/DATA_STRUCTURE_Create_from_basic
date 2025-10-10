import java.util.*;

class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode(int val) {
        data = val;
        left = right = null;
    }
}

class BuildTree {
    TreeNode root;

    BuildTree() {
        root = null;
    }

    // Create tree level-wise
    void createTree() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter root value (-1 for no node): ");
        int val = sc.nextInt();
        if (val == -1) return;

        root = new TreeNode(val);
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode curr = q.poll();

            System.out.print("Enter left child of " + curr.data + " (-1 for no node): ");
            val = sc.nextInt();
            if (val != -1) {
                curr.left = new TreeNode(val);
                q.add(curr.left);
            }

            System.out.print("Enter right child of " + curr.data + " (-1 for no node): ");
            val = sc.nextInt();
            if (val != -1) {
                curr.right = new TreeNode(val);
                q.add(curr.right);
            }
        }
    }

    // Traversals
    void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

    void preorder(TreeNode node) {
        if (node == null) return;
        System.out.print(node.data + " ");
        preorder(node.left);
        preorder(node.right);
    }

    void postorder(TreeNode node) {
        if (node == null) return;
        postorder(node.left);
        postorder(node.right);
        System.out.print(node.data + " ");
    }

    int height(TreeNode node) {
        if (node == null) return 0;
        return 1 + Math.max(height(node.left), height(node.right));
    }

    int countNodes(TreeNode node) {
        if (node == null) return 0;
        return 1 + countNodes(node.left) + countNodes(node.right);
    }

    void displayAll() {
        System.out.print("\nInorder: ");
        inorder(root);
        System.out.print("\nPreorder: ");
        preorder(root);
        System.out.print("\nPostorder: ");
        postorder(root);
        System.out.println("\nHeight: " + height(root));
        System.out.println("Total Nodes: " + countNodes(root));
    }
}

public class Main {
    public static void main(String[] args) {
        BuildTree tree = new BuildTree();
        tree.createTree();
        tree.displayAll();
    }
}





/* 
 * op--
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

Inorder: 4 2 5 1 3 6
Preorder: 1 2 4 5 3 6
Postorder: 4 5 2 6 3 1
Height: 3
Total Nodes: 6
  


*/


/*

1-Take binary tree input in level-order form from user.
(Example input → 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1)
where -1 = null.

2-Build the tree.

3-Print tree structure visually like
    1
   / \
  2   3
 / \   \
4  5    6

*/





/*
🧠 Notes (Java):

Works exactly like C++ version, but without pointers.

Uses Queue<TreeNode> for level-wise tree building.

JVM’s garbage collector manages memory automatically.

⚙️ Useful Extensions You Can Add Later:

✅ search(int key) — check if a value exists
✅ sumOfNodes() — add all node values
✅ levelOrder() — print tree level by level
✅ mirrorTree() — invert the tree
 */