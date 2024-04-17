#include<stdio.h>
#define N 5
int queue[N];
int front =-1;
int rear=-1;

void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N ==front){
        printf("queue is full\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear ==-1){
        printf("stack is empty\n");
    }
    else if(front ==rear){
        front=rear-1;
    }else{
        printf("%d is dequeued\n",queue[front]);
        front =(front+1)%N;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("queue is empty\n");
    }else{
        int i=front;
        printf("\nQueue :");
        while(i !=rear){
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[rear]);
    }
    printf("\n");
}

void peek(){
    if(front ==-1 && rear ==-1){
        printf("stack is empty\n");
    }else{
        printf("%d is at peek",queue[front]);
    }
}

void main(){
    enqueue(6);
    enqueue(2);
    enqueue(3);
    enqueue(9);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    dequeue();
    enqueue(8);
    display();
}


