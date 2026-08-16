# HEAP Brief Note and Code in Pkg
#### (readme)

> **Repository:** `create-data-structure-from-basic`  
> **Purpose:** Compact implementation notes for Heap using `ArrayList`, interfaces, and menus.  
> **Detailed reference:** `HeapUsingArrayList.md`

---

## 1. Heap — Quick Definition

A **Heap** is a **Complete Binary Tree** that satisfies the **Heap Property**.

```text
                    HEAP
                      |
             +--------+--------+
             |                 |
          MIN HEAP          MAX HEAP
             |                 |
      smallest at root     largest at root
```

### Complete Binary Tree

Every level is completely filled except possibly the last, and the last level is filled from left to right.

### Heap Property

**Min Heap**
```text
parent <= children
```

Root = minimum element.

**Max Heap**
```text
parent >= children
```

Root = maximum element.

> A Heap is **not a sorted tree**. Only the root is guaranteed to be the minimum/maximum.

---

## 2. ArrayList Representation

A Complete Binary Tree can be stored efficiently in an array-like structure.

```text
              10
            /    \
          20      15
         /  \    /
       30   40  50
```

```text
index:    0   1   2   3   4   5
value:   10  20  15  30  40  50
```

For index `i`:

```text
parent = (i - 1) / 2
left   = 2 * i + 1
right  = 2 * i + 2
```

Root is always at index `0`.

---

## 3. Repository Architecture

My implementation separates **contract, implementation, user interaction, and application entry point**.

```text
                              Main
                                |
                                v
                         HeapTypeMenu
                                |
                       Select Min / Max
                                |
                                v
                              Heap
                         <<interface>>
                                |
                   +------------+------------+
                   |                         |
                   v                         v
             BuildMinHeap              BuildMaxHeap
             <<interface>>             <<interface>>
                   |                         |
                   v                         v
        MinHeapUsingArrayList      MaxHeapUsingArrayList
                   |                         |
                   +------------+------------+
                                |
                            ArrayList
```

### Suggested files

```text
Heap.java
BuildMinHeap.java
BuildMaxHeap.java

MinHeapUsingArrayList.java
MaxHeapUsingArrayList.java

HeapTypeMenu.java
HeapMenu.java
Main.java
```

---

## 4. Interface Design

### `Heap`

Defines operations common to every Heap:

```text
insert()
peek()
remove()
print()
size()
isEmpty()
```

It answers:

> **What can a Heap do?**

It does not define:

> **How is the Heap implemented?**

### Child interfaces

```text
                         Heap
                    <<interface>>
                          |
             +------------+------------+
             |                         |
       BuildMinHeap              BuildMaxHeap
       <<interface>>             <<interface>>
```

Both child interfaces inherit the common Heap operations.

Implementations:

```text
BuildMinHeap
     ↑
MinHeapUsingArrayList
```

```text
BuildMaxHeap
     ↑
MaxHeapUsingArrayList
```

This gives a clean separation between contract and implementation.

---

## 5. Why Interfaces?

The menu should not depend on a concrete implementation.

Conceptually:

```text
Heap
 |
 +---- MinHeapUsingArrayList
 |
 +---- MaxHeapUsingArrayList
```

Both can be handled through a common `Heap` reference.

Benefits:

```text
Abstraction
Polymorphism
Separation of Concerns
```

---

## 6. Heap Type Menu

The first menu answers:

> **Which Heap does the user want?**

```text
===== SELECT HEAP =====

1. Min Heap
2. Max Heap
```

Flow:

```text
                    HeapTypeMenu
                          |
              +-----------+-----------+
              |                       |
           choice 1                choice 2
              |                       |
              v                       v
      MinHeapUsingArrayList   MaxHeapUsingArrayList
              |                       |
              +-----------+-----------+
                          |
                          v
                         Heap
```

The Heap Type Menu should **not** contain Heapify logic.

It only selects the implementation.

---

## 7. Heap Operations Menu

After selecting the Heap:

```text
===== HEAP =====

1. Add Element
2. Peek Element
3. Remove Element
4. Print Heap
5. Size
6. Is Empty
7. Exit
```

Its responsibility is:

```text
user input
    ↓
call appropriate Heap operation
```

It should not contain:

```text
heapifyUp
heapifyDown
swap
parent/child calculations
```

Those belong to the implementation class.

---

## 8. Main

`Main` should remain small.

Conceptually:

```text
Main
 |
 +--> create HeapTypeMenu
 |
 +--> select Min / Max Heap
 |
 +--> receive selected Heap
 |
 +--> create/start HeapMenu
 |
 +--> pass Heap to HeapMenu
```

The flow:

```text
Main
 ↓
HeapTypeMenu
 ↓
select Heap
 ↓
Heap
 ↓
HeapMenu
 ↓
insert / peek / remove / print / size / isEmpty
```

---

## 9. Core Operations

| Operation | Purpose |
|---|---|
| `insert(x)` | Add element and restore Heap Property |
| `peek()` | Return root without removing it |
| `remove()` | Remove root and restore Heap Property |
| `print()` | Display internal ArrayList |
| `size()` | Return number of elements |
| `isEmpty()` | Check whether Heap is empty |

---

## 10. Insert

Insertion must preserve the Complete Binary Tree property.

```text
1. Add element at the end.
2. Heapify Up.
```

Example Min Heap:

```text
              10
            /    \
          20      30
```

Insert `5`:

```text
              10
            /    \
          20      30
         /
        5
```

Heap Property is violated because:

```text
5 < 20
```

Heapify Up moves `5` toward the root:

```text
              5
            /   \
          10     30
         /
        20
```

---

## 11. Heapify Up

Heapify Up moves:

```text
child → parent
bottom → top
```

### Min Heap

Swap when:

```text
parent > child
```

Smaller values move upward.

### Max Heap

Swap when:

```text
parent < child
```

Larger values move upward.

### Memory trick

```text
MIN → smaller moves UP
MAX → larger moves UP
```

Algorithm:

```text
childIdx = inserted element index
parentIdx = (childIdx - 1) / 2

while child is not root:

    compare parent and child

    if Heap Property is satisfied:
        stop

    swap parent and child

    child becomes parent
```

Important:

```text
childIdx > 0
```

because root has no parent.

---

## 12. Remove Root

For Min Heap:

```text
remove() → minimum
```

For Max Heap:

```text
remove() → maximum
```

Process:

```text
1. Save root.
2. Remove last element.
3. Put last element at root.
4. Heapify Down.
5. Return saved root.
```

Example:

```text
              10
            /    \
          20      15
         /  \
       30   40
```

Remove `10`.

Move `40` to root:

```text
              40
            /    \
          20      15
         /
       30
```

Heapify Down restores the Min Heap:

```text
              15
            /    \
          20      40
         /
       30
```

---

## 13. Heapify Down

Heapify Down moves:

```text
parent → child
top → bottom
```

### Min Heap

Choose:

```text
smallest child
```

Swap when:

```text
child < parent
```

### Max Heap

Choose:

```text
largest child
```

Swap when:

```text
child > parent
```

### Memory trick

```text
MIN → choose smaller child
MAX → choose larger child
```

At index `i`:

```text
left  = 2 * i + 1
right = 2 * i + 2
```

Start:

```text
bestIndex = current index
```

Then compare left and right children with the current best.

If `bestIndex == current index`, stop.

Otherwise:

```text
swap
move to bestIndex
continue
```

---

## 14. Min Heap → Max Heap

The overall implementation remains almost identical.

Main differences:

```text
MIN HEAP

Heapify Up:
parent > child → swap

Heapify Down:
choose smaller child
```

```text
MAX HEAP

Heapify Up:
parent < child → swap

Heapify Down:
choose larger child
```

Quick memory:

```text
MIN → <
MAX → >
```

The ArrayList representation and index formulas remain unchanged.

---

## 15. `peek()`

Root is always:

```text
index 0
```

Therefore:

```text
peek() → get(0)
```

Complexity:

```text
O(1)
```

For an empty Heap, throwing an exception is preferable to returning a fake value such as `-1`, because `-1` could be valid data.

---

## 16. `size()` and `isEmpty()`

```text
size()      → O(1)
isEmpty()   → O(1)
```

An empty Heap is a valid state:

```text
size() = 0
```

`size()` should therefore not need to throw just because the Heap is empty.

---

## 17. Complexity

| Operation | Time | Extra Space |
|---|---:|---:|
| Insert | O(log n) | O(1) |
| Peek | O(1) | O(1) |
| Remove | O(log n) | O(1) |
| Heapify Up | O(log n) | O(1) |
| Heapify Down | O(log n) | O(1) |
| Swap | O(1) | O(1) |
| Size | O(1) | O(1) |
| Is Empty | O(1) | O(1) |

Overall Heap storage:

```text
O(n)
```

Heap height:

```text
O(log n)
```

Therefore:

```text
insert → O(log n)
remove → O(log n)
peek   → O(1)
```

---

## 18. ArrayList Complexity

The implementation uses:

```text
ArrayList<Integer>
```

Important operations:

```text
get(index)      → O(1)
set(index, x)   → O(1)
add(x)          → amortized O(1)
remove(last)    → O(1)
```

This makes `ArrayList` a good fit for an array-based Heap.

---

## 19. Why Not LinkedList?

Heap frequently needs random access to:

```text
parent
left child
right child
```

ArrayList:

```text
get(index) → O(1)
```

LinkedList:

```text
get(index) → O(n)
```

Therefore:

```text
Array / ArrayList
       ↓
Good choice for Heap

LinkedList
       ↓
Poor choice for array-style Heap
```

---

## 20. Heap Is Not Sorted

Example:

```text
              5
            /   \
          20     10
         /  \
       40   30
```

ArrayList:

```text
[5, 20, 10, 40, 30]
```

This is a valid Min Heap but not a sorted array.

The guarantee is only:

```text
parent <= children
```

for Min Heap.

---

## 21. Heap vs Priority Queue

```text
Heap
 ↓
Data Structure
```

```text
Priority Queue
 ↓
Abstract Data Type
```

A Heap can implement a Priority Queue:

```text
Min Heap → Min Priority Queue
Max Heap → Max Priority Queue
```

Useful memory:

```text
Priority Queue = WHAT

Heap = HOW
```

---

## 22. Heap vs BST — Quick Note

Heap is excellent when we mainly need:

```text
minimum / maximum
```

BST is useful for:

```text
search
ordered traversal
predecessor
successor
range queries
```

Heap:

```text
peek min/max → O(1)
```

A Heap does not provide the same general ordered-search capability as a BST.

---

## 23. Common Implementation Mistakes

### Wrong parent formula

```text
(i - 1) / 2
```

### Wrong child formulas

```text
left  = 2*i + 1
right = 2*i + 2
```

### Forgetting bounds

Before accessing a child:

```text
childIndex < size
```

### Wrong child selection

```text
MIN → smallest child
MAX → largest child
```

### Wrong heapify direction

```text
insert       → Heapify Up
remove root  → Heapify Down
```

### Forgetting root has no parent

```text
index > 0
```

### Returning a fake empty value

Avoid blindly returning:

```text
-1
0
```

when those may be valid data.

Use an appropriate exception for operations that require an element.

---

## 24. My Implementation Flow

### Insert

```text
insert(x)
   |
   v
ArrayList.add(x)
   |
   v
Heapify Up
   |
   v
Heap Property restored
```

### Remove

```text
remove()
   |
   v
save root
   |
   v
remove last element
   |
   v
put last at root
   |
   v
Heapify Down
   |
   v
return old root
```

### Peek

```text
peek()
   |
   v
get(0)
```

---

## 25. Design Responsibility

Each component has one main responsibility.

```text
Heap.java
    ↓
common contract

BuildMinHeap.java
    ↓
Min Heap contract

BuildMaxHeap.java
    ↓
Max Heap contract

MinHeapUsingArrayList.java
    ↓
Min Heap implementation

MaxHeapUsingArrayList.java
    ↓
Max Heap implementation

HeapTypeMenu.java
    ↓
select Min / Max

HeapMenu.java
    ↓
user operations

Main.java
    ↓
application entry point
```

Most important separation:

```text
Menu
  ≠
Heap Logic
```

The menu asks:

```text
"What does the user want?"
```

The Heap implementation handles:

```text
"How is that operation performed?"
```

---

## 26. Quick Interview Questions

### What is a Heap?

A Complete Binary Tree satisfying the Heap Property.

### What is a Min Heap?

Every parent is less than or equal to its children.

### What is a Max Heap?

Every parent is greater than or equal to its children.

### Where is the root stored?

```text
index 0
```

### Parent formula?

```text
(i - 1) / 2
```

### Left child?

```text
2*i + 1
```

### Right child?

```text
2*i + 2
```

### Complexity of peek?

```text
O(1)
```

### Complexity of insertion?

```text
O(log n)
```

### Complexity of remove root?

```text
O(log n)
```

### Why Heapify Up after insertion?

The new element is added at the bottom and may violate the parent-child Heap Property.

### Why Heapify Down after root removal?

The replacement element is moved to the root and may violate the Heap Property with its children.

### Is Heap sorted?

No.

### Can Heap implement Priority Queue?

Yes.

---

## 27. 5-Minute Revision Sheet

```text
HEAP
=
Complete Binary Tree
+
Heap Property
```

```text
MIN HEAP
parent <= child
root = minimum
```

```text
MAX HEAP
parent >= child
root = maximum
```

Array formulas:

```text
parent = (i - 1) / 2
left   = 2*i + 1
right  = 2*i + 2
```

Operations:

```text
INSERT
add at end
   ↓
Heapify Up

REMOVE
remove root
   ↓
move last to root
   ↓
Heapify Down

PEEK
get(0)
```

Heapify:

```text
MIN → smaller moves UP
MIN → choose smaller child DOWN

MAX → larger moves UP
MAX → choose larger child DOWN
```

Complexity:

```text
insert → O(log n)
remove → O(log n)
peek   → O(1)
space  → O(n)
```

Architecture:

```text
Main
 ↓
HeapTypeMenu
 ↓
Heap interface
 ↓
BuildMinHeap / BuildMaxHeap
 ↓
MinHeapUsingArrayList / MaxHeapUsingArrayList
 ↓
ArrayList
```

---

## 28. Final Mental Model

```text
                           HEAP
                             |
                Complete Binary Tree
                             +
                       Heap Property
                             |
                +------------+------------+
                |                         |
                v                         v
             MIN HEAP                 MAX HEAP
                |                         |
          smallest root              largest root
                |                         |
                v                         v
          Heapify Up                  Heapify Up
          Heapify Down                Heapify Down
                |                         |
       choose smaller child       choose larger child
                |                         |
                +------------+------------+
                             |
                             v
                         ArrayList
                             |
              +--------------+--------------+
              |              |              |
           parent           left          right
              |              |              |
          (i-1)/2          2i+1          2i+2
```

---

## 29. Key Learning From My Implementation

The most important thing is understanding the **movement of the violating element**.

```text
INSERT
new element starts at bottom
          ↓
       move UP
          ↓
     Heapify Up
```

```text
REMOVE ROOT
replacement starts at top
          ↓
       move DOWN
          ↓
     Heapify Down
```

Then remember:

```text
MIN → smaller toward root

MAX → larger toward root
```

Once Heapify Up and Heapify Down become comfortable, converting:

```text
Min Heap
   ↓
Max Heap
```

is mostly a matter of reversing the comparisons.

---

## Related Documentation

### Detailed Heap Notes

`HeapUsingArrayList.md`

Use this for the full theory, detailed implementation walkthrough, construction methods, complexity analysis, and interview preparation.

### Priority Queue

`PriorityQueueUsingHeap.md`

Use this separately for Priority Queue theory and its Heap-based implementation.

---

# End

> **Practice priority:** Heapify Up + Heapify Down.
>
> The code is short; understanding why the element moves up/down is the real skill.
