import java.util.*;
public class iterativeMergeSort
{
	static void merge(int[] x, int lb, int ub)
	{
		// 0 1 2 3 4
		int mid = (lb + ub) / 2;
		int n = ub-lb;
		int y[] = new int[n+1];
		int k = 0;
		int i = lb;
		int j = mid+1;
		while(i <= mid && j <= ub)
		{
			if(x[i]<x[j]) y[k++] = x[i++];
			else y[k++] = x[j++];
		}
		while(i<=mid) y[k++] = x[i++];
		while(j<=ub) y[k++] = x[j++];
		for(k=0;k<=n;k++)x[lb+k] = y[k];
	}
	static void mergeSort(int[] x, int lb, int ub)
	{
		int mid = 0;
		Stack<Integer> s1 = new Stack<>();
		Stack<Integer> s2 = new Stack<>();
		Stack<Integer> ss1 = new Stack<>();
		Stack<Integer> ss2 = new Stack<>();
		s1.push(lb);
		s2.push(ub);
		while(!s1.isEmpty())
		{
			lb = s1.pop();
			ub = s2.pop();
			ss1.push(lb);
			ss2.push(ub);
			mid = (ub+lb)/2;
			//0 1 2 3 4 
			if(lb < mid)
			{
				s1.push(lb);
				s2.push(mid);
			}
			if(mid+1 < ub)
			{
				s1.push(mid+1);		
				s2.push(ub);		
			}
		}
		System.out.println("merging");
		while(!ss1.isEmpty())
		{
			lb = ss1.pop();
			ub = ss2.pop();
			merge(x, lb, ub);
		}
	}
	public static void main(String[] args) 
	{
		int x[] = {990,89,11,100,-1, 90, 1920, -12, 0, 0, 21, -12, 0};
		mergeSort(x, 0, x.length-1);
		for(int i: x)System.out.print(i + " ");
	}
 }
