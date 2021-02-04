#include<stdio.h>
void show(int x[], int div, int n)
{
	int i;
	int a[10] = {0};
	int y[n];
	for(i = 0; i<n; i++)
		a[(x[i]/div)%10]++;
	
	for(i = 1; i<10; i++)
		a[i]+=a[i-1];

	for(i = 0; i < n; i++)
		y[a[(x[i]/div)%10]-=1] = x[i];

	for(i = 0; i < n; i++)
		x[i] = y[i];
}
void main()
{
	int i;
	int x[] = {82,2,24,45,66,18,75,90};
	show(x,1,8);
	show(x,10,8);
	for(i = 0; i < 8; i++) 
		printf("%d ",x[i]);
}