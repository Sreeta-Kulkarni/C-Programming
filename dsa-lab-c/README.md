# Data Structures and Algorithms in C

Lab programs for the **Data Structures and Algorithms** course (Subject Code: CSEG1043), B.Tech CSE, Semester II — implemented in C.

Each folder corresponds to one lab/experiment and contains the individual task programs as separate `.c` files. All programs have been extracted, cleaned up, and compile successfully with `gcc`.

## 📁 Structure

| Folder | Topic |
|---|---|
| [`01_structures_unions_pointers`](./01_structures_unions_pointers) | Structures, Unions & Pointers |
| [`02_linked_lists`](./02_linked_lists) | Singly / Circular Linked Lists |
| [`03_stack`](./03_stack) | Stack (Array & Linked List) |
| [`04_queue`](./04_queue) | Queue (Linear, Circular, Multiple Queues) |
| [`05_searching`](./05_searching) | Linear Search & Binary Search |
| [`06_sorting`](./06_sorting) | Bubble, Selection & Insertion Sort |
| [`07_trees`](./07_trees) | Binary Trees |
| [`08_heaps`](./08_heaps) | Min/Max Heaps & Priority Queue |
| [`09_hashing`](./09_hashing) | Hash Tables (Linear/Quadratic Probing, Double Hashing) |
| [`10_graphs`](./10_graphs) | Graph Representation, BFS, DFS, Cycle Detection |

## 📜 Program list

### 01. Structures, Unions & Pointers
1. Book structure — input & display 3 books
2. Employee structure with nested Address structure
3. Union storing Temperature or Humidity (memory sharing demo)
4. Swap two numbers using pointers
5. Array of pointers to store & print city names
6. Print a 3×3 matrix using pointer to an array

### 02. Linked Lists
1. Insert a node at the beginning of a singly linked list
2. Delete a node from the end of a singly linked list
3. Circular singly linked list
4. Menu-driven program: insert, delete, traverse

### 03. Stack
1. Stack using array (menu-driven)
2. Stack using linked list (menu-driven)
3. Balanced parentheses checker
4. Infix to postfix conversion
5. Postfix expression evaluation
6. Two stacks in a single array
7. Reverse a string using stack

### 04. Queue
1. Queue with Front, Rear, IsEmpty, IsFull operations
2. Circular queue using array
3. Printer queue simulation
4. Multiple queues in a single array

### 05. Searching
1. Linear search with comparison count
2. Recursive binary search
3. Search with input validation
4. Linear vs binary search — execution time comparison
5. Search multiple elements in one run
6. Binary search — first & last occurrence

### 06. Sorting
1. Bubble sort (descending order)
2. Bubble sort with swap/comparison counters
3. Sort with dynamic (user-entered) input
4. Sort only even numbers, keep odd numbers in place
5. Selection sort — display array after each pass
6. Insertion sort — print intermediate steps

### 07. Trees
1. Binary tree using integers
2. Count total number of nodes
3. Find height of a binary tree

### 08. Heaps
1. Min heap implementation
2. Insert 5 elements & display heap
3. Find maximum element in a heap
4. Priority queue using a heap
5. K largest elements using a heap

### 09. Hashing
1. Insert 10+ elements & display hash table
2. Search operation
3. Deletion using linear probing
4. Quadratic probing
5. Load factor calculation
6. Double hashing
7. Application: word frequency counter
8. Application: student record storage

### 10. Graphs
1. Graph using adjacency matrix
2. BFS traversal (queue based)
3. DFS traversal (recursive)
4. Cycle detection
5. BFS vs DFS — time complexity comparison

## 🛠️ How to compile & run

Each file is self-contained. Compile any program with `gcc`:

```bash
gcc 01_structures_unions_pointers/01_book_structure.c -o book_structure
./book_structure
```

All 54 programs have been verified to compile cleanly with `gcc` (no warnings suppressed except `-w` for legacy `scanf` string-format warnings).

## 🎓 Course Info

- **Subject:** Data Structures and Algorithms (CSEG1043)
- **Course:** B.Tech CSE, Semester II
- **College:** UPES
