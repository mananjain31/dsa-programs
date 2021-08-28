#include<stdio.h>

int _getKnapsackFillValue(int* v,int*  w,int n,int cap,int i)
{
	if(i == n || cap<=0 ) return 0;
	int x,y;
	x = 0;
	if(cap >= w[i])
	{
		x = v[i] +  _getKnapsackFillValue(v, w, n, cap-w[i], i+1);
	}
	y = _getKnapsackFillValue(v, w, n, cap, i+1);
	return x > y ? x : y;
}

int getKnapsackFillValue(int* v,int*  w,int n,int cap)
{
	return _getKnapsackFillValue(v, w, n, cap, 0);
}
int main()
{
	int v[] = { 5,2,6,4,5,3 };
    int w[] = { 1,5,10,15,20,22 };
    int cap = 25;
    int n = sizeof(v) / sizeof(v[0]);
    printf("%d\n",getKnapsackFillValue(v, w, n, cap));
}