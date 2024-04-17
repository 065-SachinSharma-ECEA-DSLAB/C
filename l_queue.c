#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == -1 && front == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else if (rear == N - 1) {
        printf("Overflow !!\n");
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (rear == -1 && front == -1) {
        printf("Underflow !!\n");
    } else if (rear == front) {
        front = rear = -1;
    } else {
        printf("The dequeued element from the queue is %d\n", queue[front]);
        front++;
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("The top or front element is %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i < rear + 1; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() { // Change void main() to int main() and return 0 at the end
    int x,choice;

    do {
        printf("\nMenu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                printf("Element to enqueue: ");
                scanf("%d", &x); // Add & before x to read the integer input
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Incorrect choice\n");
        }
    } while (choice != 5);

    return 0; // Return 0 to indicate successful execution
}
