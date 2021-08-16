#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j,sum,currSum;
    int *a;
    printf("Entert Size of elements : ");
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        printf("Enter a Number : ");
        scanf("%d", &a[i]);
    }
    printf("Enter sum (for which the subarray is to be determined) : ");
    scanf("%d", &sum);

    for(i=0;i<n;i++){
        currSum = 0;
        for(j=i;j<n;j++)
        {
            currSum+=a[j];
            if(currSum == sum){
                printf("subarray with sum %d is: %d %d \n", sum, i, j);
                return 0;
            }
        }
    }
    return 0;
}