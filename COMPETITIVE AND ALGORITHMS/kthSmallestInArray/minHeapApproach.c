#include<stdio.h>
#include<stdlib.h>

void _minHeapify(int* a, int lb, int ub, int i)
{
    int left,right,min,t;
    min = i;
    left = ((i-lb)*2)+1+lb;
    right = left+1;
    if(left<=ub)
    {
        min = a[left]<a[min] ? left : min;
    }
    if(right<=ub)
    {
        min = a[right]<a[min] ? right : min;
    }
    if(min!=i)
    {
        t = a[min];
        a[min] = a[i];
        a[i] = t;
        _minHeapify(a,lb,ub,min);
    }
}
void minHeapify(int* a, int lb, int ub)
{
    int lastParent = ((ub-lb-1)/2)+lb;
    while(lastParent>=lb)
    {
        _minHeapify(a,lb,ub,lastParent);
        lastParent--;
    }
}
int findKthSmallest(int* a, int lb, int ub, int k)
{
    int i, t;
    minHeapify(a, lb, ub);
    for(i=1;i<k;i++)
    {
        t = a[lb];
        a[lb] = a[ub];
        a[ub] = t;
        ub--;
        _minHeapify(a,lb,ub,lb);
    }
    return a[lb];
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