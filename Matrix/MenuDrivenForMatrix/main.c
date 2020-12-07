#include <stdio.h>
#include <stdlib.h>

// Menu Driven for Diagonal
int main()
{
    int *A,n,ch,x,j,i;
    printf("Enter Dimension:\n");
    scanf("%d", &n);
    A= (int*)malloc(n*sizeof(int));
    do {
        //Display Menu
        //1.Creat
        //2.Get
        //3.Set
        //4.Dispaly
        printf("Enter a choice:");
        scanf("%d", &ch);
        switch(ch) {
            case 1: for(i=1; i<=n; i++) {
                    scanf("%d", &A[i-1]);
                    }
                    break;
            case 2: printf("Enter Indicies:\n");
                    scanf("%d%d", &i, &j);
                    if(i==j) printf("%d\n", A[i-1]);
                    else printf("0\n");
            case 3: printf("Enter Row,Column and Element\n");
                    scanf("%d%d%d", &i, &j, &x);
                    if(i==j) A[i-1]=x;
                    break;
            case 4: for(i=1; i<=n; i++) {
                        for(j=1; j<=n; j++) {
                            if(i==j) printf("%d ", A[i-1]);
                            else printf("0 ");
                        }
                        printf("\n");
                    }
        }
    }
    while(n<=10);

    return 0;
}
