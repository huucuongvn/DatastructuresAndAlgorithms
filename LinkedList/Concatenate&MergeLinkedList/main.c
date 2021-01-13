#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

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
void create2(int A[], int n) {
    int i;
    struct node *t,*last;
    second=(struct node*)malloc(sizeof(struct node));
    second->data=A[0];
    second->next=NULL;
    last=second;
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

void Concat(struct node *p, struct node *q) {
    third=p;
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
}
void Merge(struct node *p,struct node *q) {
    struct node *last;
    if(p->data<q->data) {
        third=last=p;
        p=p->next;
        third->next=NULL;
    } else {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q) {
        if(p->data < q->data) {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        } else {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p) last->next=p;
    if(q) last->next=q;
}

int main()
{
    int A[]={10,20,30,40,50};
    int B[]={5,15,25,35,45};
    create(A,5);
    create2(B,5);
    Merge(first,second);
    printf("Merge\n");
    rdisplay(third);
    printf("\n\n");

    return 0;
}
