
// Set (using LinkedList for collision handling) ***


class LinkedNode {
    int val;   
    LinkedNode next;
    LinkedNode(int v) { val = v; next = null; }
}


class SetCreation {
    LinkedNode[] buckets;    // array of linked list heads
    int size = 6;   LinkedNode head;
    int currSize = 0;

    public SetCreation() {
        buckets = new LinkedNode[size];
        head = null;
    }

    private int hash(int val) { 
        return Math.abs(val) % size; 
    }

    public void add(int val) {
        int idx = hash(val);
        LinkedNode curr = buckets[idx];
        while (curr != null) {
            if (curr.val == val) return; // already exists
            curr = curr.next;
        }
        LinkedNode newNode = new LinkedNode(val);
        newNode.next = buckets[idx];
        buckets[idx] = newNode;
        currSize++;
    }

    public boolean contains(int val) {
        int idx = hash(val);
        LinkedNode curr = buckets[idx];
        System.out.print("Contains elt with " + val + " : ");
        while (curr != null) {
            if (curr.val == val) return true;
            curr = curr.next;
        }
        return false;
    }

    public void remove(int val) {
        int idx = hash(val);
        LinkedNode curr = buckets[idx], prev = null;
        while (curr != null) {
            if (curr.val == val) {
                if (prev == null) {buckets[idx] = curr.next; }
                else {prev.next = curr.next; }
                currSize--;
                return;
            }
            prev = curr;
            curr = curr.next;
        }
    }

    public void print() {
     System.out.println("Current Set elements:");
    for (int i = 0; i < size; i++) {
        LinkedNode curr = buckets[i];
        while (curr != null) {
            System.out.println("index: "+ i + " -> val: "+ curr.val );
            curr = curr.next;
        }
    }
    System.out.println("\n----");
    }


    public void currSizeSet() {
        System.out.println("Curr size of Set: " + currSize);
    }
}



class SetBuild_BaseDS_LLArr {

    public static void main(String[] args) {
        SetCreation stt = new SetCreation();

        stt.add(5); stt.add(10);
        stt.add(5); stt.add(20);
        stt.currSizeSet();    stt.print(); 
        
        System.out.println(stt.contains(5));  // true
        System.out.println(stt.contains(3));  // false
        stt.remove(5);     
        System.out.println(stt.contains(5));  // false 
        stt.currSizeSet();    stt.print(); 
        
    }
}





/*
 op ---
 Curr size of Set: 3
Current Set elements:
index: 2 -> val: 20
index: 4 -> val: 10
index: 5 -> val: 5

----
Contains elt with 5 : true
Contains elt with 3 : false
Contains elt with 5 : false
Curr size of Set: 2
Current Set elements:
index: 2 -> val: 20
index: 4 -> val: 10

----
*/

/*
 Base DS used: Array + Linked List

Time Complexity: add/remove/contains O(n) worst-case, O(1) average

Space Complexity: O(n)
*/