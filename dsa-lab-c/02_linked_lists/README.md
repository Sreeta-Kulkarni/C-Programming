# Linked Lists (Self-Referential Structures & Dynamic Memory Allocation)
## 💻 Programs

1. [`01_insert_at_beginning.c`](./01_insert_at_beginning.c) — Insert a node at the beginning of a singly linked list
2. [`02_delete_from_end.c`](./02_delete_from_end.c) — Delete a node from the end of a singly linked list
3. [`03_circular_singly_linked_list.c`](./03_circular_singly_linked_list.c) — Implement a circular singly linked list
4. [`04_menu_driven_linked_list.c`](./04_menu_driven_linked_list.c) — Menu-driven program: insertion, deletion, traversal

## 🛠️ How to compile & run

```bash
gcc 01_insert_at_beginning.c -o output
./output
```

Run the same way for any of the other 3 files in this folder — just swap the filename.

## 📖 Theory

Lab 2: Linked Lists Using Self-Referential Structures and Dynamic Memory Allocation.  
Aim of the Experiment  
To study and implement linked lists using self-referential structures and dynamic memory
allocation in C, and to understand the types of linked lists and their applications.  
Learning Objectives  
After completing this experiment, the student will be able to:
- Understand the concept of self-referential structures

- Create and manipulate linked lists in C

- Use dynamic memory allocation for node creation

- Implement different types of linked lists

- Apply linked lists to solve real-world problems

Structure in C
A structure is a user-defined data type that allows grouping of variables of different data types
under a single name.
Example:
struct student {
int roll;
char name[20];
};

Self-Referential Structure
A self-referential structure is a structure that contains a member which is a reference to the
same structure type.
General Form:
struct node {
int data;
struct node *next;
};

Explanation:
- data stores the value

- next stores the address of another structure of the same type

- This allows structures to be linked together dynamically

Self-referential structures are the foundation of linked lists.
Dynamic Memory Allocation
Linked list nodes are created at runtime using dynamic memory allocation functions such as:
- malloc() – allocates memory

- free() – releases memory

Example:
struct node *newnode;
newnode = (struct node*)malloc(sizeof(struct node));

Linked List
Definition
A linked list is a linear data structure consisting of nodes, where each node contains:
1. Data
2. A reference to the next node in the list
Nodes are not stored in contiguous memory locations.
Representation:

Types of Linked Lists
1. Singly Linked List
2. Doubly Linked List
3. Circular Singly Linked List
4. Circular Doubly Linked List

Singly Linked List
Structure Definition:
struct node {
int data;
struct node *next;
};

Example: Creation and Traversal of Singly Linked List
```c
#include <stdio.h>
#include <stdlib.h>
struct mystruct {
int data;
struct mystruct *next;
};
int main() {
struct mystruct *p1, *p2, *p3;
struct mystruct *temp;
```
/* Dynamic memory allocation */  
p1 = (struct mystruct *)malloc(sizeof(struct mystruct));  
p2 = (struct mystruct *)malloc(sizeof(struct mystruct));  
p3 = (struct mystruct *)malloc(sizeof(struct mystruct));  
/* Assign data and link nodes */  
p1->data = 10; p1->next = p2;  
p2->data = 20; p2->next = p3;  
p3->data = 30; p3->next = NULL;  
/* Traversal of singly linked list */  
temp = p1;  
printf("Singly Linked List:\n");  

while (temp != NULL) {  
printf("%d -> ", temp->data);  
temp = temp->next;  
}  
printf("NULL\n");  
/* Free allocated memory */  
free(p1);  
free(p2);  
free(p3);  
return 0;  
}

Doubly Linked List  
Structure Definition:  
struct node {  
int data;  
struct node *prev;  
struct node *next;  
};

Example 2: Creation and Traversal of Doubly Linked List
```c
#include <stdio.h>
#include <stdlib.h>
struct mystruct {
int data;
struct mystruct *prev;
struct mystruct *next;
};

int main() {
struct mystruct *p1, *p2, *p3;
struct mystruct *temp;
```
/* Dynamic memory allocation */  
p1 = (struct mystruct *)malloc(sizeof(struct mystruct));  
p2 = (struct mystruct *)malloc(sizeof(struct mystruct));  
p3 = (struct mystruct *)malloc(sizeof(struct mystruct));  
/* Assign data */  
p1->data = 10;  
p2->data = 20;  
p3->data = 30;  
/* Linking nodes */  
p1->prev = NULL; p1->next = p2;  
p2->prev = p1; p2->next = p3;  
p3->prev = p2; p3->next = NULL;  
/* Forward traversal */  
temp = p1;  
printf("Doubly Linked List (Forward):\n");  
while (temp != NULL) {  
printf("%d <-> ", temp->data);  
temp = temp->next;  
}  
printf("NULL\n");  
/* Backward traversal */  
temp = p3;  
printf("Doubly Linked List (Backward):\n");  
while (temp != NULL) {  
printf("%d <-> ", temp->data);

temp = temp->prev;  
}  
printf("NULL\n");  
/* Free allocated memory */  
free(p1);  
free(p2);  
free(p3);  
return 0;  
}

Applications of Linked Lists:
- Implementation of stacks and queues

- Polynomial representation

- Dynamic memory management

- Undo and redo operations

- Music playlist management

- Graph representation

Advantages and Disadvantages:
Advantages
- Dynamic size

- Efficient insertion and deletion

- No memory wastage

Disadvantages
- Extra memory for links

- Sequential access only

- More complex implementation than arrays

Result:
Linked lists were successfully implemented using self-referential structures and dynamic
memory allocation in C, and their types and applications were studied.
Tasks:
1. Write a C program to insert a node at the beginning of a singly linked list.
2. Write a program to delete a node from the end of a singly linked list.
3. Implement a circular singly linked list.
4. Write a menu-driven program to perform:
- •
- Insertion
Deletion
Traversal

Note: This manual is prepared based on the topics discussed in class and the current syllabus
coverage. Terminology and programming concepts will be updated in upcoming classes, and the
revised versions will be used thereafter.

---

