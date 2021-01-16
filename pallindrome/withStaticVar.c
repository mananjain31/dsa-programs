#include<stdio.h>

int reverse(int n)
{
	static int x = 0;
	if(n == 0)return 0;
	x = x*10 + n%10;
	reverse(n/10);
	return x;
}
void main()
{
	int num;
	printf("Enter number to check pallindrome: ");
	scanf("%d", &num);
	 if(num==reverse(num))printf("the number is pallindrome.\n");
	 else printf("the number is not pallindrome\n");
}