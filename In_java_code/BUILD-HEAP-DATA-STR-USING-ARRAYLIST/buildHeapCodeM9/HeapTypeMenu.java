import java.util.Scanner;

public class HeapTypeMenu {

    Scanner scan; 

    public HeapTypeMenu() {
        scan = new Scanner(System.in);
    }
    
    public Heap selectHeap() {

    
        System.out.println("========== SELECT HEAP ==========");
        System.out.println("1. Min Heap     2. Max Heap");
        //System.out.println("2. Max Heap");
        
        System.out.print("Enter choice: ");
        int choice = scan.nextInt();

        switch (choice) {

            case 1:
                BuildMinHeap minHeap = new MinHeapUsingArrayList();
                return minHeap;

            case 2:
                BuildMaxHeap maxHeap = new MaxHeapUsingArrayList();
                return maxHeap;

            default:
                throw new IllegalArgumentException(
                    "Invalid choice"
                );
        }
    }
}