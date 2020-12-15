#include <stdio.h>
#include <stdlib.h>

struct element {
    int i;
    int j;
    int x;
};

struct sparse {
    int m;
    int n;
    int num;
    struct element *ele;
};

void create(struct sparse *s) {
    printf("Enter Dimensions ");
    scanf("%d%d", &s->m, &s->n);
    printf("Number of non-zero ");
    scanf("%d", &s->num);
    s->ele=(struct element *)malloc(s->num*sizeof(struct element));
    printf("Enter non-zero Elements ");
    for(int i=0; i<s->num; i++) {
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}
void display(struct sparse s) {
    int k=0;
    for(int i=0; i<s.m; i++) {
        for(int j=0; j<s.n; j++) {
            if(i==s.ele[k].i && j==s.ele[k].j)
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct sparse s;
    create(&s);
    display(s);
    return 0;
}
