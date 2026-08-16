# Priority Queue Using Heap

## 1. Heap → Priority Queue Relationship

```text
                    DATA STRUCTURES / ADTs
                           |
              ---------------------------
              |                         |
          Concrete DS                  ADT
              |                         |
            Heap                  Priority Queue
              |
       can be used to implement
              |
              v
       Priority Queue
```

A **Heap** is a concrete data structure.

A **Priority Queue** is an **Abstract Data Type (ADT)**.

A binary heap is one of the most common and efficient ways to implement a Priority Queue.

---

## 2. Origin / Evolution: Heap and Priority Queue

```text
                         PROBLEM
                           |
                           v
              Need to process elements
              according to their priority
                           |
                           v
                    PRIORITY QUEUE
                         (ADT)
                           |
             "Give me the highest/
              lowest priority item"
                           |
                           v
              Need an efficient DS
                    to implement it
                           |
                           v
                         HEAP
                           |
              -----------------------
              |                     |
          Min Heap              Max Heap
              |                     |
       smallest first          largest first
              |                     |
              +----------+----------+
                         |
                         v
                Efficient PQ
                implementation
```

The important conceptual distinction is:

```text
Priority Queue = WHAT we want
Heap           = HOW we can implement it
```

---

## 3. What is a Priority Queue?

A **Priority Queue** is an ADT in which elements are processed according to priority rather than simply according to insertion order.

Normal Queue:

```text
FIFO
First In → First Out
```

Priority Queue:

```text
Priority determines removal
```

Example:

```text
Task       Priority
-------------------
A             5
B             2
C             8
D             1
```

If smaller number means higher priority:

```text
D → B → A → C
```

---

## 4. Why Do We Need a Priority Queue?

Consider an emergency room:

```text
Patient A → normal
Patient B → critical
Patient C → normal
Patient D → emergency
```

A normal Queue processes:

```text
A → B → C → D
```

A Priority Queue can process:

```text
D → B → A → C
```

Other applications:

- CPU scheduling
- Dijkstra's shortest path
- Prim's MST
- Network packet scheduling
- Event simulation
- Job scheduling
- Task scheduling

---

## 5. Priority Queue Operations

Common operations:

```text
insert / add / offer
peek
remove / poll
size
isEmpty
```

For a Min Priority Queue:

```text
peek()   → minimum
remove() → minimum
```

For a Max Priority Queue:

```text
peek()   → maximum
remove() → maximum
```

---

## 6. Min Priority Queue vs Max Priority Queue

### Min Priority Queue

Smallest key/value has highest priority.

```text
             5
           /            10     8
        /        20   15
```

```text
peek() → 5
remove() → 5
```

### Max Priority Queue

Largest key/value has highest priority.

```text
             50
           /             30      40
        /        10   20
```

```text
peek() → 50
remove() → 50
```

---

## 7. Priority Queue Does NOT Necessarily Mean Min Heap

A Priority Queue can be implemented using:

```text
Unsorted Array/List
Sorted Array/List
Linked List
Heap
Balanced BST
```

A binary heap is usually preferred because it gives an excellent balance:

```text
peek       O(1)
insert     O(log n)
remove     O(log n)
```

---

## 8. Heap vs Priority Queue

| Heap | Priority Queue |
|---|---|
| Concrete data structure | Abstract Data Type |
| Usually a complete binary tree | Defines priority-based behavior |
| Has heap-order property | Does not specify one particular implementation |
| Can be stored using Array/ArrayList | Can use heap, BST, list, etc. |
| Min Heap / Max Heap | Min PQ / Max PQ |
| Heap can implement a PQ | PQ can be implemented using a heap |

Best interview answer:

> **A heap is a data structure, while a priority queue is an abstract data type. A binary heap is commonly used to implement a priority queue efficiently.**

---

## 9. Heap and PQ Are Not Synonyms

Think:

```text
Stack → ADT
Array / Linked List → possible implementations

Queue → ADT
Array / Linked List → possible implementations

Priority Queue → ADT
Heap / BST / List → possible implementations

Heap → concrete data structure
```

The simplest distinction:

```text
PQ = WHAT
Heap = HOW
```

---

## 10. Why Heap is a Good Implementation for PQ

Suppose we need:

```text
Insert
Peek minimum
Remove minimum
```

A binary Min Heap provides:

```text
Insert        O(log n)
Peek minimum  O(1)
Remove min    O(log n)
```

The heap keeps the highest/lowest priority element at the root.

---

## 11. Implementing Priority Queue Using Binary Heap

```text
Min Priority Queue
       |
       v
    Min Heap
       |
       v
smallest element at root
```

```text
Max Priority Queue
       |
       v
    Max Heap
       |
       v
largest element at root
```

The Heap implementation from:

```text
HeapUsingArrayList.md
```

can be reused.

For Min PQ:

```text
MinHeap.java
```

For Max PQ:

```text
MaxHeap.java
```

There is no need to duplicate the heap implementation inside the Priority Queue file.

---

## 12. Min Priority Queue Using Existing MinHeap

```java
public class MinPriorityQueue {

    private final MinHeap heap;

    public MinPriorityQueue() {
        heap = new MinHeap();
    }

    // O(log n)
    public void add(int value) {
        heap.insert(value);
    }

    // O(1)
    public int peek() {
        return heap.peek();
    }

    // O(log n)
    public int remove() {
        return heap.remove();
    }

    // O(1)
    public int size() {
        return heap.size();
    }

    // O(1)
    public boolean isEmpty() {
        return heap.isEmpty();
    }
}
```

The important design idea:

```text
Priority Queue
      |
      v
   delegates to
      |
      v
    MinHeap
```

The PQ does not need to reinvent:

```text
heapifyUp()
heapifyDown()
swap()
```

---

## 13. Heap Code Used by Priority Queue

The complete heap implementation is already present in:

```text
HeapUsingArrayList.md
```

Use:

```text
MinHeap.java
```

for a Min Priority Queue.

Use:

```text
MaxHeap.java
```

for a Max Priority Queue.

Conceptually:

```text
Min PQ → MinHeap.java
Max PQ → MaxHeap.java
```

---

## 14. Complexity of Heap-Based Priority Queue

| PQ Operation | Heap Operation | Time |
|---|---|---:|
| `add()` | `insert()` | `O(log n)` |
| `peek()` | `peek()` | `O(1)` |
| `remove()` | `remove()` | `O(log n)` |
| `size()` | `size()` | `O(1)` |
| `isEmpty()` | `isEmpty()` | `O(1)` |

Space:

```text
Heap elements = O(n)
Overall PQ space = O(n)
```

The wrapper object itself only keeps a reference to the heap, so its additional space is `O(1)`.

---

## 15. Why `peek()` is O(1)

In a Min Priority Queue:

```text
                 5
              /                 10       8
           /  \     /          20   15   12  30
```

The minimum is guaranteed at:

```text
index 0
```

Therefore:

```java
heap.peek();
```

returns the root directly.

```text
peek = O(1)
```

---

## 16. Why `remove()` is O(log n)

After removing the root:

```text
1. Remove root.
2. Move last element to root.
3. Heapify down.
```

The replacement element can travel at most the height of the heap.

For a binary heap:

```text
height = O(log n)
```

Therefore:

```text
remove = O(log n)
```

---

## 17. Why `add()` is O(log n)

When adding:

```text
1. Add element at the end.
2. Compare with parent.
3. Swap if priority rule is violated.
4. Continue upward.
```

This is heapify-up.

Maximum movement:

```text
height = O(log n)
```

Therefore:

```text
add = O(log n)
```

---

## 18. Priority Queue with Element + Priority

Real applications often store both an object and its priority.

```java
class Task {

    String name;
    int priority;

    Task(String name, int priority) {
        this.name = name;
        this.priority = priority;
    }
}
```

The heap comparison is based on:

```java
task.priority
```

rather than the task name.

Example:

```text
Task       Priority
-------------------
Payment       1
Login         2
Email         3
Report        5
```

Min Priority Queue:

```text
             Payment(1)
             /                Login(2)     Email(3)
```

So:

```text
peek() → Payment(1)
```

---

## 19. Java's `PriorityQueue`

Java provides:

```java
import java.util.PriorityQueue;
```

By default:

```java
PriorityQueue<Integer> pq = new PriorityQueue<>();
```

behaves as a **Min Priority Queue**.       // VVIP

Example:

```java
PriorityQueue<Integer> pq = new PriorityQueue<>();

pq.add(30);
pq.add(10);
pq.add(20);

System.out.println(pq.peek());
```

Output:

```text
10
```

Remove:

```java
System.out.println(pq.poll());
```

Output:

```text
10
```

---

## 20. Java Max Priority Queue

Use:

```java
PriorityQueue<Integer> pq =
    new PriorityQueue<>(Collections.reverseOrder());     // Imp
```

Now:

```java
pq.add(30);
pq.add(10);
pq.add(20);

System.out.println(pq.peek());
```

Output:

```text
30
```

Another option:

```java
PriorityQueue<Integer> pq =
    new PriorityQueue<>((a, b) -> Integer.compare(b, a));
```

Prefer `Integer.compare()` over:

```java
(a, b) -> b - a
```

because subtraction can overflow.

---

## 21. Important Java PriorityQueue Methods

Common methods:

```java
add()
offer()

peek()

poll()
remove()

size()

isEmpty()

contains()
```

Typical heap-based complexities:

```
| Operation | Complexity |
|---|---:|
| `add()` | `O(log n)` |
| `offer()` | `O(log n)` |
| `peek()` | `O(1)` |
| `poll()` | `O(log n)` |
| `remove()` | `O(log n)` for root removal |
| `size()` | `O(1)` |
| `isEmpty()` | `O(1)` |
| `contains()` | `O(n)` |
```

---

### 21-b What About a Priority Queue With Objects?

This is extremely important in Java interviews.

Suppose:
```
class Student {
   int marks;
   String name;
}
```

We want the student with the lowest marks first.
We can define:
```
PriorityQueue<Student> pq =
   new PriorityQueue<>(
       Comparator.comparingInt(s -> s.marks)
   );
```

Now:
```
pq.offer(new Student(80, "A"));
pq.offer(new Student(50, "B"));
pq.offer(new Student(90, "C"));
```

Then:
```
pq.peek()
```
returns the student with:
50 marks

This is why PriorityQueue is extremely common in Java DSA.


---

## 22. Important: Java PriorityQueue Is NOT Sorted

Suppose:

```java
PriorityQueue<Integer> pq = new PriorityQueue<>();

pq.add(10);
pq.add(5);
pq.add(20);
pq.add(1);
```

The internal structure is **not guaranteed to be**:

```text
1 5 10 20
```

A heap only guarantees that the highest-priority element is at the root.

Therefore:

```text
Priority Queue ≠ Sorted Array
```

To obtain elements repeatedly in priority order:

```java
while (!pq.isEmpty()) {
    System.out.println(pq.poll());
}
```

---

## 23. Priority Queue vs Sorted Array

Suppose we need:

```text
insert
peek minimum
remove minimum
```

### Sorted Array

```text
insert         O(n)
peek minimum   O(1)
remove         O(n)
```

### Binary Heap

```text
insert         O(log n)
peek minimum   O(1)
remove         O(log n)
```

Heap provides a better overall balance for Priority Queue workloads.

---

## 24. Priority Queue vs Unsorted Array

### Unsorted Array

```text
insert         O(1)
peek minimum   O(n)
remove minimum O(n)
```

### Binary Heap

```text
insert         O(log n)
peek minimum   O(1)
remove minimum O(log n)
```

So:

```text
Unsorted array:
fast insertion, slow priority access

Heap:
slightly slower insertion, fast priority access
```

---

# 25. Interview Questions

## Q1. Is Priority Queue a Heap?

**Answer:**

> No. A Priority Queue is an ADT that defines priority-based behavior. A heap is a concrete data structure and is one of the most common ways to implement a Priority Queue.

Short version:

```text
PQ = WHAT
Heap = HOW
```

---

## Q2. Why is Heap Used to Implement Priority Queue?

**Answer:**

> A binary heap keeps the highest-priority element at the root while maintaining efficient insertion and deletion. Insert and remove take `O(log n)`, while peek takes `O(1)`.

---

## Q3. Is Java PriorityQueue a Min Heap?

**Answer:**

> Java's `PriorityQueue` provides heap-based priority ordering and, with its natural ordering, behaves as a Min Priority Queue: the smallest element is returned by `peek()` and `poll()`. A custom comparator can create a Max Priority Queue or another ordering.

---

## Q4. Does PriorityQueue Store Elements in Sorted Order?

**Answer:**

> No. A heap-based Priority Queue is not fully sorted. It only guarantees that the highest-priority element is at the head/root. Repeated `poll()` operations return elements in priority order.

---

## Q5. Why is `peek()` O(1)?

**Answer:**

> The highest-priority element is maintained at the root of the heap, which is at index `0` in an array-based heap. Therefore it can be accessed directly.

---

## Q6. Why is Insert O(log n)?

**Answer:**

> The new element is added at the end to preserve the complete-tree property and may move upward through heapify-up. Since heap height is `O(log n)`, insertion is `O(log n)`.

---

## Q7. Why is Remove O(log n)?

**Answer:**

> After removing the root, the last element is moved to the root and may move downward using heapify-down. It can travel at most the heap height, which is `O(log n)`.

---

## Q8. Can a Priority Queue Be Implemented Without a Heap?

**Answer:**

> Yes. It can be implemented using an unsorted array, sorted array, linked list, balanced BST, or other structures. A binary heap is popular because it provides `O(log n)` insertion, `O(1)` peek, and `O(log n)` removal.

---

## Q9. Heap vs BST for Priority Queue?

A heap is generally preferable when the main requirement is:

```text
get/remove minimum or maximum
```

because:

```text
Heap:
peek min/max    O(1)
insert          O(log n)
remove min/max  O(log n)
```

A BST is more useful when we also need ordered operations such as:

```text
search
predecessor
successor
range queries
```

The correct data structure depends on the requirements.

---

## Q10. Why Can't We Use a Normal Queue for Priority Scheduling?

**Answer:**

> A normal Queue follows FIFO ordering, whereas a Priority Queue removes elements according to priority. Therefore, a normal Queue does not naturally provide priority-based removal.

---

## Q11. Min PQ vs Max PQ?

```text
Min PQ:
smallest element = highest priority

Max PQ:
largest element = highest priority
```

Example:

```text
5, 10, 20

Min PQ:
peek() → 5

Max PQ:
peek() → 20
```

---

## Q12. Heapify Up vs Heapify Down?

### Heapify Up

Usually after:

```text
INSERT
```

```text
leaf
 ↓
parent
 ↓
grandparent
 ↓
root
```

### Heapify Down

Usually after:

```text
REMOVE ROOT
```

```text
root
 ↓
child
 ↓
grandchild
 ↓
leaf
```

---

## Q13. Can We Build a Priority Queue in O(n)?

If all elements are already available and bottom-up heap construction is used:

```text
Build Heap = O(n)
```

This is better than inserting all `n` elements:

```text
n × O(log n)
= O(n log n)
```

---

# 26. Important Complexity Summary

For a binary-heap-based Priority Queue:

```text
                 Min/Max PQ
                     |
       +-------------+-------------+
       |             |             |
      add           peek          remove
       |             |             |
    O(log n)        O(1)        O(log n)
```

Space:

```text
O(n)
```

---

# 27. Final Mental Model

```text
                         PRIORITY QUEUE
                              |
                         is an ADT
                              |
                     "process by priority"
                              |
                              v
                    needs an implementation
                              |
               +--------------+--------------+
               |                             |
             HEAP                           BST
               |
       +-------+-------+
       |               |
    Min Heap        Max Heap
       |               |
    Min PQ          Max PQ
       |               |
 smallest first    largest first
```

The key interview sentence:

```text
Priority Queue defines the behavior.
Heap provides an efficient implementation.
```

---

# 28. One-Page Revision

```text
PRIORITY QUEUE
--------------
ADT where removal/access happens according to priority.

MIN PQ:
smallest element has highest priority.

MAX PQ:
largest element has highest priority.


COMMON HEAP IMPLEMENTATION
---------------------------
Min PQ → Min Heap
Max PQ → Max Heap


OPERATIONS
----------
```
add       → O(log n)
peek      → O(1)
remove    → O(log n)
size      → O(1)
isEmpty   → O(1)

Space     → O(n)
```


HEAP
----
Concrete data structure.

Complete Binary Tree
+
Heap Order Property


PQ
--
Abstract Data Type.

Defines:
- priority-based insertion/access/removal

Does NOT dictate one implementation.


KEY DIFFERENCE
--------------
Heap = data structure
PQ   = ADT

Heap = HOW
PQ   = WHAT


JAVA
----
PriorityQueue<Integer> pq = new PriorityQueue<>();

Default:
Min Priority Queue // VIP

Max:
PriorityQueue<Integer> pq =
    new PriorityQueue<>(Collections.reverseOrder());   // IMP


IMPORTANT
---------
PriorityQueue is NOT fully sorted.

Only the highest-priority element is guaranteed
to be at the head/root.

Repeated poll() gives elements in priority order.
```

```
```
Crtd by alpha1zln wd rtAi ctgpt.
```
```