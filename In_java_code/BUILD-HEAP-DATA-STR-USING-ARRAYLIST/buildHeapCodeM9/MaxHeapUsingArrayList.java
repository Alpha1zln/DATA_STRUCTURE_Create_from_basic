/**
 * MaxHeapUsingArrayList
 */
import java.util.ArrayList;

// MAX HEAP CREATION USING ARRAYLIST

public class MaxHeapUsingArrayList implements BuildMaxHeap {

    // create ArrayList
    private final ArrayList<Integer> maxHeapArrayList;

    // constructor
    public MaxHeapUsingArrayList() {
        maxHeapArrayList = new ArrayList<>();
    }

    // add element
    @Override
    public void insert(int elt) {

        maxHeapArrayList.add(elt);

        // Heapify Up
        heapifyUpHeap(maxHeapArrayList.size() - 1);
    }

    // remove element
    @Override
    public int remove() {

        if (maxHeapArrayList.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }

        int rootValue = maxHeapArrayList.get(0);

        int lastIndex = maxHeapArrayList.size() - 1;
        int lastValue = maxHeapArrayList.remove(lastIndex);

        // Heap had only one element
        if (maxHeapArrayList.isEmpty()) {
            return rootValue;
        }

        // Put last element at root
        maxHeapArrayList.set(0, lastValue);

        // Heapify Down
        heapifyDownHeap(0);

        return rootValue;
    }

    // O(1)
    @Override
    public int peek() {

        if (maxHeapArrayList.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }

        return maxHeapArrayList.get(0);
    }

    // print
    @Override
    public void print() {

        if (maxHeapArrayList.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }

        System.out.println(maxHeapArrayList);
    }

    // O(1)
    @Override
    public int size() {

        if (maxHeapArrayList.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }

        return maxHeapArrayList.size();
    }

    // O(1)
    @Override
    public boolean isEmpty() {

        return maxHeapArrayList.isEmpty();
    }

    // O(1)
    private void swap(int a, int b) {

        int valA = maxHeapArrayList.get(a);
        int valB = maxHeapArrayList.get(b);

        maxHeapArrayList.set(a, valB);
        maxHeapArrayList.set(b, valA);
    }

    // O(log n)
    private void heapifyUpHeap(int childIdx) {

        while (childIdx > 0) {

            int parIdx = (childIdx - 1) / 2;

            // Max Heap property satisfied
            if (maxHeapArrayList.get(parIdx)
                    >= maxHeapArrayList.get(childIdx)) {
                break;
            }

            // Parent < Child → violation
            swap(parIdx, childIdx);

            childIdx = parIdx;
        }
    }

    // O(log n)
    private void heapifyDownHeap(int index) {

        int size = maxHeapArrayList.size();

        while (true) {

            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            int largestIdx = index;

            // Check left child
            if (leftChild < size
                    && maxHeapArrayList.get(leftChild)
                    > maxHeapArrayList.get(largestIdx)) {

                largestIdx = leftChild;
            }

            // Check right child
            if (rightChild < size
                    && maxHeapArrayList.get(rightChild)
                    > maxHeapArrayList.get(largestIdx)) {

                largestIdx = rightChild;
            }

            // Heap property satisfied
            if (largestIdx == index) {
                break;
            }

            swap(index, largestIdx);

            index = largestIdx;
        }
    }
}
