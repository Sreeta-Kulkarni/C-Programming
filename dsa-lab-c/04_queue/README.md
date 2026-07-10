# Queue Data Structure

## 💻 Programs

1. [`01_front_rear_isempty_isfull.c`](./01_front_rear_isempty_isfull.c) — Queue with Front, Rear, IsEmpty and IsFull operations
2. [`02_circular_queue.c`](./02_circular_queue.c) — Circular queue implementation using an array
3. [`03_printer_queue_simulation.c`](./03_printer_queue_simulation.c) — Simulate a printer queue system using a queue
4. [`04_multiple_queues_single_array.c`](./04_multiple_queues_single_array.c) — Implement multiple queues in a single array

## 🛠️ How to compile & run

```bash
gcc 01_front_rear_isempty_isfull.c -o output
./output
```

Run the same way for any of the other 3 files in this folder — just swap the filename.

## 📖 Theory

Experiment 4: Queue Data Structure
Aim
To demonstrate the use of arrays and linked lists to implement different variants of Queue Data
Structure, it’s operations and applications.
What is Queue?
A Queue is a linear data structure that follows the FIFO (First In First Out) principle.
This means:
- The first element inserted is the first element removed.

Basic Queue Operations:

Types of Queue Implementations
Queues can be implemented using:
1. Arrays
2. Linked Lists

Example Program 1: Queue Implementation Using Arrays
```c
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
if(rear == MAX - 1)
printf("Queue Overflow\n");
else
{
if(front == -1)
front = 0;
rear++;
queue[rear] = value;
}
}

void dequeue()
{
if(front == -1 || front > rear)
printf("Queue Underflow\n");
else
{
printf("Deleted element: %d\n", queue[front]);
front++;

}
}

void display()
{
if(front == -1)
printf("Queue is Empty\n");
else
{
for(int i = front; i <= rear; i++)
printf("%d ", queue[i]);
printf("\n");
}
}

int main()
{
enqueue(10);
enqueue(20);
enqueue(30);

display();

dequeue();
display();

return 0;
}
```
Example Program 2: Queue Implementation Using Linked List
```c
#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
struct node *temp;
temp = (struct node*)malloc(sizeof(struct node));

temp->data = value;
temp->next = NULL;

if(rear == NULL)
{
front = rear = temp;
}
else
{
rear->next = temp;

rear = temp;
}
}

void dequeue()
{
if(front == NULL)
printf("Queue Underflow\n");
else
{
struct node *temp = front;
printf("Deleted element: %d\n", temp->data);
front = front->next;
free(temp);
}
}

void display()
{
struct node *temp = front;

if(front == NULL)
printf("Queue is Empty\n");
else
{
while(temp != NULL)
{
printf("%d ", temp->data);

temp = temp->next;
}
printf("\n");
}
}

int main()
{
enqueue(5);
enqueue(10);
enqueue(15);

display();

dequeue();
display();

return 0;
}
```
Applications of Queue (This will be explained in more detail during the class.)
Queues are used in many real-world and computing scenarios:
1. CPU Scheduling
2. Printer Queue
3. Process Scheduling
4. Breadth First Search (BFS)
5. Call Center Waiting System
6. Network Packet Scheduling

Tasks:
1. Implement Front (to fetch front element), Rear (to fetch rear element), IsEmpty, and
IsFull functions wherever applicable.
2. Implement Circular Queue using arrays.
3. Write a program to simulate a printer queue system.
4. Write a program to implement multiple queues in a single array.

---
