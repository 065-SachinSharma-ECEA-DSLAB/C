#include <stdio.h>

#define N 5 

int stack[N]; 
int top1 = -1; 
int top2 = N; 


void push1(int x) {
    if (top1 <= top2 ) { 
        stack[++top1] = x; 
    } else {
        printf("Stack Overflow for Stack 1\n");
    }
}

void push2(int x) {
    if (top1 <= top2) { 
        stack[--top2] = x; 
    } else {
        printf("Stack Overflow for Stack 2\n");
    }
}

int pop1() {
    if (top1 >= 0) { 
        return stack[top1--]; 
    } else {
        printf("Stack Underflow for Stack 1\n");
        return -1; 
    }
}

int pop2() {
    if (top2 < N) { 
        return stack[top2++];
    } else {
        printf("Stack Underflow for Stack 2\n");
        return -1; 
    }
}

void display() {
    printf("Array : ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack[i]);
    }
    for (int i = N - 1; i >= top2; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main() {
    push1(1);
    push1(2);
    
    push2(7);
    push2(8);

    display();

    printf("Popped element from Stack 1: %d\n", pop1());
    printf("Popped element from Stack 2: %d\n", pop2());

    display();

    return 0;
}
