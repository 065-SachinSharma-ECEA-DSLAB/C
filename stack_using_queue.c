#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
} Queue;

void enqueue(Queue* q, int x) {
    if (q->rear == q->size - 1) {
        q->data = (int*)realloc(q->data, 2 * q->size * sizeof(int));
        q->size *= 2;
    }
    q->data[++q->rear] = x;
}

int dequeue(Queue* q) {
    if (q->front == q->rear) {
        return -1;
    }
    return q->data[++q->front];
}

int front(Queue* q) {
    if (q->front == q->rear) {
        return -1;
    }
    return q->data[q->front + 1];
}

int size(Queue* q) {
    return q->rear - q->front;
}

typedef struct {
    Queue q1;
    Queue q2;
} Stack;

void push(Stack* s, int x) {
    enqueue(&s->q2, x);
    while (size(&s->q1) != 0) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

void pop(Stack* s) {
    if (size(&s->q1) == 0) {
        return;
    }
    dequeue(&s->q1);
}

int top(Stack* s) {
    if (size(&s->q1) == 0) {
        return -1;
    }
    return front(&s->q1);
}

int size_stack(Stack* s) {
    return size(&s->q1);
}

int main() {
    Stack s;
    s.q1.data = (int*)malloc(sizeof(int));
    s.q1.front = -1;
    s.q1.rear = -1;
    s.q1.size = 1;
    s.q2.data = (int*)malloc(sizeof(int));
    s.q2.front = -1;
    s.q2.rear = -1;
    s.q2.size = 1;

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("current size: %d\n", size_stack(&s));
    printf("%d\n", top(&s));
    pop(&s);
    printf("%d\n", top(&s));
    pop(&s);
    printf("%d\n", top(&s));

    printf("current size: %d\n", size_stack(&s));
    return 0;
}

