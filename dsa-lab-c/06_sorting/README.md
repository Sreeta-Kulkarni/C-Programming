# Sorting Algorithms

## 📖 Theory

Experiment 6: Sorting Algorithms
Aim: To implement common sorting algorithms in C and understand their working.

Introduction
Sorting is the process of arranging elements in a specific order (ascending or descending). It is
widely used in applications like searching, data analysis, and database management.

Types of sorting algorithms
1. Bubble Sort
Bubble Sort works by repeatedly comparing adjacent elements and swapping them if they are in
the wrong order. After each pass, the largest element moves to its correct position.
Example: Given
Array: [5, 3, 8, 4, 2]
Pass 1:
(5,3) → swap → [3,5,8,4,2]
(5,8) → no swap
(8,4) → swap → [3,5,4,8,2]
(8,2) → swap → [3,5,4,2,8]
Pass 2:
(3,5) → no swap
(5,4) → swap → [3,4,5,2,8]
(5,2) → swap → [3,4,2,5,8]
Pass 3:
(3,4) → no swap
(4,2) → swap → [3,2,4,5,8]
Pass 4:
(3,2) → swap → [2,3,4,5,8]
Final: [2,3,4,5,8]

Complexity Analysis of Bubble Sort:

Time Complexity:
Best Case: O(n) - The input array is already sorted. An optimized bubble sort includes a flag to
stop early after the first pass if no swaps are made.
Average Case: O(n²) - The input array is in a random or unsorted order.
Worst Case: O(n²) - The input array is sorted in reverse order (descending order when sorting in
ascending order).

Auxiliary Space: O(1)

Advantages of Bubble Sort:
- Simple and easy to understand and implement

- Requires no extra memory (in-place sorting)

- Stable sort (preserves order of equal elements)

Disadvantages of Bubble Sort:
- Very slow for large datasets (time complexity: O(n²))

- Rarely used in real-world applications; mainly for educational purposes

Example Program 1: Bubble Sort
```c
#include <stdio.h>
int main() {
int arr[] = {5, 3, 8, 4, 2};
int n = sizeof(arr) / sizeof(arr[0]);
int i, j, temp, swapped;
for(i = 0; i < n - 1; i++) {
swapped = 0; // optimization flag

for(j = 0; j < n - i - 1; j++) {
if(arr[j] > arr[j + 1]) {
// swap
temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
swapped = 1;
}
}
// stop if already sorted
if(swapped == 0)
break;
}
printf("Sorted array: ");
for(i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
return 0;
}
```
1. Selection Sort
Selection Sort is a comparison-based algorithm that repeatedly selects the smallest element from
the unsorted portion and places it in its correct position.
- Find the smallest element and swap it with the first position

- Then find the next smallest and place it in the second position

- Repeat until the entire array is sorted

Example: Given
Array: [64, 25, 12, 22, 11]
Pass 1:
Minimum = 11 → swap with 64
→ [11, 25, 12, 22, 64]
Pass 2:
Minimum = 12 → swap with 25
→ [11, 12, 25, 22, 64]
Pass 3:
Minimum = 22 → swap with 25
→ [11, 12, 22, 25, 64]
Pass 4:
Already sorted
Final: [11, 12, 22, 25, 64]

Complexity Analysis of Selection Sort:
Time Complexity: O(n²) – best, average, and worst case!
Auxiliary Space: O(1)

Advantages of Selection Sort:
- Simple and easy to understand

- Uses constant extra space (O(1))

- Requires fewer swaps compared to most sorting algorithms

Disadvantages of Selection Sort:
- Slow for large datasets (time complexity: O(n²))

- Not stable (does not preserve order of equal elements)

Example Program 2: Selection Sort
```c
#include <stdio.h>
int main() {
int arr[5] = {64,25,12,22,11};
int i,j,min,temp;
for(i=0;i<4;i++){
min=i;
for(j=i+1;j<5;j++){
if(arr[j]<arr[min])
min=j;
}
temp=arr[i];
arr[i]=arr[min];
arr[min]=temp;
}
for(i=0;i<5;i++)
printf("%d ", arr[i]);
return 0;
}

//Fixed size…change that in your implementation
```
3. Insertion Sort
Insertion Sort builds a sorted array one element at a time by placing each element in its correct
position within the sorted portion.
- Assume the first element is already sorted.

- Pick the next element and compare it with the previous elements.

- Shift larger elements to the right and insert the element at the correct position.

- Repeat until the entire array is sorted.

Example: Given
Array: [8, 3, 5, 2, 6]

Pass

Key

Comparisons / Shifts

Array After Pass

1

3

3 < 8 → shift 8

[3, 8, 5, 2, 6]

2

5

5 < 8 → shift 8

[3, 5, 8, 2, 6]

3

2

2 < 8, 5, 3 → shift all

[2, 3, 5, 8, 6]

4

6

6 < 8 → shift 8

[2, 3, 5, 6, 8]

“Pick → Compare → Shift → Insert”

Complexity Analysis of Insertion Sort:
Time Complexity:
O(n) – The input array is already sorted.
O(n²) – average, and worst case.
Auxiliary Space: O(1)

Advantages of Insertion Sort:
- Simple and easy to implement, stable sorting algorithm

- Efficient for small or nearly sorted arrays

- In-place (requires no extra memory). Adaptive: runs faster (O(n)) for already sorted data

Disadvantages of Insertion Sort:
- Inefficient for large datasets

- Slower than advanced algorithms like Merge Sort and Quick Sort

Example Program 3: Insertion Sort
```c
#include <stdio.h>
int main() {
int arr[5] = {12,11,13,5,6};
int i,j,key;
for(i=1;i<5;i++){
key=arr[i];
j=i-1;
while(j>=0 && arr[j]>key){
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}
for(i=0;i<5;i++)
printf("%d ", arr[i]);
return 0;
}

//Fixed size…change that in your implementation
```
Tasks:

1.
2.
3.
4.

Modify Bubble Sort to sort elements in descending order.
Write a program to count number of swaps and comparisons in Bubble Sort.
Write a program to sort an array entered by the user (dynamic input).
Write a program that sorts only even numbers in an array while keeping odd numbers in
their positions.
5. Implement Selection Sort and display the array after each pass.
6. Implement Insertion Sort and print intermediate steps.

SORTING
Aim: To implement and analyze common sorting algorithms in C and study their time
complexity, space complexity, working, and real-world applications.
INTRODUCTION
Sorting is the process of arranging data in a specific order (ascending or descending). It
plays a crucial role in improving efficiency of searching, data processing, and optimization
problems.
Sorting is widely used in:
• Databases (indexing)
• Search engines
• Data analysis systems
• Real-time applications
TYPES OF SORTING
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
Sorting is not just rearranging elements. It is about minimizing operations like comparisons,
swaps, and memory usage while organizing data efficiently.

BUBBLE SORT
CONCEPT:
Compare adjacent elements , Swap if wrong
Largest element goes to end after each pass

MEMORY BEHAVIOR
Array stored contiguously
• Swapping changes actual memory positions
arr[j] ↔ arr[j+1]
- STEP FLOW
Example:
[5, 3, 8, 4, 2]
Pass 1:
• 5↔3 → swap
• 8↔4 → swap
• 8↔2 → swap
Largest goes to end

IMPORTANT CONCEPT
After each pass:
Last element = sorted

Important Points:
Bubble sort is:
• Stable
• In-place
• Adaptive (if optimized)
WHY Bubble sort is SLOW?
Because: Every element is compared with every other

SELECTION SORT
CONCEPT:
Find minimum
Place at correct position

MEMORY BEHAVIOR
- •

Only 1 swap per pass
Less memory movement

FLOW
Example:
[64, 25, 12, 22, 11]
Pass 1:
Find min (11) → swap with 64
IMPORTANT
Unlike bubble:
• Doesn’t swap repeatedly

Finds minimum first
Not stable
Less swaps but still slow
- INSERTION SORT
CONCEPT
Build sorted part step-by-step
MEMORY BEHAVIOR
Shifting happens:
arr[j+1] = arr[j]
No swapping → shifting
FLOW
Example:
[8, 3, 5, 2, 6]
Pass:
• Insert 3 before 8
• Insert 5 correctly
KEY IDEA
Pick → Compare → Shift → Insert

WHY FAST SOMETIMES?
If nearly sorted then Very few shifts

# Bubble sort repeatedly swaps elements, causing more memory writes.
Selection sort minimizes swaps but still scans entire array.
Insertion sort shifts elements, which is efficient when data is partially sorted.

REAL WORLD APPLICATION
Bubble:
• Educational
Selection:
• Memory-constrained systems
Insertion:
• Real-time systems
• Small datasets
• Hybrid algorithms

Tasks:
1.
Modify Bubble Sort to sort elements in descending order.

---

## 💻 Programs

1. [`01_bubble_sort_descending.c`](./01_bubble_sort_descending.c) — Bubble sort modified to sort in descending order
2. [`02_bubble_sort_count_swaps_comparisons.c`](./02_bubble_sort_count_swaps_comparisons.c) — Bubble sort with swap and comparison counters
3. [`03_sort_dynamic_input.c`](./03_sort_dynamic_input.c) — Sort an array with dynamic (user-entered) input
4. [`04_sort_even_numbers_only.c`](./04_sort_even_numbers_only.c) — Sort only even numbers in an array, keeping odd numbers in place
5. [`05_selection_sort_per_pass.c`](./05_selection_sort_per_pass.c) — Selection sort, displaying the array after every pass
6. [`06_insertion_sort_intermediate_steps.c`](./06_insertion_sort_intermediate_steps.c) — Insertion sort, printing intermediate steps

## 🛠️ How to compile & run

```bash
gcc 01_bubble_sort_descending.c -o output
./output
```

Run the same way for any of the other 5 files in this folder — just swap the filename.
