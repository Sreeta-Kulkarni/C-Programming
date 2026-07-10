# Searching Algorithms
## 💻 Programs

1. [`01_linear_search_count_comparisons.c`](./01_linear_search_count_comparisons.c) — Linear search modified to count number of comparisons
2. [`02_binary_search_recursive.c`](./02_binary_search_recursive.c) — Binary search implemented using recursion
3. [`03_search_with_input_validation.c`](./03_search_with_input_validation.c) — Search program with input validation
4. [`04_compare_linear_vs_binary_time.c`](./04_compare_linear_vs_binary_time.c) — Compare execution time of linear search vs binary search
5. [`05_search_multiple_elements.c`](./05_search_multiple_elements.c) — Search for multiple elements in a single run
6. [`06_binary_search_first_last_occurrence.c`](./06_binary_search_first_last_occurrence.c) — Binary search modified to find first and last occurrence

## 🛠️ How to compile & run

```bash
gcc 01_linear_search_count_comparisons.c -o output
./output
```

Run the same way for any of the other 5 files in this folder — just swap the filename.

## 📖 Theory

Experiment 5: Searching algorithms
Aim: To implement and understand various searching algorithms on data structures using the C
programming language.
Introduction
Searching is a fundamental operation in computer science used to locate an element in a data
structure. Efficient searching improves performance in applications like databases, file systems,
and AI systems.
Types of Searching Algorithms
1. Linear Search (Sequential Search)
- Searches element one by one from start to end.

- Works on both sorted and unsorted data.

- Simple but inefficient for large datasets.

Time Complexity:
- Best: O(1)

- Worst: O(n)

Example: You have the following list of marks:
[45, 78, 12, 89, 66]
Search for 89.
Solution: Step-by-Step Execution
Step

Index

Value

Comparison

1

0

45

45 ≠ 89

2

1

78

78 ≠ 89

3

2

12

12 ≠ 89

4

3

89

Found

2. Binary Search
- Works only on sorted arrays.

- Divides the search space into halves.

- Much faster than linear search.

Time Complexity:
- Best: O(1)

- Worst: O(log n)

Example: You are given a sorted array:
[10, 20, 30, 40, 50, 60, 70]
Search for 50.
Solution: Step-by-Step Execution
Step

Low

High

Mid

Value

1

0

6

3

40

Go right

2

4

6

5

60

Go left

3

4

4

4

50

Found

3. Interpolation Search
- Improves binary search for uniformly distributed data.

- Estimates position based on value.

Time Complexity:
- Best: O(1)

- Worst: O(n)

Action

Example: You are given a uniformly distributed array:
[10, 20, 30, 40, 50, 60, 70]
Search for 40.
Solution: We use the following formula to predict the position:

…(1)
From the data:
- •

low = 0, high = 6
key = 40

Element found at index 3 (position 4)

Worst Case Happens When Data is NOT Uniform
If elements are not evenly distributed, the formula gives a bad estimate, and the algorithm may:
- Move very slowly (almost one step at a time)

- Behave like linear search

Example of Worst Case: [1, 2, 3, 4, 5, 1000]
Search for 1000.

Example Program 1: Linear Search
```c
#include <stdio.h>

int main() {
int arr[100], n, i, key, found = 0;
printf("Enter number of elements: ");
scanf("%d", &n);

printf("Enter elements:\n");
for(i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}

printf("Enter element to search: ");
scanf("%d", &key);

for(i = 0; i < n; i++) {
if(arr[i] == key) {
printf("Element found at position %d\n", i + 1);
found = 1;
break;
}
}
if(!found) {
printf("Element not found\n");
}
return 0;
}
```
Example Program 2: Binary Search
```c
#include <stdio.h>

int main() {
int arr[100], n, i, key;
int low = 0, high, mid;

printf("Enter number of elements: ");
scanf("%d", &n);

printf("Enter sorted elements:\n");
for(i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}

printf("Enter element to search: ");
scanf("%d", &key);

high = n - 1;

while(low <= high) {
mid = (low + high) / 2;

if(arr[mid] == key) {
printf("Element found at position %d\n", mid + 1);
return 0;
}
else if(arr[mid] < key) {

low = mid + 1;
}
else {
high = mid - 1;
}
}

printf("Element not found\n");
return 0;
}
```
Example Program 3: Interpolation Search
```c
#include <stdio.h>

int main() {
int arr[100], n, i, key;
int low = 0, high, pos;

printf("Enter number of elements: ");
scanf("%d", &n);

printf("Enter sorted elements:\n");
for(i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}

printf("Enter element to search: ");
scanf("%d", &key);

high = n - 1;

while(low <= high && key >= arr[low] && key <= arr[high]) {
pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

if(arr[pos] == key) {
printf("Element found at position %d\n", pos + 1);
return 0;
}

if(arr[pos] < key) {
low = pos + 1;
} else {
high = pos - 1;
}
}

printf("Element not found\n");
return 0;
}
```
Tasks:
1.
2.
3.
4.
5.
6.

Modify linear search to count number of comparisons.
Implement binary search using recursion.
Add input validation in all programs.
Compare execution time of linear and binary search.
Write a program to search multiple elements in one run.
Modify binary search to find first and last occurrence.

SEARCHING
AIM: To implement and analyze different searching algorithms in C and study their time
complexity, space complexity, efficiency, and real-world applications.
INTRODUCTION :
Searching is a fundamental operation in computer science used to locate an element in a
dataset.
It directly affects:
• Performance of applications
• Efficiency of databases
• Speed of decision-making systems
TYPES OF SEARCHING
1. Linear Search
• Sequential search
• Works on sorted + unsorted data
2. Binary Search
• Works only on sorted data
• Uses divide and conquer
3. Interpolation Search
• Uses mathematical prediction
• Best for uniform distribution

LINEAR SEARCH:
CONCEPT:
• Start from index 0
• Compare each element with key
• Stop when found
MEMORY BEHAVIOR
• Array stored contiguously
• Access pattern:
arr[0] → arr[1] → arr[2] → ...
CPU cache-friendly but slow for large data

# Important Points:
1. Linear search is optimal for small datasets
2. No preprocessing needed
3. Used when data is unsorted or dynamic

# WHY LINEAR SEARCH AVERAGE CASE ≠ O(log n)
Total comparisons:
1 + 2 + 3 + ... + n
Formula:
= n(n+1)/2
Average:
= (n+1)/2 ≈ n/2
Big-O ignores constants:
n/2 → O(n)
That’s why:
Average case = O(n)
NOT O(log n)
Algorithm Behavior
Linear

checks one-by-one

Binary

cuts in half

BINARY SEARCH:
Reduce search space by half each step

HOW IT WORKS
Given sorted array:
[10, 20, 30, 40, 50, 60, 70]
Steps :
• Mid = (low + high)/2
• Compare
• Go left or right

# Important Points:
Works only on sorted data
• Each step cuts problem in half
Example:
n = 1,000,000
log₂n ≈ 20 steps only
- Comparison Between Linear & Binary Search:
Linear Search
- •

Worst case → n iterations
Example (n = 10000) → up to 10000 steps

Binary Search
- •

Worst case → log₂(n) iterations
Example (n = 10000):
log₂(10000) ≈ 14 steps only

Growth Comparison Table:
n

Linear Search

Binary Search

10

10

4

100

100

7

1000

1000

10

10000

10000

14

INTERPOLATION SEARCH:
How it works:
- •

Unlike binary search → does not go to middle
It predicts position using formula:

pos = low + ((key - arr[low]) * (high - low))
(arr[high] - arr[low])

Why iterations are low:
- If data is uniformly distributed, it directly jumps near the answer
That’s why sometimes it finds in 1 iteration

Important Edge Case:
if(low == high)
Prevents division by zero

# Important Points:
Faster than binary if data is uniform
• Fails badly if data is uneven
Example:
[1,2,3,4,5,1000]
behaves like linear
- *Interpolation search is an improvement over binary search for uniformly distributed
datasets and demonstrates how mathematical estimation can optimize search
performance.

Tasks:
1.
Modify linear search to count number of comparisons.

---
