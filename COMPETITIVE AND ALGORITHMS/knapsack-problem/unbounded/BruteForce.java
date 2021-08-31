class BruteForce
{
	static int recur(int cap, int[] v, int[] w, int curr, int max)
	{
		if(cap < 0) return max;
		if(curr > max) max = curr;
		for(int i=0;i<v.length;i++)
		{
			if(cap >= w[i])
			{
				int x = recur(cap-w[i], v, w, curr+v[i], max);
				max = max > x ? max : x;
			}
		}
		return max;
	}
	static int getKnapSackFillValue(int cap, int[] v, int[] w)
	{
		return recur(cap, v, w, 0, 0);
	}
	public static void main(String[] args) {
		int capacity = 8;
		int v[] = {10, 40, 50, 70};
       	int w[]  = {1, 3, 4, 5} ;
		System.out.println(getKnapSackFillValue(capacity, v, w));
	}
}