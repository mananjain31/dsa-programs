#include<stdio.h>
#include<stdlib.h>
int _gcd(int s, int b){
	if(b%s) return _gcd(b%s,s);
	return s;
}
int gcd(int s, int b){
	if(s>b) return _gcd(b,s);
	return _gcd(s,b);
}
int main()
{
	int n,i,lcm;
	int *a;
	printf("Enter size of array : ");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++){
		printf("Enter a number : ");
		scanf("%d", &a[i]);
 	}
	lcm = a[0];
	for(i=1;i<n;i++)
	{
		lcm = (lcm * a[i]) / gcd(lcm,a[i]);
	}

	printf("Gcd : %d", lcm);
	return 0;
}