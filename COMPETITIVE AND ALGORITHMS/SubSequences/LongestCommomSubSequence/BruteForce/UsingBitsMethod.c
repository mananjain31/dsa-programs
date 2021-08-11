#include<stdio.h>
#include<math.h>

int main()
{
char a1[] = {'a', 'b', 'c', 'd', 'b', 'c', 'b'};
char a2[] = {'a', 'd', 'c', 'b', 'b', 'c'};

int n1 = sizeof(a1)/sizeof(a1[0]);
int n2 = sizeof(a2)/sizeof(a2[0]);

int m1 = pow(2, n1)-1;
int m2 = pow(2, n2)-1;


int i,j1,j2,maxSS = 0, i1, i2, k1,k2;
char b1[n1];
char b2[n2];
for(j1=1;j1<=m1;j1++)
{
	i1 = 0;
	for(k1=0;k1<n1;k1++)
	{
		if(j1 >> k1 & 1)
		{
			b1[i1] = a1[k1];
			i1++;
		}
		if(i1 > maxSS)
		{
			for(j2=1;j2<=m2;j2++)
			{
				i2 = 0;
				for(k2=0;k2<n2;k2++)
				{
					if(j2 >> k2 & 1)
					{
						b2[i2] = a2[k2];
						i2++;
					}
				}
				if(i1 == i2)
				{
					for(i=0;i<i1;i++) if(b1[i] != b2[i]) break;
					if(i==i1)
					{
						maxSS = i1;
						break;
					}
				}
			}
		}
	}
}
printf("%d", maxSS);


}