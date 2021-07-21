#include<stdio.h>
#include<stdlib.h>
int findKthSmallest(int* a, int lb, int ub, int k)
{
    k = lb+k-1;
    int i=lb, j=ub, t;
    while(i!=j)
    {
        for(i=lb;i<k;i++)
            if(a[i]>a[k])
            {
                t = a[i];
                a[i] = a[k];
                a[k] = t;
                break;
            }
        for(j=ub;j>k;j--)
            if(a[j]<a[k])
            {
                t = a[j];
                a[j] = a[k];
                a[k] = t;
                break;
            }
    }
    return a[k];
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