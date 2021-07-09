#include<stdio.h>
#include<stdlib.h>
void gnomeSort(int *a, int si, int ei)
{
	int j;
	j = si;
	while(j<=ei)
	{
		if(j != si && a[j]<a[j-1])
		{
			a[j] = a[j] + a[j-1];
			a[j-1] = a[j] - a[j-1];
			a[j] = a[j] - a[j-1];
			j--;
		}
		else j++;
	}
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
	gnomeSort(a,0,n-1);
	for(i=0;i<n;i++)printf("%d\n",*(a+i));
	free(a);
	return 0;
}