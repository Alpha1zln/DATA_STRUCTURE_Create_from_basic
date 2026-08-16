/**
 * HeapMenu
 */
import java.util.Scanner;

public class HeapOperationsMenu {

    private final Heap heap;
    private final Scanner sc;

    public HeapOperationsMenu(Heap heap) {
        this.heap = heap;
        this.sc = new Scanner(System.in);
    }

    public void start() {

        while (true) {

            System.out.println("\n============  HEAP ==================");
            System.out.println("1. Add Element       2. Peek Element");
            //System.out.println("");
            System.out.println("3. Remove Element    4. Print Heap");
            //System.out.println("");
            System.out.println("5. Size              6. Is Empty     7. Exit");
            //System.out.println("");
            //System.out.println("");

            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter element: ");
                    int element = sc.nextInt();
                    heap.insert(element);
                    System.out.println("Element: " + element + " added successfully.");
                    heap.print();   //System.out.println("");
                    break;

                case 2:
                    try {
                        System.out.println("Minimum element: " + heap.peek() );
                        heap.print();   System.out.println("");
                    } catch (IllegalStateException e) {
                        System.out.println(e.getMessage());
                    }
                    break;

                case 3:
                    try {
                        int removed = heap.remove();
                        System.out.println("Removed element: " + removed);
                        heap.print(); // System.out.println("");
                    } catch (IllegalStateException e) {
                        System.out.println(e.getMessage());
                    }
                    break;

                case 4:
                    heap.print(); // System.out.println("");
                    break;

                case 5:
                    System.out.println("Heap size: " + heap.size());
                    heap.print(); // System.out.println("");
                    break;

                case 6:
                    System.out.println(
                        heap.isEmpty()
                            ? "Heap is empty."
                            : "Heap is not empty."
                    );
                    break;

                case 7:
                    System.out.println("Exiting...");
                    return;

                default:
                    System.out.println(
                        "Invalid choice. Please try again."
                    );
            }
        }
    }
}
