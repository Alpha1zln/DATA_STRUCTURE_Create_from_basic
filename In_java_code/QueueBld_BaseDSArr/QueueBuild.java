
class QueueBld_BaseDS {
    private int[] arr;
    private int front, rear, size, capacity;

    public QueueBld_BaseDS(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    public void enqueue(int val) {
        if (size == capacity) throw new RuntimeException("Queue full");
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    public int dequeue() {
        if (size == 0) throw new RuntimeException("Queue empty");
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        System.out.print("Dequeue elt : ");
        return val;
    }

    public int peek() {
        if (size == 0) throw new RuntimeException("Queue empty");
        System.out.print("Front elt : ");
        return arr[front];
    }

    public boolean isEmpty() { System.out.print("Is empty qu : ");
        return size == 0; 
    }

    public int currSize() { System.out.print("Curr Size : ");
        return size; 
    }

    public void print() { 
        System.out.println("Elts in queue :: ");
        if(size == 0) {System.out.println("empty"); return;}
        for(int i=front; i<= rear; i++) {
            System.out.print(arr[i] + " ");   
        }
         System.out.println("");
    }

}


public class QueueBuild {

    // main method (psvm)
    public static void main(String[] args) {
        QueueBld_BaseDS q = new QueueBld_BaseDS(5);
        q.enqueue(10);        q.enqueue(20);
        q.enqueue(30);        q.enqueue(40);
        System.out.println(q.currSize());    // 4
        
        q.print();
        System.out.println(q.isEmpty());    // f        
        System.out.println(q.peek());    // 10
        System.out.println(q.dequeue()); // 10
        System.out.println(q.peek());    // 20
        System.out.println(q.currSize());    // 3
        
    }
}


/*
op ---

Curr Size : 4
Elts in queue :: 
10 20 30 40 
Is empty qu : false
Front elt : 10
Dequeue elt : 10
Front elt : 20
Curr Size : 3
*/


/*
Base DS used: Array

Time Complexity: enqueue/dequeue O(1)

Space Complexity: O(n)
*/