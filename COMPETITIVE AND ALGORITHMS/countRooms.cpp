#include <iostream>
#include <stdbool.h>
using namespace std;
char mat[1001][1001];
int rooms = 0;
int n, m;
bool isvalid(int i, int j)
{
	if(i>n || j>m || i<=0 || j <=0)return false;
	if(mat[i][j]=='#')return false;
	return true;
}
void show(int i, int j)
{
	mat[i][j]='#';
	if(isvalid(i+1,j))
		show(i+1, j);
	if(isvalid(i,j+1))
		show(i, j+1);
	if(isvalid(i-1,j))
		show(i-1, j);
	if(isvalid(i,j-1))
		show(i, j-1);
}
int main ()
{
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mat[i][j];
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mat[i][j] == '.')
			{
				rooms++;
				show(i,j);
			}
		}
	}
	cout << rooms;
}