#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap helper
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up (after insert)
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down (after extract)
void heapifyDown(int i) {
    int smallest = i;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

// Insert
void insert(int val) {
    if (size == MAX)
        return;

    heap[size] = val;
    heapifyUp(size);
    size++;
}

// Extract Min
void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

// Peek
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
}

int main() {
    int N, val;
    char op[20];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            scanf("%d", &val);
            insert(val);
        } 
        else if (op[0] == 'e') { // extractMin
            extractMin();
        } 
        else if (op[0] == 'p') { // peek
            peek();
        }
    }

    return 0;
}