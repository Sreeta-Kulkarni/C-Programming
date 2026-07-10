# Heaps

## 📖 Theory

Experiment 8: Heaps
Aim: To create a heap data structure and implement its operations, and its applications.
What is a Heap?
A heap is a complete binary tree where nodes follow a specific parent-child order. In a min-heap,
parents have smaller values than their children, while in a max-heap, parents have larger values.
This structure allows efficient access to the smallest or largest element, making heaps useful for
implementing priority queues.
- Max Heap: Parent node ≥ Children

- Min Heap: Parent node ≤ Children

Key Properties
1. Complete Binary Tree
o

All levels filled except possibly the last

o

Nodes filled left to right

2. Heap Property
o

Maintains ordering between parent and children

Heaps are usually stored in arrays:
For a node at index i:
- Left child → 2i + 1

- Right child → 2i + 2

- Parent → (i - 1) / 2

Basic Operations:
Operation
Insert

Description
Add element and restore heap

Operation

Description

Delete

Remove root and heapify

Heapify

Maintain heap property

Peek

Get root element

Example: Insert into Max Heap:
Insert: 10, 20, 15, 30
Step-by-step:
1. Insert 10 → [10]
2. Insert 20 → [20, 10]
3. Insert 15 → [20, 10, 15]
4. Insert 30 → [30, 20, 15, 10]

Insert 30 into Max Heap:

Algorithm (Insert in Max Heap)
1. Insert element at end
2. Compare with parent
3. Swap if larger
4. Repeat until heap property satisfied
Algorithm (Delete in Max Heap)
1. Replace root with last element
2. Reduce heap size
3. Compare with children
4. Swap with larger child
5. Repeat until heap property is satisfied

Example Program:
```c
#include <stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;

// Insert function
void insert(int value) {
int i = size;
heap[size++] = value;

// Heapify up
while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
int temp = heap[i];
heap[i] = heap[(i - 1) / 2];

heap[(i - 1) / 2] = temp;
i = (i - 1) / 2;
}
}

// Delete root function (Max Heap)
void deleteRoot() {
if (size == 0) {
printf("Heap is empty\n");
return;
}

// Replace root with last element
heap[0] = heap[size - 1];
size--;
int i = 0;

// Heapify down
while (1) {
int left = 2 * i + 1;
int right = 2 * i + 2;
int largest = i;
if (left < size && heap[left] > heap[largest])
largest = left;
if (right < size && heap[right] > heap[largest])
largest = right;
if (largest == i)
break;

int temp = heap[i];
heap[i] = heap[largest];
heap[largest] = temp;
i = largest;
}
}

// Display function
void display() {
for (int i = 0; i < size; i++)
printf("%d ", heap[i]);
printf("\n");
}

int main() {
insert(10);
insert(20);
insert(15);
insert(30);
printf("Heap elements: ");
display();
deleteRoot();
printf("After deletion: ");
display();
return 0;
}
```
Applications of Heap
1. Priority Queue
2. Heap Sort Algorithm
3. Graph Algorithms
o

Dijkstra’s Algorithm

o

Prim’s Algorithm

4. Scheduling systems
5. Finding K largest/smallest elements

Tasks:
1.
2.
3.
4.
5.
6.

Create a Min Heap instead of Max Heap.
Insert 5 elements and display the heap.
Write function to find maximum element.
Use heap to implement a priority queue.
Solve: Find K largest elements using heap.
Compare heap vs binary search tree.

---

## 💻 Programs

1. [`01_min_heap.c`](./01_min_heap.c) — Min heap implementation (instead of max heap)
2. [`02_insert_and_display_heap.c`](./02_insert_and_display_heap.c) — Insert 5 elements into a heap and display it
3. [`03_find_maximum_element.c`](./03_find_maximum_element.c) — Find the maximum element in a heap
4. [`04_priority_queue_using_heap.c`](./04_priority_queue_using_heap.c) — Implement a priority queue using a heap
5. [`05_k_largest_elements.c`](./05_k_largest_elements.c) — Find the K largest elements using a heap

## 🛠️ How to compile & run

```bash
gcc 01_min_heap.c -o output
./output
```

Run the same way for any of the other 4 files in this folder — just swap the filename.
