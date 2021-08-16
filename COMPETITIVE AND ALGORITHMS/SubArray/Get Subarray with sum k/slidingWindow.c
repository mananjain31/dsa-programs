#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j,sum,currSum,lb,ub;
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

    lb = ub = 0;
    currSum=a[ub];
    do
    {
        if(currSum < sum)
        {
            ub++;
            if(ub >= n) break;
            currSum+=a[ub];
            // printf("currSum < sum %d %d lb ub %d %d\n", currSum, sum, lb, ub);
        }
        if(currSum > sum)
        {
            currSum-=a[lb];
            lb++;
            // printf("currSum > sum %d %d lb ub %d %d\n", currSum, sum, lb, ub);
        }
        if(currSum == sum){
            printf("Subarray : %d - %d\n", lb, ub);
            return 0;
        }
    }while(1);
    printf("Subarray Not Present\n");
    return 0;
}