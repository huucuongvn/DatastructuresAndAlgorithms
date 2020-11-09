#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {
    printf("\nElement are\n");
    for(int i=0; i<arr.length; i++) {
        printf("%d\n", arr.A[i]);
    }
}
void swap(int *x,int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(struct Array *arr,int key) {
    for(int i=0; i<arr->length; i++) {
        if(key==arr->A[i]) {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

void inSert(struct Array *arr,int index,int x) {
    int i;
    if(index>=0 && index<=arr->length) {
        for(i=arr->length; i>index; i--) {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int delete(struct Array *arr,int index) {
    int x=0;
    if(index>=0 && index<arr->length) {
        x=arr->A[index];
        for(int i=index; i<arr->length-1; i++) {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int Sum(struct Array arr) {
    int s=0;
    for(int i=0; i<arr.length; i++) {
        s+=arr.A[i];
    }
    return s;
}


int main()
{
    int ch;
    int x,index;
    struct Array arr1;
    printf("Enter Size of Array ");
    scanf("%d", &arr1.size);
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.length = 0;
    do {
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("enter your choice ");
    scanf("%d",&ch);

    switch(ch) {
        case 1: printf("Enter an element and index ");
            scanf("%d%d",&x, &index);
            inSert(&arr1,index,x);
            break;
        case 2: printf("Enter index ");
            scanf("%d", &index);
            x=delete(&arr1,index);
            printf("Delete Element is %d\n",x);
            break;
        case 3: printf("Enter element to search ");
            scanf("%d", &x);
            index=linearSearch(&arr1,x);
            printf("Element index %d\n", index);
            break;
        case 4: printf("Sum is %d\n", Sum(arr1));
            break;
        case 5: Display(arr1);

    }
    } while(ch<6);

    return 0;
}
