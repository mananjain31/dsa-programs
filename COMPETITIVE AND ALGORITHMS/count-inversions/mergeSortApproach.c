//Time complexity = O(N^2)
//Space Complexity = O(1)
#include <stdio.h>
#include <stdlib.h>
int invCount;
void merge(int* a, int lb, int mid, int ub){
	int i1 = lb, i2 = mid+1, i3 = 0;
	int* b = (int*)malloc(sizeof(int)*((ub-lb)+1));
	while(i1<=mid && i2<=ub){
		if(a[i1] <= a[i2]){
			b[i3++] = a[i1++];
		}
		else{
			invCount+=(mid-i1)+1;
			b[i3++] = a[i2++];
		}
	}
	while(i1<=mid){
		b[i3++] = a[i1++];
	}
	while(i2<=ub){
		b[i3++] = a[i2++];
	}
	i1 = lb;
	i3 = 0;
	while(i1<=ub){
		a[i1++] = b[i3++];
	}
	free(b);
}
void mergeSort(int* a, int lb, int ub){
	if(lb >= ub) return;
	int mid = (lb+ub)/2;
	mergeSort(a,lb,mid);
	mergeSort(a,mid+1,ub);
	merge(a,lb,mid,ub);
}

int main()
{
	int n,i,j;
	int* a;
	printf("Enter Size of array : ");
	scanf("%d", &n);
	a = (int*) malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		printf("Enter a number : ");
		scanf("%d", a+i);
	}

	////
	invCount = 0;
	mergeSort(a,0,n-1);
	////

	printf("Inversion Count : %d\n", invCount);
	free(a);
	return 0;
}
//6 4 12 3 32 76 54 19 27 62