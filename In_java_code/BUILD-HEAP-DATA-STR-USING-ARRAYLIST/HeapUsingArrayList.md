# Heap Using ArrayList

## 1. What is a Heap?

A **Heap** is a **complete binary tree** that follows the **heap-order property**.

There are two main types:

### Min Heap
The parent is always **smaller than or equal to** its children.

```text
              10
            /    \
          20      15
         /  \    /  \
       30   40  25   50
```

For every node:

```text
parent <= children
```

Therefore, the **minimum element is always at the root**.

### Max Heap
The parent is always **greater than or equal to** its children.

```text
              50
            /    \
          40      45
         /  \    /  \
       20   30  35   10
```

For every node:

```text
parent >= children
```

Therefore, the **maximum element is always at the root**.

---

# 2. Two Important Properties of a Heap

A heap has **two separate properties**.

## Property 1: Complete Binary Tree

All levels are completely filled except possibly the last level.

The last level is filled **from left to right**.

Example:

```text
                 10
              /      \
            20        30
           /  \      /  \
         40   50    60   70
        /
       80
```

This is a complete binary tree.

This property is important because it allows us to store the heap efficiently in an **array / ArrayList**, without storing explicit left/right pointers.

---

## Property 2: Heap Order Property

### Min Heap

```text
parent <= child
```

Example:

```text
        10
       /  \
     20    15
```

Both children are greater than the parent.

### Max Heap

```text
parent >= child
```

Example:

```text
        50
       /  \
     40    45
```

Both children are smaller than the parent.

---

# 3. Heap Structure Using ArrayList

A heap can be represented using an `ArrayList<Integer>`.

Suppose we have this Min Heap:

```text
                 10
              /      \
            20        15
           /  \      /  \
         30   40    25   50
```

Store it level by level:

```text
ArrayList:

index:    0   1   2   3   4   5   6
          -----------------------------
value:   10  20  15  30  40  25  50
```

The tree and ArrayList correspond as follows:

```text
                    10 (0)
                  /        \
             20 (1)       15 (2)
              /   \        /   \
        30 (3) 40 (4) 25 (5) 50 (6)
```

Notice that **no left/right pointers are required**.

---

# 4. Parent and Child Index Formulas

For a node at index `i`:

### Parent

```java
parent = (i - 1) / 2
```

### Left Child

```java
left = 2 * i + 1
```

### Right Child

```java
right = 2 * i + 2
```

These formulas work because the heap is a **complete binary tree**.

Example:

```text
Index 1 = 20

parent:
(1 - 1) / 2 = 0

left child:
2 * 1 + 1 = 3

right child:
2 * 1 + 2 = 4
```

Therefore:

```text
             10 (0)
            /
         20 (1)
        /     \
     30 (3)  40 (4)
```

---

# 5. Why ArrayList Works So Well for a Heap

A normal binary tree usually needs something like:

```java
class Node {
    int data;
    Node left;
    Node right;
}
```

But a heap does **not** need this.

Because the tree is complete, its structure is already determined by the index.

So:

```text
Tree structure
      ↓
determined by array indexes
      ↓
no explicit left/right pointers required
```

This gives:

- less memory overhead
- simple implementation
- direct access to parent/children
- excellent cache locality compared with pointer-based trees

---

# 6. Main Heap Operations

For a heap containing `n` elements:

| Operation | Min Heap | Max Heap | Time |
|---|---:|---:|---:|
| Get root | Minimum | Maximum | `O(1)` |
| Insert | Add + Heapify Up | Add + Heapify Up | `O(log n)` |
| Remove root | Remove + Heapify Down | Remove + Heapify Down | `O(log n)` |
| Peek root | Minimum | Maximum | `O(1)` |
| Build Heap from `n` elements | Heapify | Heapify | `O(n)` |
| Search arbitrary value | `O(n)` | `O(n)` | `O(n)` |

### Space Complexity

The heap itself stores `n` elements:

```text
Space = O(n)
```

If we perform an operation such as heapify-up or heapify-down, the iterative implementation uses:

```text
Auxiliary Space = O(1)
```

---

# 7. Why Insert is O(log n)

Suppose we insert an element into a heap.

Because the heap must remain a **complete binary tree**, the new element is first placed at the end.

Then it may have to move upward.

Example:

```text
        10
       /  \
     20    15
    /
   30
```

Insert `5`:

```text
        10
       /  \
     20    15
    /  \
   30   5
```

Now compare `5` with its parent:

```text
5 < 20
```

Swap:

```text
        10
       /  \
      5    15
     / \
   30  20
```

Compare again:

```text
5 < 10
```

Swap:

```text
         5
       /   \
     10     15
    / \
   30  20
```

The element moves only along the height of the tree.

For a complete binary tree:

```text
height = O(log n)
```

Therefore:

```text
Insert = O(log n)
```

---

# 8. Heapify Up

**Heapify Up** is used after insertion.

Steps:

```text
1. Add the new element at the end.
2. Find its parent.
3. Compare parent and child.
4. If heap property is violated, swap.
5. Continue upward.
6. Stop when the heap property is satisfied.
```

For Min Heap:

```text
if child < parent
    swap
```

For Max Heap:

```text
if child > parent
    swap
```

---

# 9. Why Remove Root is O(log n)

The root is removed.

But simply deleting the root would break the complete-tree structure.

Therefore:

```text
1. Save root.
2. Move last element to root.
3. Remove last element.
4. Heapify Down.
```

Example:

```text
        10
       /  \
     20    15
    /  \
   30  40
```

Remove `10`.

Move last element `40` to root:

```text
        40
       /  \
     20    15
    /
   30
```

Now heapify down:

```text
40 > 15
```

Swap:

```text
        15
       /  \
     20    40
    /
   30
```

Then:

```text
40 > 30
```

Swap:

```text
        15
       /  \
     20    30
    /
   40
```

The element moves at most one root-to-leaf path.

Therefore:

```text
Remove root = O(log n)
```

---

# 10. Heapify Down

**Heapify Down** is generally used after removing the root.

For Min Heap:

```text
1. Compare node with left child.
2. Compare node with right child.
3. Find the smaller child.
4. If node > smaller child, swap.
5. Continue downward.
```

For Max Heap:

```text
1. Compare node with left child.
2. Compare node with right child.
3. Find the larger child.
4. If node < larger child, swap.
5. Continue downward.
```

---

# 11. Creating a Heap

There are two common ways to create a heap.

## Method 1: Insert Elements One by One

Start with an empty heap:

```text
[]
```

Insert each element using the normal `insert()` operation.

For example:

```text
10
20
5
30
15
```

Every insertion performs heapify-up if necessary.

For `n` elements:

```text
Each insertion = O(log n)
Total = O(n log n)
```

### Space

The resulting heap stores all `n` elements:

```text
O(n)
```

Auxiliary space for the iterative insertion logic:

```text
O(1)
```

---

# 12. Method 2: Build Heap Using Bottom-Up Heapify

If all elements are already available in an array/list, we can build the heap more efficiently.

Example:

```text
[40, 10, 30, 50, 20, 15]
```

Treat it as a complete binary tree and start heapifying from the **last non-leaf node**.

The last non-leaf node is:

```text
(n / 2) - 1
```

For each node, perform heapify-down.

```text
for (i = n / 2 - 1; i >= 0; i--)
    heapifyDown(i);
```

### Time Complexity

Although one `heapifyDown()` can take `O(log n)`, doing it for every node does **not** make build-heap `O(n log n)`.

The reason is that most nodes are near the bottom and can move only a small distance.

The total work is:

```text
O(n)
```

Therefore:

```text
Bottom-up Build Heap = O(n)
```

This is an important interview point.

---

# 13. `O(n)` vs `O(n log n)` Heap Creation

| Method | Approach | Time |
|---|---|---:|
| Insert one by one | Heapify Up | `O(n log n)` |
| Bottom-up build heap | Heapify Down | `O(n)` |

So, if the complete input is already available, **bottom-up heap construction is preferred**.

---

# 14. Min Heap Implementation Using ArrayList

The implementation below uses:

```java
ArrayList<Integer>
```

and implements:

- `insert()`
- `peek()`
- `remove()`
- `heapifyUp()`
- `heapifyDown()`
- `size()`
- `isEmpty()`
- `buildHeap()`

```java
import java.util.ArrayList;
import java.util.List;

public class MinHeap {

    private final List<Integer> heap;

    public MinHeap() {
        heap = new ArrayList<>();
    }

    // O(log n)
    public void insert(int value) {
        heap.add(value);
        heapifyUp(heap.size() - 1);
    }

    // O(1)
    public int peek() {
        if (heap.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        return heap.get(0);
    }

    // O(log n)
    public int remove() {
        if (heap.isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }

        int root = heap.get(0);

        int lastIndex = heap.size() - 1;
        int lastValue = heap.remove(lastIndex);

        // Heap had only one element.
        if (heap.isEmpty()) {
            return root;
        }

        heap.set(0, lastValue);
        heapifyDown(0);

        return root;
    }

    // O(log n)
    private void heapifyUp(int index) {

        while (index > 0) {

            int parentIndex = (index - 1) / 2;

            // Min Heap property is satisfied.
            if (heap.get(parentIndex) <= heap.get(index)) {
                break;
            }

            swap(parentIndex, index);

            index = parentIndex;
        }
    }

    // O(log n)
    private void heapifyDown(int index) {

        int size = heap.size();

        while (true) {

            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            int smallest = index;

            if (leftChild < size &&
                heap.get(leftChild) < heap.get(smallest)) {

                smallest = leftChild;
            }

            if (rightChild < size &&
                heap.get(rightChild) < heap.get(smallest)) {

                smallest = rightChild;
            }

            // Heap property is satisfied.
            if (smallest == index) {
                break;
            }

            swap(index, smallest);

            index = smallest;
        }
    }

    private void swap(int i, int j) {

        int temp = heap.get(i);

        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    // O(1)
    public int size() {
        return heap.size();
    }

    // O(1)
    public boolean isEmpty() {
        return heap.isEmpty();
    }

    // O(n)
    public void buildHeap(List<Integer> values) {

        heap.clear();
        heap.addAll(values);

        int lastNonLeaf = heap.size() / 2 - 1;

        for (int i = lastNonLeaf; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    public void printHeap() {
        System.out.println(heap);
    }

    public static void main(String[] args) {

        MinHeap minHeap = new MinHeap();

        minHeap.insert(40);
        minHeap.insert(20);
        minHeap.insert(10);
        minHeap.insert(30);
        minHeap.insert(5);

        minHeap.printHeap();

        System.out.println("Minimum: " + minHeap.peek());

        System.out.println("Removed: " + minHeap.remove());

        minHeap.printHeap();

        minHeap.buildHeap(
            List.of(40, 10, 30, 50, 20, 15)
        );

        minHeap.printHeap();
    }
}
```

---

# 15. Min Heap Code — Operation Complexity

| Method | Time | Auxiliary Space |
|---|---:|---:|
| `insert()` | `O(log n)` | `O(1)` |
| `peek()` | `O(1)` | `O(1)` |
| `remove()` | `O(log n)` | `O(1)` |
| `heapifyUp()` | `O(log n)` | `O(1)` |
| `heapifyDown()` | `O(log n)` | `O(1)` |
| `buildHeap()` | `O(n)` | `O(1)` auxiliary* |
| `size()` | `O(1)` | `O(1)` |
| `isEmpty()` | `O(1)` | `O(1)` |

\* `buildHeap()` stores the input elements in the heap, so the heap itself occupies `O(n)` space. The heapification process is iterative and uses `O(1)` auxiliary space.

---

# 16. How to Convert Min Heap to Max Heap

The **structure does not change**.

The following remain exactly the same:

```java
parent = (i - 1) / 2;

leftChild = 2 * i + 1;

rightChild = 2 * i + 2;
```

Also unchanged:

- `ArrayList` representation
- complete binary tree property
- insertion position
- removal procedure
- heapify-up mechanism
- heapify-down mechanism
- build-heap algorithm
- complexity

Only the **comparison direction** changes.

---

# 17. Changes Required for Max Heap

## Change 1: `heapifyUp()`

### Min Heap

```java
if (heap.get(parentIndex) <= heap.get(index)) {
    break;
}
```

Meaning:

```text
parent <= child
```

If parent is greater, swap.

### Max Heap

Use:

```java
if (heap.get(parentIndex) >= heap.get(index)) {
    break;
}
```

Meaning:

```text
parent >= child
```

If parent is smaller, swap.

---

## Change 2: `heapifyDown()`

### Min Heap

Find the **smallest** child:

```java
int smallest = index;

if (leftChild < size &&
    heap.get(leftChild) < heap.get(smallest)) {

    smallest = leftChild;
}

if (rightChild < size &&
    heap.get(rightChild) < heap.get(smallest)) {

    smallest = rightChild;
}
```

### Max Heap

Find the **largest** child:

```java
int largest = index;

if (leftChild < size &&
    heap.get(leftChild) > heap.get(largest)) {

    largest = leftChild;
}

if (rightChild < size &&
    heap.get(rightChild) > heap.get(largest)) {

    largest = rightChild;
}
```

---

# 18. Max Heap — What Changes in the Code?

The Min Heap:

```java
private void heapifyUp(int index) {

    while (index > 0) {

        int parentIndex = (index - 1) / 2;

        if (heap.get(parentIndex) <= heap.get(index)) {
            break;
        }

        swap(parentIndex, index);

        index = parentIndex;
    }
}
```

becomes:

```java
private void heapifyUp(int index) {

    while (index > 0) {

        int parentIndex = (index - 1) / 2;

        if (heap.get(parentIndex) >= heap.get(index)) {
            break;
        }

        swap(parentIndex, index);

        index = parentIndex;
    }
}
```

And Min Heap:

```java
private void heapifyDown(int index) {

    int size = heap.size();

    while (true) {

        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        int smallest = index;

        if (leftChild < size &&
            heap.get(leftChild) < heap.get(smallest)) {

            smallest = leftChild;
        }

        if (rightChild < size &&
            heap.get(rightChild) < heap.get(smallest)) {

            smallest = rightChild;
        }

        if (smallest == index) {
            break;
        }

        swap(index, smallest);

        index = smallest;
    }
}
```

becomes:

```java
private void heapifyDown(int index) {

    int size = heap.size();

    while (true) {

        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        int largest = index;

        if (leftChild < size &&
            heap.get(leftChild) > heap.get(largest)) {

            largest = leftChild;
        }

        if (rightChild < size &&
            heap.get(rightChild) > heap.get(largest)) {

            largest = rightChild;
        }

        if (largest == index) {
            break;
        }

        swap(index, largest);

        index = largest;
    }
}
```

So the key idea is:

```text
                 MIN HEAP          MAX HEAP
------------------------------------------------
Parent rule      parent <= child    parent >= child
Root             minimum            maximum
Heapify Up       smaller moves up   larger moves up
Heapify Down     smaller child      larger child
```

---

# 19. Important Interview Point

A Heap and a Priority Queue are **not exactly the same thing**.

A **heap is a data structure**.

A **priority queue is an abstract data type (ADT)** that says:

> Elements have priorities, and the highest/lowest-priority element should be accessible/removed first.

A heap is one of the most common ways to **implement** a priority queue.

Therefore:

```text
Priority Queue
      ↓
   can be implemented using
      ↓
     Heap
```

Because of this, their common priority-queue operations often have the same asymptotic complexity when the priority queue is implemented using a binary heap:

```text
insert       O(log n)
peek         O(1)
remove       O(log n)
```

But conceptually:

```text
Heap ≠ Priority Queue
```

They should not be treated as identical concepts.

---

# 20. Heap vs Priority Queue — Complexity View

For a binary-heap-based Priority Queue:

| Operation | Binary Heap | Heap-based Priority Queue |
|---|---:|---:|
| Insert | `O(log n)` | `O(log n)` |
| Peek min/max | `O(1)` | `O(1)` |
| Remove min/max | `O(log n)` | `O(log n)` |
| Build from all elements | `O(n)` | Depends on implementation/API |
| Search arbitrary element | `O(n)` | Usually not the main operation |

So the **same complexity does not mean they are the same data structure**.

---

# 21. Final Mental Model

Remember Heap in this order:

```text
                    HEAP
                     |
          -------------------------
          |                       |
      Complete BT            Heap Order
          |                       |
    ArrayList/Array        Min / Max rule
          |
    Index formulas
          |
   -------------------
   |                 |
Insert              Remove
   |                 |
Heapify Up        Heapify Down
   |                 |
 O(log n)           O(log n)
```

And for creation:

```text
All elements available
        |
        +----------------------+
        |                      |
 Insert one-by-one       Bottom-up Build
        |                      |
    O(n log n)               O(n)
```

The most important formulas to remember:

```java
parent = (i - 1) / 2;

leftChild = 2 * i + 1;

rightChild = 2 * i + 2;
```

And the most important difference:

```text
MIN HEAP:
smallest element at root
smaller values move upward

MAX HEAP:
largest element at root
larger values move upward
```


```
###  INTERVIEW QUESTIONS

```
Q1. Why is insertion in a heap O(log n)?
Answer
A new element is first inserted at the end to preserve the complete binary tree property.
Then it may move upward using heapify-up.
The maximum number of levels it can travel is the height of the heap.
A complete binary tree has height:
O(log n)
Therefore:
Insertion = O(log n)
```

```
Q2. Why is peek() O(1) in a heap?
Answer
In a Min-Heap, the minimum element is always at the root.
In a Max-Heap, the maximum element is always at the root.
The root is stored at:
index 0
Therefore we directly access it.
peek = O(1)
```

```
Q3. Why is Build Heap O(n), not O(n log n)?
Answer
If we insert elements one by one:
n insertions × O(log n)
= O(n log n)
But bottom-up heap construction is different.
We start from the last non-leaf node and perform heapify-down.
Most nodes are near the leaves and can move only a small distance.
The total work across all nodes sums to:
O(n)
Therefore:
Bottom-up Build Heap = O(n)
This is a favorite interview question.
```


```
Q4. Can we search an arbitrary element in O(log n) in a heap?
Answer
No.
A heap only guarantees:
parent ≤ children       // Min-Heap
parent ≥ children       // Max-Heap
There is no ordering between siblings or arbitrary branches.
For example:
       1
      / \
     50  10
    / \
   60 70
If we search for 70, we can't decide which subtree to discard based on the heap property.
Therefore we may need to inspect every element.
Search = O(n)
```

```
Q5. What is the difference between Heap and Priority Queue?
Answer
A Priority Queue is an ADT that defines behavior:
The element with the highest priority should be accessed/removed first.
A Heap is a data structure that can efficiently implement that behavior.

For example:
Min Priority Queue
       ↓
    Min-Heap
Typical complexities using a binary heap:
peek → O(1)
insert → O(log n)
remove → O(log n)
So the clean interview answer is:
"Priority Queue defines what we want; Heap is one of the most efficient ways to implement it."
```


```

### 🔥 Final Interview Cheat Sheet
Remember this table:

#### Operation - Binary Heap
```
peek()                  O(1)
insert()                O(log n)
extractMin/Max()        O(log n)
Delete root             O(log n)
Search arbitrary        O(n)
Delete arbitrary value  O(n)
Build by insertion      O(n log n)
Build bottom-up         O(n)
Heap height             O(log n)

Auxiliary SC for iterative heap O(1)
```


```

#### And the 5 formulas you should know cold:

parent(i) = (i - 1) / 2

left(i)   = 2i + 1

right(i)  = 2i + 2

last non-leaf = n/2 - 1

heap height = O(log n)


```

#### One final mental model

```
                HEAP
                 │
         Complete Binary Tree
                 │
            stored in Array
                 │
      ┌──────────┴──────────┐
      │                     │
   Min-Heap              Max-Heap
      │                     │
   minimum               maximum
   at root                at root
      │                     │
      └──────────┬──────────┘
                 ↓
          PRIORITY QUEUE
                 │
       offer → O(log n)
       peek  → O(1)
       poll  → O(log n)

```
```
```
done - crtd by alpha1zln wd chtGpt
```
````