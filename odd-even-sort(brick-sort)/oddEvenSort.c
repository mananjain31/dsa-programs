#include<stdio.h>
#include<stdlib.h>
void oddEvenSort(int *a, int si, int ei)
{
	int i,j,flag,k;
	do
	{
		flag = 0;
		for(i=1;i>=0;i--)
		{
			for(j=si+i;j+1<=ei;j+=2)
			{
				if(a[j]>a[j+1])
				{
					k = a[j];
					a[j] = a[j+1];
					a[j+1] = k;
					flag = 1;
				}
			}
		}
	}while(flag==1);
}
int main()
{
	int n,i;
	int *a;
	printf("Enter Collection size -> ");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		printf("Enter a Number : ");
		scanf("%d", a+i);
	}
	oddEvenSort(a,0,n-1);
	for(i=0;i<n;i++)printf("%d\n",*(a+i));
	free(a);
	return 0;
}