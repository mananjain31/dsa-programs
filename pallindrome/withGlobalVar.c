#include<stdio.h>
int r=0;
void rev(int num)
{
	if(num==0)return;
	r = r*10 + num%10;
	num/=10;
	rev(num);	
}
void main()
{
	int num;
	printf("Enter number to check pallindrome: ");
	scanf("%d", &num);
	rev(num);
	if(num==r)printf("the number is pallindrome.\n");
	else printf("the number is not pallindrome\n");
}