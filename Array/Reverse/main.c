#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[20];
    int size;
    int length;
};

void swap(int *x,int *y) {
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

void Display(struct Array arr) {
    printf("\nElement are\n");
    for(int i=0; i<arr.length; i++) {
        printf("%d\n", arr.A[i]);
    }
}

void reverse(struct Array *arr) {
    int *B;
    int i,j;
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1, j=0; i>=0; i--, j++) {
        B[j]=arr->A[i];
    }
    for(i=0; i<arr->length; i++) {
        arr->A[i]=B[i];
    }
}

void reverse2(struct Array *arr) {
    int i,j;
    for(i=0,j=arr->length-1; i<j; i++, j--) {
        swap(&arr->A[i],&arr->A[j]);
    }
}

int main()
{
    struct Array arr={{2,3,4,5,6},10,5};
    reverse2(&arr);
    Display(arr);
    return 0;
}
