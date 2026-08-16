    
    class Main {
    
    
    public static void main(String args[]) {

        //BuildMinHeap minHeap = new MinHeapUsingArrayList();

        HeapTypeMenu heapTypeMenu = new HeapTypeMenu();
        Heap heap = heapTypeMenu.selectHeap();

        HeapOperationsMenu menu = new HeapOperationsMenu(heap);

        menu.start();


        // minHeap.insertEltIntoHeap(50);
        // minHeap.insertEltIntoHeap(30);
        // System.out.println("Minimum: " + minHeap.peekHeap());    
        // minHeap.printHeap();

        // minHeap.insertEltIntoHeap(10);
        // System.out.println("Minimum: " + minHeap.peekHeap());   
        // minHeap.printHeap();

        // minHeap.insertEltIntoHeap(70);
        // System.out.println("Minimum: " + minHeap.peekHeap());    
        // minHeap.printHeap();
        
        // minHeap.removeEltFromHeap();
        // System.out.println("Minimum: " + minHeap.peekHeap());    
        // minHeap.printHeap();

        // minHeap.insertEltIntoHeap(20);
        // minHeap.insertEltIntoHeap(50);
        // System.out.println("Minimum: " + minHeap.peekHeap());    
        // minHeap.printHeap();

        // minHeap.removeEltFromHeap();
        // System.out.println("Minimum: " + minHeap.peekHeap());    
        // minHeap.printHeap();

        // minHeap.insertEltIntoHeap(7);
        // System.out.println("Minimum: " + minHeap.peekHeap());    
        // minHeap.printHeap();

    } // main class end  


}



/*

OP ----------------- MAX HEAP
========== SELECT HEAP ==========
1. Min Heap     2. Max Heap
Enter choice: 2

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 1
Enter element: 10
Element: 10 added successfully.
[10]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 1
Enter element: 56
Element: 56 added successfully.
[56, 10]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 1
Enter element: 5
Element: 5 added successfully.
[56, 10, 5]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 1
Enter element: 88
Element: 88 added successfully.
[88, 56, 5, 10]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 1
Enter element: 20
Element: 20 added successfully.
[88, 56, 5, 10, 20]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 1
Enter element: 40
Element: 40 added successfully.
[88, 56, 40, 10, 20, 5]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 2
Minimum element: 88
[88, 56, 40, 10, 20, 5]


============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 1
Enter element: 60
Element: 60 added successfully.
[88, 56, 60, 10, 20, 5, 40]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 3
Removed element: 88
[60, 56, 40, 10, 20, 5]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 5
Heap size: 6
[60, 56, 40, 10, 20, 5]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 6
Heap is not empty.

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 4
[60, 56, 40, 10, 20, 5]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 1
Enter element: 52
Element: 52 added successfully.
[60, 56, 52, 10, 20, 5, 40]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 3
Removed element: 60
[56, 40, 52, 10, 20, 5]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 3
Removed element: 56
[52, 40, 5, 10, 20]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 3
Removed element: 52
[40, 20, 5, 10]

============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 2
Minimum element: 40
[40, 20, 5, 10]


============  HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit
Enter your choice: 7
Exiting...










op-------

============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 1
Enter element: 70
Element: 70 added successfully.
[70]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 1
Enter element: 50
Element: 50 added successfully.
[50, 70]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 1
Enter element: 60
Element: 60 added successfully.
[50, 70, 60]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 2
Minimum element: 50
[50, 70, 60]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 5
Heap size: 3
[50, 70, 60]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 6
Heap is not empty.

============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 4
[50, 70, 60]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 1
Enter element: 5
Element: 5 added successfully.
[5, 50, 60, 70]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 1
Enter element: 40
Element: 40 added successfully.
[5, 40, 60, 70, 50]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 1 
Enter element: 55
Element: 55 added successfully.
[5, 40, 55, 70, 50, 60]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 1
Enter element: 20
Element: 20 added successfully.
[5, 40, 20, 70, 50, 60, 55]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 3
Removed element: 5
[20, 40, 55, 70, 50, 60]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 3
Removed element: 20
[40, 50, 55, 70, 60]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 1
Enter element: 42
Element: 42 added successfully.
[40, 50, 42, 70, 60, 55]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 3
Removed element: 40
[42, 50, 55, 70, 60]


============ MIN HEAP ==================
1. Add Element       2. Peek Element
3. Remove Element    4. Print Heap
5. Size              6. Is Empty     7. Exit

Enter your choice: 7
Exiting...

*/