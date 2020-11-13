#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10]={8,3,6,4,6,5,6,8,2,7};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n-1; i++) {
        int count=1;
        if(arr[i]!=-1) {
            for(int j= i+1; j<n; j++) {
                if(arr[i]==arr[j]) {
                    count++;
                    arr[j]=-1;
                }
            }
            if(count>1)
                printf("%d apprearing %d time\n", arr[i], count);
        }
    }

    return 0;
}
