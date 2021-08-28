import java.util.*;
class BruteForce
{
	static int _getKnapsackFillValue(int[] v,int[] w,int n,int cap, int i)
	{
		if(i >= n || cap <= 0) return 0;
		int x=0,y=0;
		if(cap>=w[i])
		{
			x = v[i] +  _getKnapsackFillValue(v, w, n, cap - w[i], i+1);
		}
		y = _getKnapsackFillValue(v, w, n, cap, i+1);
		return x > y ? x : y;
	}
	static int getKnapsackFillValue(int[] v,int[] w,int n,int cap)
	{
		return _getKnapsackFillValue(v, w, n, cap, 0);
	}
	public static void main(String[] args) {
	    int v[] = { 5,2,6,4,5,3 };
		int w[] = { 1,5,10,15,20,22 };
		int n = v.length;
	    int capacity = 25;
	    int maxFill = getKnapsackFillValue(v, w, n, capacity);
	    System.out.printf("Maximum value that can be taken away in knapsack with capacity %d is %d\n",capacity, maxFill);
	}
}