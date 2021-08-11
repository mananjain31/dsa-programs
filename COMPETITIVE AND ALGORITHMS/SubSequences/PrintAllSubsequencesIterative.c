#include<stdio.h>
#include<math.h>
int main()
{
	int i,j;
	char a[] = "abcde";
	int n = (sizeof(a)/sizeof(a[0]))-1;
	int num = 1;
	num = pow(2, n);
	for(j=1;j<num;j++)
	{
		for(i=0;i<n;i++)
		{
			if(j>>i & 1)
			{
				printf("%c", a[i]);
			}
		}
		printf("\n");
		
	}
	return 0;
}