#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first=NULL;

void create(int A[], int n) {
    int i;
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1; i<n; i++) {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void rdisplay(struct node *p) {
    if(p!=NULL) {
        printf("%d ", p->data);
        rdisplay(p->next);
    }
}

int count(struct node *p) {
    int l=0;
    while(p) {
        l++;
        p=p->next;
    }
    return l;
}
int Rcount(struct node *p) {
    if(p)
        return Rcount(p->next)+1;
    else
        return 0;
}

int sum(struct node *p) {
    int sum=0;
    while(p) {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int Rsum(struct node *p) {
    if(p)
        return Rsum(p->next)+p->data;
    else
        return 0;
}

int max(struct node *p) {
    int max=INT_MIN;
    while(p) {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}
int rmax(struct node *p) {
    int x=0;
    if(p==0)
        return INT_MIN;
    x=rmax(p->next);
    if(x>p->data)
        return x;
    else
        return p->data;
}

struct node* LSearch(struct node *p, int key) {
    struct node* q;
    while(p!=NULL) {
        if(key==p->data) {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
};
struct node*RSearch(struct node *p, int key) {
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next, key);
};

void insert(struct node *p, int index, int x) {
    struct node *t;
    if(index <0 || index > count(p))
        return;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    if(index==0) {
        t->next=first;
        first=t;
    }
    else {
        for(int i=0; i<index-1; i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }

}

void SortedInsert(struct node *p, int x) {
    struct node *t,*q=NULL;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=t;
    else {
        while(p && p->data<x) {
            q=p;
            p=p->next;
        }
        if(p==first) {
            t->next=first;
            first=t;
        } else {
            t->next=q->next;
            q->next=t;
        }
    }
}

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    SortedInsert(first,35);
    rdisplay(first);
    printf("\n");
    return 0;
}
