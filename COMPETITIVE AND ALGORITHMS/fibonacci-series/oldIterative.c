#include<stdio.h>
#include<stdlib.h>
int main(){
	int x,y,z,j,k;
	x = 0;
	y = 1;
	printf("Enter Number : ");
	scanf("%d", &k);
	j = 1;
	while(j<k)
	{
		z = x+y;
		x = y;
		y = z;
		j++;
	}
	printf("%d", y);
	return 0;
}