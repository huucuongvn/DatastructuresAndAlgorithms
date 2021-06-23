#include "Queue.h"
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


struct Stack {
    int size;
    int top;
    struct Node **S;
};

void Stackcreate(struct Stack *st,int size) {
    st->size=size;
    st->top=-1;
    st->S=(struct Node **)malloc(st->size*sizeof(struct Node*));
}

void push(struct Stack *st, struct Node *x) {
    if(st->top==st->size-1)
        printf("Stack overflow\n");
    else {
        st->top++;
        st->S[st->top]=x;
    }
}

struct Node *pop(struct Stack *st) {
    struct Node *x=NULL;
    if(st->top==-1)
        printf("Stack Underflow\n");
    else {
        x=st->S[st->top--];
    }
    return x;
};

int isEmptyStack(struct Stack st) {
    if(st.top==-1)
        return 1;
    return 0;
}

int IsFullStack(struct Stack st) {
    return st.top==st.size-1;
}

#endif // STACK_H_INCLUDED