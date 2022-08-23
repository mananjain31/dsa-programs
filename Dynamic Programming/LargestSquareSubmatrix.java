/*

Largest Square Submatrix of all 1's | Dynamic Programming
Problem : https://www.youtube.com/watch?v=UagRoA3C5VQ&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=1
DP Level 2 - Lec1

Example Input
5 6
0 1 0 1 0 1
1 0 1 0 1 0
0 1 1 1 1 0
0 0 1 1 1 0
1 1 1 1 1 1

*/

import java.util.*;

public class LargestSquareSubmatrix {
    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number of Rows and Columns : (Example 3 4) ");
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        System.out.println("Enter Matrix data (0 or 1) space and line separated :");
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = sc.nextInt();
        System.out.println(solve(matrix, rows, cols));
    }

    static int solve(int[][] matrix, int rows, int cols) {
        int ans = 0;
        int[][] dp = new int[rows][cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j];
                else
                    ans = Math.max(
                            ans,
                            dp[i][j] = Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1])) + 1);

        return ans;
    }
}