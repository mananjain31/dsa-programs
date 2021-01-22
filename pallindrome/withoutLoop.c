#include<stdio.h>
int reverse(int n, int s)
{
	if(n == 0)return s;
	s = s*10 + n%10;
	return reverse(n/10, s);
}
void main()
{
	printf("Enter number to check if pallindrome: ");
	int n;
	scanf("%d", &n);
	int rev = reverse(n, 0);
	if(rev == n)printf("\nGiven no. is pallindrome.\n");
	else printf("\nGiven no. is not pallindrome.\n");
}


