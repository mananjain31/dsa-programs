#include<stdio.h>
void quick (int a[], int si, int end)
{
	if (si >= end) return;
	int pivot = a[end];
	int p = si;
	for (int i = si; i < end; i++)
	{
		if(a[i] < pivot)
		{
			int t = a[i];
			a[i] = a[p];
			a[p] = t;
			p++;
		}
	}
	int t = a[end];
	a[end] = a[p];
	a[p] = t;

	quick (a, si, p-1);
	quick (a, p+1, end);	
}
int main()
{
	int a[] = {100, 90, 10, 50, 70, 80, 20, 40, 30, 60};
	int n = sizeof (a) / sizeof (a[0]); 
	quick (a, 0, n-1);
	printf ("Sorted Data using QuickSort Algorithm \n");
	for (int i = 0; i < n; i++)
		printf ("%d ", a[i]);
	printf ("\n");
	return 0;
}