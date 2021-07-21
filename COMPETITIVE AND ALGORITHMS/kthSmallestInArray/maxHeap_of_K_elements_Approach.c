#include<stdio.h>
#include<stdlib.h>

void _maxHeapify(int* a, int lb, int ub, int i)
{
    int left,right,max,t;
    max = i;
    left = ((i-lb)*2)+1+lb;
    right = left+1;
    if(left<=ub)
    {
        max = a[left]>a[max] ? left : max;
    }
    if(right<=ub)
    {
        max = a[right]>a[max] ? right : max;
    }
    if(max!=i)
    {
        t = a[max];
        a[max] = a[i];
        a[i] = t;
        _maxHeapify(a,lb,ub,max);
    }
}
void maxHeapify(int* a, int lb, int ub)
{
    int lastParent = ((ub-lb-1)/2)+lb;
    while(lastParent>=lb)
    {
        _maxHeapify(a,lb,ub,lastParent);
        lastParent--;
    }
}
int findKthSmallest(int* a, int lb, int ub, int k)
{
    int i, t;
    maxHeapify(a, lb, lb+k-1); 
    for(i=lb+k;i<=ub;i++)
    {
        if(a[i]<a[lb])
        {
            t = a[i];
            a[i] = a[lb];
            a[lb] = t;
            _maxHeapify(a, lb, lb+k-1, 0);
        }
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