#include<stdio.h>
#include<stdlib.h>
int findKthSmallest(int* a, int lb, int ub, int k)
{
    int i,j,t;
    for(i=lb;i<lb+k;i++)
    {
        for(j=ub;j>=i+1;j--)
        {
            if(a[j]<a[j-1])
            {
                t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
            }
        }
    }
    return a[lb+k-1];
}
int main()
{
    int k, n, *a, i, kthSmallest;
    printf("Program to find kth smallest element in an array of distinct elements\n");
    printf("Enter No. of elements : ");
    scanf("%d", &n);
    printf("Enter k : ");
    scanf("%d", &k);
    a = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        printf("Enter A Number : ");
        scanf("%d", &a[i]);
    }
    kthSmallest = findKthSmallest(a, 0, n-1, k);
    printf("for k = %d, kth smallest elements is : %d\n", k, kthSmallest);
    return 0;
}