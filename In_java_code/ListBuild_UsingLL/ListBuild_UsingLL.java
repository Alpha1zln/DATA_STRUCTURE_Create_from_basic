
class Node {
    int val;
    Node next;
    Node(int v) { val = v; next = null; }
}

class ListCreation {
    Node head = null   , tail = null;

    public void addFirst(int val) {
        Node newNode = new Node(val);
        newNode.next = head;
        if(head == null) tail = newNode;
        head = newNode;
    }

    public void addLast(int val) {
        Node newNode = new Node(val);
        if (head == null) { head = newNode; tail = newNode; return; }
        // Node curr = head;
        // while (curr.next != null) curr = curr.next;
        // curr.next = newNode;
        tail.next = newNode;    tail = newNode;
    }

    public void removeFirst() {
        if (head != null) head = head.next;
    }

    public void removeLast() {
        if (head != null) {
            Node curr = head, back = head;
            while (curr.next != null) {
                back = curr;    curr = curr.next; 
            } 
            back.next = null; 
        }
        else {System.out.println("Empty");}
    }


    public void printList() {
        Node curr = head;
        while (curr != null) { 
            System.out.print(curr.val + " "); 
            curr = curr.next; 
        }
        System.out.println();
    }
}

public class ListBuild_UsingLL {
    public static void main(String[] args) {

        ListCreation list = new ListCreation();
        list.addFirst(2);   list.addFirst(5);
        list.addLast(10);  list.addLast(40);   
        list.printList(); // 5 2 10 40

        list.removeFirst();       list.removeLast();
        list.printList();    // 2 10
    }
}







/*
 Base DS used: Nodes (Linked structure)

Time Complexity: addFirst O(1), addLast O(n), removeFirst O(1)

Space Complexity: O(n)
 
*/


/*   
op ---
5 2 10 40 

2 10  
*/