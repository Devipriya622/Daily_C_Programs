//Simulate a round-robin CPU scheduler using a circular queue.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
}

int dequeue() {
    if (front == -1) return -1;
    int x = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return x;
}

int isEmpty() {
    return front == -1;
}

int main() {
    int n, tq;
    int bt[MAX], rt[MAX];
    printf("Size : ");
    scanf("%d", &n);
   printf("Burst Time: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        enqueue(i);
    }
     printf("Time Quantum : ");
    scanf("%d", &tq);

    int time = 0;

    while (!isEmpty()) {
        int i = dequeue();

        if (rt[i] > tq) {
            time += tq;
            rt[i] -= tq;
            enqueue(i);
        } else {
            time += rt[i];
            rt[i] = 0;
            printf("Process : P%d Finish Time: %d\n", i + 1, time);
        }
    }

    return 0;
}
