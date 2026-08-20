
import java.util.LinkedList;
import java.util.Queue; 



// -------------- CLASS TREE ------------------------
public class TreeDsa {

    // -------------- TREENODE ------------------------
    public static class TreeNode {
        int data;
        TreeNode left, right;

        TreeNode(int val) {
            this.data = val;
            this.left = null;        this.right = null;
        }
    }
    
    // --------------- CLASS - BUILD-TREE --------------------
    public static class BuildTreeClass {
        public static int idx = 0;      
          
        public static TreeNode createTree(int NodesArr[]) {
            if(NodesArr[idx] == -1) {
                idx++;   return null;
            }

            TreeNode newNd = new TreeNode(NodesArr[idx]);
            idx++;
            newNd.left = createTree(NodesArr);
            newNd.right = createTree(NodesArr);

            return newNd;
        }
    }

    // --------------- FIND HEIGHT --------------------
    public static int findHt(TreeNode root) {
        if (root == null) return 0;

        int lh = findHt(root.left);
        int rh = findHt(root.right);

        return Math.max(lh, rh) + 1;
    }

    // --------------- LEVEL ORDER --------------------
    public static void levelOrder(TreeNode node) {
        Queue<TreeNode> qu = new LinkedList<>();
        qu.add(node);

        while (!qu.isEmpty()) {
            int size = qu.size();

            for (int i = 0; i < size; i++) {
                TreeNode currNd = qu.poll();
                System.out.print(currNd.data + " ");

                if (currNd.left != null) qu.add(currNd.left);
                if (currNd.right != null) qu.add(currNd.right);
            }
            System.out.println("");
        }
    }

    // ----------- FIND DIA --------------------------------------------------
    // public static void findDia(TreeNode root, int maxDia[]) {  /// O(n^2) = tc
    //     if (root == null) return;

    //     int lh = findHt(root.left);
    //     int rh = findHt(root.right);

    //     //int leftDia = 
    //     findDia(root.left, maxDia);
    //     //int rightDia = 
    //     findDia(root.right, maxDia);

    //     int currDia = lh + rh;
    //     maxDia[0] = Math.max(maxDia[0], currDia);
    //     //return Math.max(currDia, Math.max(leftDia, rightDia));
    // }
    
     public static int findDia(TreeNode root, int maxDia[]) {  /// O(n) = tc
        if (root == null) return 0;

        int lh = findHt(root.left);
        int rh = findHt(root.right);
        
        int currDia = lh + rh;
        maxDia[0] = Math.max(maxDia[0], currDia);
        
        int ht = Math.max(lh, rh) + 1;
        return ht; // return the height of the current subtree
    }

    // -------------- PSVM - MAIN ----------------------
    public static void main(String[] args) {
        // preorder array representation of the tree
        int nodesArr[] = {1, 2,4, -1,-1, -1, 3, 5,-1, 7,-1,-1, 6,-1, 8,-1,-1};
        TreeNode rootNd = BuildTreeClass.createTree(nodesArr);  

        //int index=0;
        //for(int et : NodesArr) {
          //  index++;
        //}

        System.out.println("Level Order is : ");
        levelOrder(rootNd);

        int maxDia[] = new int[1];
        findDia(rootNd, maxDia);
        
        System.out.println("Height is : "+ findHt(rootNd));
        System.out.println("Dia is : "+ maxDia[0]);

    }
}



/*
OP ---------------------------------------

Level Order is : 
1 
2 3 
4 5 6 
7 8 

Height is : 4
Dia is : 6

*/




/*
/*


*********** In your code     ** vip ************

Thing	                        Why static?
static int idx	            One shared index during tree construction
static int maxDia	        One shared maximum diameter
static createTree()	        Doesn't need a BuildTreeClass object
static findDia()	        Doesn't need a TreeDsa object
static TreeNode	            Nested class doesn't need outer TreeDsa object
static BuildTreeClass	    Nested class doesn't need outer TreeDsa object
static main()	            JVM needs to call it without creating TreeDsa object

*/
*/