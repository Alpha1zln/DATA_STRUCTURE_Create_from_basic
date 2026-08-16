import java.util.ArrayList;

    // BUILD_MAX_HEAP_USING_ARRAYLIST_m9
    // MIN HEAP CREATION USING ARRAYLIST 
    
    public class MinHeapUsingArrayList implements BuildMinHeap {
        // create AryLst
        private final ArrayList<Integer> minHeapArrayList;  
        
        // constructor
        public MinHeapUsingArrayList() {
            minHeapArrayList = new ArrayList<>();
        }

        // add elt
        @Override
        public void insert(int elt) {
            minHeapArrayList.add(elt);

            // if 1 size , then no need for heapifyUp
            // if(minHeapArrayList.size() == 1) {
            //     // System.out.println("Added elt : " + elt + "/n");
            //     return;
            // }
            heapifyUpHeap(minHeapArrayList.size()-1);
        }
        
        // remove elt 
        @Override
        public int remove() {
            if (minHeapArrayList.isEmpty()) {
                throw new IllegalStateException("Heap is empty");
            }
            int rootValue = minHeapArrayList.get(0);
            int lastIndex = minHeapArrayList.size()-1;   
            int lastValue = minHeapArrayList.remove(lastIndex);

            // Heap had only one element.
            if (minHeapArrayList.isEmpty())     return rootValue;
            
            minHeapArrayList.set(0, lastValue);
            heapifyDownHeap(0);

            return rootValue;
        }

        // O(1)
        @Override
        public int peek(){
            if(minHeapArrayList.size() == 0) 
                throw new IllegalStateException("Heap is empty");
            return minHeapArrayList.get(0);
        }
        
    
        // print 
        @Override
        public void print() {
            if(minHeapArrayList.size() == 0) 
                throw new IllegalStateException("Heap is empty");
            System.out.println(minHeapArrayList);
        }

        // O(1)
        @Override
        public int size() {
            if(minHeapArrayList.size() == 0) 
                throw new IllegalStateException("Heap is empty");
            return minHeapArrayList.size();
        }

        // O(1)
        @Override
        public boolean isEmpty(){
            return minHeapArrayList.size() == 0;
        }

        // O(1)
        public void swap(int a, int b) {
            int valA = minHeapArrayList.get(a), valB = minHeapArrayList.get(b);
            minHeapArrayList.set(a, valB);
            minHeapArrayList.set(b, valA);
        }

        // O(log n)
        public void heapifyUpHeap(int lastIdx) {
            int childIdx = lastIdx; int parIdx = (childIdx-1)/2;

            while( minHeapArrayList.get(parIdx) > minHeapArrayList.get(childIdx) ) {
                
                if( minHeapArrayList.get(parIdx) > minHeapArrayList.get(childIdx) ) {
                    swap(parIdx, childIdx);
                }
                childIdx=parIdx;
                parIdx = (childIdx-1)/2;
            }
        } // hpfyUp end

        // O(log n)
        public void heapifyDownHeap(int index) {
            int size = minHeapArrayList.size();

            while (true) {
                int leftChild = 2 * index + 1,  rightChild = 2 * index + 2;
                int smallestIdx = index;

                if (leftChild < size && minHeapArrayList.get(leftChild) < minHeapArrayList.get(smallestIdx)) {
                    smallestIdx = leftChild;               
                }
                if (rightChild < size && minHeapArrayList.get(rightChild) < minHeapArrayList.get(smallestIdx)) {
                    smallestIdx = rightChild;            
                }
                
                // Heap property is satisfied.
                if (smallestIdx == index) {
                    break;
                }

                swap(index, smallestIdx);
                index = smallestIdx;
            }
        }



    } // bldMinHeap end










// INTERVIEW QS

/*

*************** Interview-friendly answer 

*** throw() 
We use throw because minHeap.peekHeaping an empty heap is an invalid operation. 
minHeap.peekHeap() should return the root to the caller, not print it. 
System.out.println() is for displaying information, 
whereas throw communicates an exceptional/invalid state to the caller.














*/