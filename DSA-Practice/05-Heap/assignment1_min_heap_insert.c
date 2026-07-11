#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *b = *a;
    *a = temp;
}

void insert(int value) {
    size++;
    heap[size - 1] = value;

    int i = size - 1;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int parent = (i - 1) / 2;
        int temp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = temp;
        i = parent;
    }
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
}

int main() {
    insert(15);
    insert(10);
    insert(20);
    insert(5);

    printf("Min Heap elements:\n");
    display();

    return 0;
}