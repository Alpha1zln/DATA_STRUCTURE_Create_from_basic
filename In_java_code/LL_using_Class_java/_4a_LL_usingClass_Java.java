import java.util.Scanner;

// Node class
class LinkedNode {
    int data;
    LinkedNode next;

    LinkedNode(int val) {
        data = val;
        next = null;
    }
}

// Linked list operations
class BuildLinkedList {
    LinkedNode head;

    BuildLinkedList() {
        head = null;
    }

    // Create list from user input
    void createList() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter value: ");
            int val = sc.nextInt();
            insertAtEnd(val);
        }
    }

    // Insert at end
    void insertAtEnd(int val) {
        LinkedNode newNode = new LinkedNode(val);
        if (head == null) {
            head = newNode;
            return;
        }
        LinkedNode temp = head;
        while (temp.next != null) temp = temp.next;
        temp.next = newNode;
    }

    // Insert at any position (1-based)
    void insertAtPos(int pos, int val) {
        LinkedNode newNode = new LinkedNode(val);
        if (pos == 1) {
            newNode.next = head;
            head = newNode;
            return;
        }
        LinkedNode temp = head;
        for (int i = 1; i < pos - 1 && temp != null; i++) temp = temp.next;
        if (temp == null) {
            System.out.println("Position out of bounds.");
            return;
        }
        newNode.next = temp.next;
        temp.next = newNode;
    }

    // Delete at position (1-based)
    void deleteAtPos(int pos) {
        if (head == null) {
            System.out.println("List empty.");
            return;
        }
        if (pos == 1) {
            head = head.next;
            return;
        }
        LinkedNode temp = head;
        LinkedNode prev = null;
        for (int i = 1; i < pos && temp != null; i++) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("Position out of bounds.");
            return;
        }
        prev.next = temp.next;
    }

    // Length of list
    int length() {
        int count = 0;
        LinkedNode temp = head;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        return count;
    }

    // Print list
    void display() {
        LinkedNode temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }
}

// Main class
public class _4a_LL_usingClass_Java {
    public static void main(String[] args) {
        BuildLinkedList list = new BuildLinkedList();
        list.createList();
        list.display();

        list.insertAtPos(2, 99);
        System.out.println("After insertion at position 2:");
        list.display();

        list.deleteAtPos(1);
        System.out.println("After deletion at position 1:");
        list.display();

        System.out.println("Length of list: " + list.length());
    }
}


/* 
^^^^^^^ how to run ^^^^^^^
javac filename.java
java filename (without .java)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\dsa - create from bsc> javac _4a_LL_usingClass_Java.java                                                                                                    
PS F:\coding nts\zzz codes m9\code_sublime_vscode_ltcd_chf_cfr\cdss\dsa - create from bsc> java _4a_LL_usingClass_Java      

Enter number of nodes: 4
Enter value: 10 20 30 40
Enter value: Enter value: Enter value: 10 -> 20 -> 30 -> 40 -> NULL
After insertion at position 2:
10 -> 99 -> 20 -> 30 -> 40 -> NULL
After deletion at position 1:
99 -> 20 -> 30 -> 40 -> NULL
Length of list: 4
 
*/
