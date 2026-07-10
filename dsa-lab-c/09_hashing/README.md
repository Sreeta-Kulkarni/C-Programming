# Hash Tables

## 📖 Theory

Experiment 9: Hash Tables
Aim: To implement hash table using various collision resolution techniques, and its applications.

What is a Hash Table?
A hash table is a data structure that stores key-value pairs and allows fast access using a hash
function.
Average Time Complexity:
Search: O(1)
Insert: O(1)
Delete: O(1)

Hash Function
A hash function converts a key into an index:
ℎ(𝑘) = 𝑘 mod 𝑚
Where:
𝑘= key
𝑚= size of table

Collision: When two keys map to the same index.

Collision Resolution Techniques
1. Separate Chaining
- Each index stores a linked list.

- Collisions are stored as nodes in the list.

Pros:
- Simple

- No clustering

Cons:
- Extra memory required

2. Linear Probing (Open Addressing)
If a slot is occupied, move to the next slot.
ℎ(𝑘, 𝑖) = (ℎ(𝑘) + 𝑖)mod 𝑚
Pros:
- No extra memory

Cons:
- Clustering problem

Algorithm
Insertion (Linear Probing)
1. Compute index using hash function.
2. If slot empty → insert.
3. Else → move to next slot.
4. Repeat until empty slot found.
Search
1. Compute hash index.
2. If key found → return position.
3. Else → check next slot.

Example
Hash Table Size = 10
Keys: 23, 43, 13
Step 1:
23 % 10 = 3 → Insert at index 3
Step 2:
43 % 10 = 3 → Collision
Check next → index 4 → Insert
Step 3:
13 % 10 = 3 → Collision
Check index 4 → occupied
Check index 5 → Insert

Final Table:
Index
3

23

4

43

5

13

Example Program 1: Linear Probing
```c
#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];

void init() {
```
Value

for(int i = 0; i < SIZE; i++)
hashTable[i] = -1;
}
int hashFunction(int key) {
return key % SIZE;
}
void insert(int key) {
int index = hashFunction(key);
while(hashTable[index] != -1) {
index = (index + 1) % SIZE;
}
hashTable[index] = key;
}

void display() {
for(int i = 0; i < SIZE; i++) {
printf("%d : %d\n", i, hashTable[i]);
}
}

int main() {
init();
insert(23);
insert(43);
insert(13);
display();
return 0;
}

Example Program 2: Separate Chaining
```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct node {
int data;
struct node* next;
};

struct node* hashTable[SIZE];

int hashFunction(int key) {
return key % SIZE;
}

void insert(int key) {
int index = hashFunction(key);

struct node* newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = key;
newNode->next = NULL;

if(hashTable[index] == NULL) {
hashTable[index] = newNode;
} else {
struct node* temp = hashTable[index];
while(temp->next != NULL)

temp = temp->next;
temp->next = newNode;
}
}

void display() {
for(int i = 0; i < SIZE; i++) {
struct node* temp = hashTable[i];
printf("%d :", i);
while(temp != NULL) {
printf(" %d ->", temp->data);
temp = temp->next;
}
printf(" NULL\n");
}
}

int main() {
for(int i = 0; i < SIZE; i++)
hashTable[i] = NULL;

insert(23);
insert(43);
insert(13);
display();
return 0;
}
```
Applications of Hash Tables
Database Indexing: Used in MySQL to quickly find records like user IDs or products.
Caching Systems: Used in Google Chrome and Redis to load data faster.
Compilers (Symbol Tables): Used in GCC to store variables and their details during
compilation.
Password Storage: Platforms like Google store hashed passwords for secure login.
Large Data Search: Used in Apache Hadoop for fast searching in big datasets.
Gaming: Used in Unity for inventory systems, leaderboards, and real-time object lookup.
Scientific Computing: Used in MATLAB for caching results and simulations.
“Hash tables are used wherever fast lookup and real-time performance are required.”

Tasks:
1.
2.
3.
4.
5.
6.
7.

Insert at least 10 elements and display table.
Implement search operation.
Implement deletion in linear probing.
Modify program to use quadratic probing.
Calculate load factor.
Implement double hashing.
Use hash table for:
• Word frequency counter
• Student record storage

---

## 💻 Programs

1. [`01_insert_and_display_table.c`](./01_insert_and_display_table.c) — Insert at least 10 elements and display the hash table
2. [`02_search_operation.c`](./02_search_operation.c) — Implement the search operation on a hash table
3. [`03_deletion_linear_probing.c`](./03_deletion_linear_probing.c) — Implement deletion using linear probing
4. [`04_quadratic_probing.c`](./04_quadratic_probing.c) — Hash table using quadratic probing
5. [`05_load_factor.c`](./05_load_factor.c) — Calculate the load factor of the hash table
6. [`06_double_hashing.c`](./06_double_hashing.c) — Implement double hashing
7. [`07_word_frequency_counter.c`](./07_word_frequency_counter.c) — Application: word frequency counter
8. [`08_student_record_storage.c`](./08_student_record_storage.c) — Application: student record storage

## 🛠️ How to compile & run

```bash
gcc 01_insert_and_display_table.c -o output
./output
```

Run the same way for any of the other 7 files in this folder — just swap the filename.
