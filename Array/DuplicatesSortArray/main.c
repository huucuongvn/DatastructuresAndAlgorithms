#include <stdio.h>
#include <stdlib.h>

int main() {

    int arr[10]={3,6,8,8,10,12,15,15,15,20};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n-1; i++) {
        if(arr[i]==arr[i+1]) {
            int j=i+1;
            while(arr[j]==arr[i])
                j++;
            printf("%d is appearing %d time\n", arr[i], j-i);
            i=j-1;
        }
    }
    return 0;
}
