# PreBuiltHeap — Java Collections Framework

> **Repository:** `create-data-structure-from-basic`  
> **Topic:** Pre-built Heap in Java  
> **Java class:** `PriorityQueue<E>`

## 1. What is a Pre-Built Heap?

Java provides:

```java
PriorityQueue<E>
```

inside the Java Collections Framework.

By default:

```java
PriorityQueue<Integer> pq = new PriorityQueue<>();
```

provides **Min Heap behavior**:

```text
peek() → smallest element
poll() → removes smallest element
```

Conceptually:

```text
PriorityQueue
      ↓
heap-backed priority queue
```

You do not have to implement:

```text
heapifyUp()
heapifyDown()
swap()
parent/child calculations
```

Java handles the internal implementation.

---

## 2. Heap vs PriorityQueue

```text
Heap
 ↓
Data Structure
```

```text
Priority Queue
 ↓
Abstract Data Type / behavior
```

A Heap is commonly used to implement a Priority Queue.

```text
Min Heap → Min Priority Queue
Max Heap → Max Priority Queue
```

Java's `PriorityQueue` is the practical pre-built option.

---

## 3. Import and Creation

```java
import java.util.PriorityQueue;
```

Min Heap:

```java
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
```

Max Heap:

```java
PriorityQueue<Integer> maxHeap =
        new PriorityQueue<>(Comparator.reverseOrder());
```

Import:

```java
import java.util.Comparator;
```

---

## 4. Min Heap

```java
PriorityQueue<Integer> pq = new PriorityQueue<>();

pq.offer(50);
pq.offer(20);
pq.offer(10);
pq.offer(40);

System.out.println(pq.peek());
```

Output:

```text
10
```

Default ordering gives the smallest element highest priority.

---

## 5. Max Heap

Java does not have a separate `MaxHeap` class.

Use a Comparator:

```java
PriorityQueue<Integer> maxHeap =
        new PriorityQueue<>(Comparator.reverseOrder());
```

Example:

```java
maxHeap.offer(30);
maxHeap.offer(10);
maxHeap.offer(50);
maxHeap.offer(20);

System.out.println(maxHeap.peek());
```

Output:

```text
50
```

Memory:

```text
default PriorityQueue
        ↓
     Min Heap

reverseOrder()
        ↓
     Max Heap
```

Prefer `Comparator.reverseOrder()` over:

```java
(a, b) -> b - a
```

because subtraction-based comparators can overflow for extreme integer values.

---

## 6. Comparator

A Comparator determines priority.

```text
Min Heap
smaller → higher priority

Max Heap
larger → higher priority
```

Example:

```java
PriorityQueue<Integer> minHeap =
        new PriorityQueue<>();

PriorityQueue<Integer> maxHeap =
        new PriorityQueue<>(Comparator.reverseOrder());
```

Custom objects can also have custom priority rules.

---

## 7. Important Operations

| Operation | Purpose | Typical TC |
|---|---|---:|
| `offer()` | Insert | O(log n) |
| `add()` | Insert | O(log n) |
| `peek()` | View root | O(1) |
| `poll()` | Remove + return root | O(log n) |
| `remove()` | Remove root | O(log n) |
| `remove(Object)` | Remove specific object | O(n) |
| `contains()` | Search | O(n) |
| `size()` | Number of elements | O(1) |
| `isEmpty()` | Empty check | O(1) |
| `clear()` | Remove all | O(n) |
| `comparator()` | Get comparator | O(1) |

Overall space:

```text
O(n)
```

---

## 8. `offer()` vs `add()`

Both insert an element:

```java
pq.offer(10);
```

```java
pq.add(10);
```

For `PriorityQueue`, both are typically:

```text
O(log n)
```

`offer()` is often clearer when treating the object as a Queue.

---

## 9. `peek()`

```java
pq.peek();
```

Returns the highest-priority element **without removing it**.

```text
peek()
  ↓
root
  ↓
O(1)
```

If empty:

```java
pq.peek();
```

returns:

```text
null
```

---

## 10. `poll()`

```java
pq.poll();
```

Does:

```text
return highest-priority element
+
remove it
```

Typical complexity:

```text
O(log n)
```

If empty:

```java
pq.poll();
```

returns:

```text
null
```

---

## 11. `remove()` vs `poll()`

Important interview question:

```text
poll()
 ↓
empty → null
```

```text
remove()
 ↓
empty → NoSuchElementException
```

Both remove the root when the queue is non-empty.

---

## 12. `remove(Object)`

There are two different forms.

### Remove root

```java
pq.remove();
```

Typical:

```text
O(log n)
```

### Remove specific value

```java
pq.remove(30);
```

Typical:

```text
O(n)
```

because arbitrary-value searching is not efficiently supported by Heap ordering.

---

## 13. `contains()`

```java
pq.contains(30);
```

Typical:

```text
O(n)
```

A Heap is not a sorted search structure.

---

## 14. `size()` and `isEmpty()`

```java
pq.size();       // O(1)
pq.isEmpty();    // O(1)
```

An empty PriorityQueue is valid:

```text
size = 0
```

---

## 15. PriorityQueue Is NOT Sorted

This is very important.

```java
System.out.println(pq);
```

does **not** guarantee sorted order.

Likewise:

```java
for (Integer x : pq)
```

does not guarantee priority order.

The important guarantees are:

```text
peek() → highest-priority element
poll() → removes highest-priority element
```

If priority order is required:

```java
while (!pq.isEmpty()) {
    System.out.println(pq.poll());
}
```

For a Min Heap, this prints elements from smallest to largest.

**Note:** polling destroys the queue.

---

## 16. Duplicates and null

Duplicates are allowed:

```java
pq.offer(10);
pq.offer(10);
pq.offer(20);
```

`null` is not allowed:

```java
pq.offer(null);
```

causes:

```text
NullPointerException
```

---

## 17. Custom Objects

PriorityQueue is very useful with custom classes.

Example:

```java
class Student {
    int marks;
    String name;
}
```

Priority by smallest marks:

```java
PriorityQueue<Student> pq =
    new PriorityQueue<>(
        Comparator.comparingInt(s -> s.marks)
    );
```

Highest marks first:

```java
PriorityQueue<Student> pq =
    new PriorityQueue<>(
        Comparator.comparingInt((Student s) -> s.marks).reversed()
    );
```

The Comparator defines:

```text
WHAT determines priority
```

Java handles:

```text
HOW the heap is maintained
```

---

## 18. Constructors

Common forms:

```java
PriorityQueue<Integer> pq =
        new PriorityQueue<>();
```

Initial capacity:

```java
PriorityQueue<Integer> pq =
        new PriorityQueue<>(100);
```

Comparator:

```java
PriorityQueue<Integer> pq =
        new PriorityQueue<>(Comparator.reverseOrder());
```

Capacity + Comparator:

```java
PriorityQueue<Integer> pq =
        new PriorityQueue<>(100, Comparator.reverseOrder());
```

---

## 19. Internal Structure

Conceptually:

```text
PriorityQueue
      |
      v
array-based heap
      |
      v
parent / child relationships
```

The same formulas apply conceptually:

```text
parent = (i - 1) / 2
left   = 2*i + 1
right  = 2*i + 2
```

Difference:

```text
Custom Heap
    ↓
YOU implement Heapify

PriorityQueue
    ↓
Java implements it
```

---

## 20. Custom Heap vs PriorityQueue

| Feature | Custom Heap | `PriorityQueue` |
|---|---|---|
| Implementation | You write | Java provides |
| Heapify | You implement | Built in |
| Swap | You implement | Built in |
| Min Heap | Yes | Yes |
| Max Heap | Yes | Comparator |
| Insert | O(log n) | O(log n) |
| Peek | O(1) | O(1) |
| Remove root | O(log n) | O(log n) |
| Search | O(n) | O(n) |
| Space | O(n) | O(n) |
| Learning | Excellent | Practical |

---

## 21. When to Use Custom Heap

Use your custom Heap when:

```text
1. Learning DSA
2. Interview asks "implement Heap"
3. Studying Heapify
4. Building a data-structure library
5. You need special behavior not provided by PriorityQueue
```

For this repository:

```text
create-data-structure-from-basic
```

the custom implementation is the learning exercise.

---

## 22. When to Use PriorityQueue

In normal Java application or competitive-programming code, use:

```java
PriorityQueue<E>
```

when you need repeated:

```text
minimum
maximum
next highest-priority item
```

Common problems:

```text
Top K Elements
Kth Largest
Kth Smallest
Merge K Sorted Lists
Scheduling
Dijkstra
Prim's MST
Task Scheduling
Median of Data Stream
```

---

## 23. Top-K Pattern

For `K` largest elements, a common technique is:

```text
Min Heap of size K
```

The smallest of the current K candidates stays at the root.

Typical complexity:

```text
O(n log k)
```

This is one of the most important PriorityQueue interview patterns.

---

## 24. Dijkstra

PriorityQueue is commonly used in Dijkstra's algorithm:

```text
distance
   ↓
priority
   ↓
Min PriorityQueue
```

The node with the smallest current distance is processed first.

---

## 25. Complexity Summary

```text
offer/add       → O(log n)
peek            → O(1)
poll            → O(log n)
remove()        → O(log n)
contains        → O(n)
remove(object)  → O(n)
size            → O(1)
isEmpty         → O(1)
space           → O(n)
```

---

## 26. Interview Questions

### Q1. Is Java's PriorityQueue a Heap?

`PriorityQueue` is a priority-queue implementation backed by a heap-based array structure.

### Q2. Min Heap or Max Heap by default?

```text
Min Heap behavior
```

### Q3. How do you create a Max Heap?

```java
PriorityQueue<Integer> pq =
        new PriorityQueue<>(Comparator.reverseOrder());
```

### Q4. Complexity of `peek()`?

```text
O(1)
```

### Q5. Complexity of `offer()`?

```text
O(log n)
```

### Q6. Complexity of `poll()`?

```text
O(log n)
```

### Q7. Complexity of `contains()`?

```text
O(n)
```

### Q8. Does PriorityQueue maintain sorted order?

No.

### Q9. Does it allow duplicates?

Yes.

### Q10. Does it allow null?

No.

### Q11. `peek()` vs `poll()`?

```text
peek → view root
poll → view + remove root
```

### Q12. `poll()` vs `remove()`?

```text
poll()   → null if empty
remove() → exception if empty
```

### Q13. `remove()` vs `remove(Object)`?

```text
remove()      → root
remove(value) → specific object
```

### Q14. Why is `contains()` O(n)?

Heap ordering does not provide sorted-order searching.

### Q15. Does iteration give sorted order?

No. Use repeated `poll()` if priority order is required.

---

# Quick Revision

```text
Java Pre-Built Heap
        ↓
PriorityQueue<E>
```

Default:

```text
PriorityQueue
      ↓
Min Heap behavior
```

Max Heap:

```java
new PriorityQueue<>(Comparator.reverseOrder());
```

Operations:

```text
offer()       → insert
add()         → insert
peek()        → view root
poll()        → remove + return root
remove()      → remove root
contains()    → search
size()        → count
isEmpty()     → empty check
```

Complexity:

```text
offer      → O(log n)
add        → O(log n)
peek       → O(1)
poll       → O(log n)
remove()   → O(log n)
contains   → O(n)
remove(x)  → O(n)
size       → O(1)
isEmpty    → O(1)
space      → O(n)
```

Important:

```text
PriorityQueue ≠ sorted collection
```

Only the highest-priority element is guaranteed to be available through the root operations.

---

# Mental Model

```text
                 PriorityQueue<E>
                        |
                +-------+-------+
                |               |
             default         Comparator
                |               |
             Min Heap        custom order
                                |
                         reverseOrder()
                                |
                             Max Heap
```

Operations internally follow the same Heap ideas you implemented yourself:

```text
insert
  ↓
Heapify Up

remove root
  ↓
Heapify Down
```

but Java performs those steps internally.

---

# One-Line Interview Answer

> **Java's `PriorityQueue` is a heap-backed priority queue that provides O(1) access to the highest-priority element and O(log n) insertion/removal of that element; by default it provides Min Heap behavior, while a Comparator can provide Max Heap or custom priority behavior.**

---

## Related Repository Files

```text
Heap.md [Heap code pkg]
    ↓
Compact custom Heap implementation notes

HeapUsingArrayList.md [Bld Heap pkg]
    ↓
Detailed Heap theory + implementation

PreBuiltHeap/README.md [pre-built pq pkg]
    ↓
Java PriorityQueue
```

# End

---

###  Git use to resolve diffc in local repo and remote repo


Case --- 
apzn MINGW64 /f/proj/Bld_data_str_from_basic/DATA_STRUCTURE_Create_from_basic (branchHeapv8)

$ git push -u origin branchHeapv8

To 
Alpha1zln/DATA_STRUCTURE_Create_from_basic.git

! [rejected]        branchHeapv8 -> branchHeapv8 (fetch first)

error: failed to push some refs to '
Alpha1zln/DATA_STRUCTURE_Create_from_basic.git'

hint: Updates were rejected because the remote contains work that you do not

hint: have locally. This is usually caused by another repository pushing to

hint: the same ref. If you want to integrate the remote changes, use

hint: 'git pull' before pushing again.

hint: See the 'Note about fast-forwards' in 'git push --help' for details.

Yes — this is a non-fast-forward rejection.


Soltn ------ 

Your situation is:

```
LOCAL:
branchHeapv8
      |
      |--- your local commits
```

```
REMOTE:
origin/branchHeapv8
      |
      |--- some commits you DON'T have locally
```
Git refuses to push because pushing your local branch as-is could overwrite the remote commits.

Safest approach:
Since you want to keep both your local work and whatever is already on GitHub, do:
```
git pull --rebase origin branchHeapv8
```

Then:
```
git push -u origin branchHeapv8
```

```
#### What pull --rebase does

It essentially:
- Downloads the remote branchHeapv8 changes.
- Temporarily moves your local commits aside.
- Applies the remote commits.
- Re-applies your local commits on top.


So the history becomes:

Before:
```
Remote: A---B---C
              \
Local:         D---E
```



After rebase:
```
A---B---C---D'---E'
```

Your work is preserved.
```



```
##### ⚠️ If you get a conflict

Git may say something like:

CONFLICT (content): Merge conflict in ...

Then:
git status

Open the conflicted file(s), resolve the conflicts, then:

git add .
git rebase --continue

Repeat until the rebase finishes.

Then:
git push -u origin branchHeapv8
First, you can inspect what exists remotely

If you want to see what remote has that you don't have, run:

git fetch origin
git log --oneline --graph --decorate HEAD..origin/branchHeapv8

And what you have locally that remote doesn't:

git log --oneline --graph --decorate origin/branchHeapv8..HEAD
❌ Don't immediately do this
git push --force

because the remote branch already contains commits you don't have. Force-pushing could overwrite those remote commits.

For your case, I'd use:

git pull --rebase origin branchHeapv8
git push -u origin branchHeapv8

This is the cleanest solution if both sides' work should be retained.
```


---