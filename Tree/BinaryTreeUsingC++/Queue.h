#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdio.h>

class Node {
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue {
private:
    int front;
    int rear;
    int size;
    struct Node **Q;
public:
    Queue() {front=rear=-1; size=10; Q=new struct Node *[size];}
    Queue (int size) {front=rear=-1; this->size=size; Q=new struct Node*[this->size];}
    void enqueue(struct Node *x);
    struct Node *dequeue();
    int isEmpty(){return front==rear;}
    void Display();
};

void Queue::enqueue(struct Node *x) {
    if(rear==size-1)
        printf("Queue Full\n");
    else {
        rear++;
        Q[rear]=x;
    }
}

struct Node *Queue::dequeue() {
    Node *x=NULL;
    if(front==rear)
        printf("Queue is Empty\n");
    else {
        x=Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display() {
    for(int i=front+1; i<=rear; i++)
        printf("%d ", Q[i]);
    printf("\n");
}

#endif // QUEUE_H_INCLUDED
