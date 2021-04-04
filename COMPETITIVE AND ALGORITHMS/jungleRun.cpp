#include <iostream>
#include <stdbool.h>
using namespace std;
char mat[31][31];
int c = 0;
int n, x1, y1;
bool isVAlid(int i, int j)
{
	if (i >= n || j >= n || i < 0 || j < 0) return false;
	if (mat[i][j] == 'T' || mat[i][j] == 'V' ) return false; 
	return true;
}
void show (int x, int y, int c1)
{
	if(x == x1 && y == y1)
	{
		if(c == 0) c = c1;
		else c = c < c1 ? c : c1;
	}
	if (isVAlid(x+1, y))
	{
		char temp;
		temp = mat[x+1][y];
		mat[x+1][y] = 'V';
		show(x+1, y, c1+1);
		mat[x+1][y] = temp;
	}
	if (isVAlid(x, y+1))
	{
		char temp;
		temp = mat[x][y+1];
		mat[x][y+1] = 'V';
		show(x, y+1, c1+1);
		mat[x][y+1] = temp;
	}
	if (isVAlid(x-1, y))
	{
		char temp;
		temp = mat[x-1][y];
		mat[x-1][y] = 'V';
		show(x-1, y, c1+1);
		mat[x-1][y] = temp;
	}
	if (isVAlid(x, y-1))
	{
		char temp;
		temp = mat[x][y-1];
		mat[x][y-1] = 'V';
		show(x, y-1, c1+1);
		mat[x][y-1] = temp;
	}
}
int main ()
{
	int x, y;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
			if(mat[i][j]=='S')
			{
				x=i;
				y=j;
			}
			if(mat[i][j]=='E')
			{
				x1=i;
				y1=j;
			}
		}
	}
	show (x, y, 0);
	cout << c;
}