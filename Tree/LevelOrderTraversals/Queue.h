#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size) {
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x) {
    if(q->rear==q->size-1)
        printf("Queue id Full");
    else {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

struct Node *dequeue(struct Queue *q) {
        struct Node *x=NULL;
        if(q->front==q->rear)
            printf("Queue is Empty\n");
        else {
            q->front++;
            x=q->Q[q->front];
        }
        return x;
}

int isEmpty(struct Queue q) {
    return q.front==q.rear;
}

#endif // QUEUE_H_INCLUDED
