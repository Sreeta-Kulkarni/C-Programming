#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert (enqueue)
void insert(int value) {
    if (size == MAX)
        return; // overflow ignored

    pq[size++] = value;
}

// Delete (remove highest priority = smallest element)
void deleteMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = 0;

    // Find smallest element
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex])
            minIndex = i;
    }

    // Print deleted element
    printf("%d\n", pq[minIndex]);

    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Peek (get highest priority element)
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int min = pq[0];

    for (int i = 1; i < size; i++) {
        if (pq[i] < min)
            min = pq[i];
    }

    printf("%d\n", min);
}

int main() {
    int N, value;
    char op[10];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            scanf("%d", &value);
            insert(value);
        } 
        else if (op[0] == 'd') { // delete
            deleteMin();
        } 
        else if (op[0] == 'p') { // peek
            peek();
        }
    }

    return 0;
}