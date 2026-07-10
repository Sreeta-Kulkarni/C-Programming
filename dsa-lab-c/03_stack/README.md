# Stack Data Structure

## 📖 Theory

Experiment 3: Stack Data Structure
Aim
To implement the Stack Data Structure using:
1. Array
2. Linked List
and to study its operations and applications.
What is a Stack?
A Stack is a linear data structure that follows the principle of:
LIFO (Last In First Out)
“The element inserted last is removed first.”
Real-Life Examples
- Stack of plates

- Undo/Redo operations

- Function call stack

Basic Operations of Stack:
Operation

Description

Push

Insert element

Pop

Remove element

Peek

View top element

isEmpty

Check if stack empty

isFull

Check overflow

Stack using Array and Linked List:

Using Array:
- •

Uses a fixed-size array
Maintains an index called top

Using Linked List
- Dynamic memory allocation

- No overflow (until memory full)

- Top points to first node

Errors in Stack
Overflow: Occurs when pushing into a full stack
Underflow: Occurs when popping from an empty stack

Example Program 1: Stack using Array
Algorithm (Push)
1. Check if top == MAX-1
2. If yes → Overflow
3. Else increment top
4. Insert element
Algorithm (Pop)
1. Check if top == -1
2. If yes → Underflow
3. Else return stack[top]
4. Decrement top
C Program:
```c
#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
```
/* Push */
void push(int value) {
if (top == MAX - 1) {
printf("Stack Overflow\n");
return;
}
stack[++top] = value;
}
/* Pop */

void pop() {
if (top == -1) {
printf("Stack Underflow\n");
return;
}
printf("Popped: %d\n", stack[top--]);
}
/* Peek */
void peek() {
if (top == -1)
printf("Stack is empty\n");
else
printf("Top element: %d\n", stack[top]);
}
/* Display */
void display() {
if (top == -1) {
printf("Stack empty\n");
return;
}
for (int i = top; i >= 0; i--)
printf("%d\n", stack[i]);
}
int main() {
push(10);

push(20);
push(30);
display();
pop();
peek();
return 0;
}

Example Program 2: Stack using Linked List
Algorithm (Push)
1. Create new node
2. newnode → next = top
3. top = newnode
Algorithm (Pop)
1. If top == NULL → Underflow
2. temp = top
3. top = top->next
4. free(temp)
C Program:
```c
#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};

struct Node *top = NULL;
```
/* Push */
void push(int value) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Overflow\n");
return;
}
newNode->data = value;
newNode->next = top;
top = newNode;
}
/* Pop */
void pop() {
if (top == NULL) {
printf("Underflow\n");
return;
}
struct Node *temp = top;
printf("Popped: %d\n", temp->data);
top = top->next;
free(temp);
}

/* Peek */
void peek() {
if (top == NULL)
printf("Stack empty\n");
else
printf("Top element: %d\n", top->data);
}
/* Display */
void display() {
struct Node *temp = top;
while (temp != NULL) {
printf("%d\n", temp->data);
temp = temp->next;
}
}

int main() {
push(5);
push(15);
push(25);
display();
pop();
peek();
return 0;
}

Applications of Stack:
1. Parenthesis Matching
Check if brackets are balanced.
Example:
Input: (a+b)
Output: Balanced
2. Infix to Postfix Conversion
A + B → AB+
3. Expression Evaluation
- Postfix evaluation

- Prefix evaluation

4. Recursion
- Function calls are managed using stack.

5. Undo/Redo Operations
- Used in editors.

Tasks
1. Implement menu-driven stack using array
2. Implement menu-driven stack using linked list
3. Check balanced parentheses
4. Convert infix to postfix
5. Evaluate postfix expression
6. Implement two stacks in one array
7. Reverse a string using stack

---

## 💻 Programs

1. [`01_stack_using_array_menu.c`](./01_stack_using_array_menu.c) — Menu-driven stack implementation using array
2. [`02_stack_using_linked_list_menu.c`](./02_stack_using_linked_list_menu.c) — Menu-driven stack implementation using linked list
3. [`03_balanced_parentheses.c`](./03_balanced_parentheses.c) — Check for balanced parentheses using a stack
4. [`04_infix_to_postfix.c`](./04_infix_to_postfix.c) — Convert an infix expression to postfix using a stack
5. [`05_evaluate_postfix.c`](./05_evaluate_postfix.c) — Evaluate a postfix expression using a stack
6. [`06_two_stacks_in_one_array.c`](./06_two_stacks_in_one_array.c) — Implement two stacks in a single array
7. [`07_reverse_string_using_stack.c`](./07_reverse_string_using_stack.c) — Reverse a string using a stack

## 🛠️ How to compile & run

```bash
gcc 01_stack_using_array_menu.c -o output
./output
```

Run the same way for any of the other 6 files in this folder — just swap the filename.
