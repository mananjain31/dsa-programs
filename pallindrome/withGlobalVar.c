#include<stdio.h>
int r = 2;
void main()
{
	int num=1;
	printf("Enter number to check pallindrome: ");
	scanf("%d", &num);
	// rev(num);
	if(num==r)printf("the number is pallindrome.\n");
	else printf("the number is not pallindrome\n");
}