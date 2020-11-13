#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10]={3,6,8,8,10,12,15,15,15,20};
    int A[20]={0};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) {
        A[arr[i]]++;
    }
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) {
        if(A[i]>1)
            printf("%d appearing %d time\n", i, A[i]);
    }
    return 0;
}
