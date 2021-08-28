class Dp
{
	public static void main(String[] args) {
	    int v[] = { 5,2,6,4,5,3 };
		int w[] = { 1,5,10,15,20,22 };
		int size = v.length; 
	    int capacity = 25;

		int i,j,num1,num2;
		int dp[][] = new int[size+1][capacity+1];
		for(i=0;i<=size;i++)dp[i][0] = 0;
		for(i=0;i<=capacity;i++)dp[0][i] = 0;

		
		for(i=1;i<=size;i++)
		{
			for(j=1;j<=capacity;j++)
			{
				num2 = 0;
				num1 = dp[i-1][j];
				if(j >= w[i-1])
				{
					num2 = dp[i-1][ j-w[i-1] ] + v[i-1];
				}
				dp[i][j] = num1 > num2 ? num1 : num2;
				System.out.printf("%4d", dp[i][j]);
			}
			System.out.println();
		}

	    System.out.printf("Maximum value that can be taken away in knapsack with capacity %d is %d\n",capacity, dp[size][capacity]);
	}
}