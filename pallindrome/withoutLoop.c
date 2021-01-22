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

/*
let no n -> 1234
show(1234, 0)
{
 s = 0*10 + 1234%10 = 4
 return show(123, 4)
 {
   s = 4*10 + 123%10 = 43
   return show (12, 43)
   {
	s = 43*10 + 12%10 = 432
	return show(1, 432)
    {
	 s = 432*10 + 1%10 = 4321
	 return show(0, 4321)
	 {
	   if(n==0) return 4321
	 }
	}
   }
 } 
}

*/


