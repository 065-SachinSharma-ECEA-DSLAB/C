#include<stdio.h>
#define N 5
int S1[N],S2[N];
int top1 =-1;
int top2 =-1;
int count =0;

void push1(int x){
    if(top1==N-1){
        printf("Overflow!!\n");
    }else{
        top1++;
        S1[top1]=x;
    }
}
void push2(int x){
    if(top2==N-1){
        printf("Overflow!!\n");
    }else{
        top2++;
        S2[top2]=x;
    }
}
int pop1(){
    return S1[top1--];
}
int pop2(){
    return S2[top2--];
}

void enqueue(int x){
    push1(x);
    count++;
}

void dequeue(){
    int i,a,b;
    if(top1==-1 && top2==-1){
        printf("queue is empty\n");
    }else{
        for(i=0;i<count;i++){
            a=pop1();
            push2(a);
        }
        b=pop2();
        printf("popped element is %d ",b);
        count--;
        for(i=0;i<count;i++){
            a=pop2();
            push1(a);
        }
    }
}

void display(){
    printf("\nelements: ");
    for(int i=0;i<=top1;i++){
        printf("%d ",S1[i]);
    }
}

void main(){
    enqueue(5);
    enqueue(0);
    enqueue(9);
    dequeue();
    display();
}