/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class A 
{
	int r1, c1;
	int board[][] = new int[9][9];
	int min;
	int calRow(char ch)
	{
		return ((int)ch - 96);
	}
	boolean isvalid(int i, int j)
	{
		if (i >= 9 || j >= 9 || i <= 0 || j <= 0) return false;
		if (board[i][j] == 1) return false; 
		return true;
	}
	void recur(int r, int c, int moves)
	{
		board[r][c] = 1;
		
		if(r == r1 && c == c1)
		{
			min = min < moves ? min : moves; 
			return;
		}	
		if(moves < min)
		{
			if(isvalid(r+2, c+1))
			{
				recur(r+2, c+1, moves+1);
				board[r+2][c+1] = 0;
			}
			if(isvalid(r+2, c-1))
			{
				recur(r+2, c-1, moves+1);
				board[r+2][c-1] = 0;
			}
			if(isvalid(r-2, c+1))
			{
				recur(r-2, c+1, moves+1);
				board[r-2][c+1] = 0;
			}
			if(isvalid(r-2, c-1))
			{
				recur(r-2, c-1, moves+1);
				board[r-2][c-1] = 0;
			}
			if(isvalid(r+1, c+2))
			{
				recur(r+1, c+2, moves+1);
				board[r+1][c+2] = 0;
			}
			if(isvalid(r-1, c+2))
			{
				recur(r-1, c+2, moves+1);
				board[r-1][c+2] = 0;
			}
			if(isvalid(r+1, c-2))
			{
				recur(r+1, c-2, moves+1);
				board[r+1][c-2] = 0;
			}
			if(isvalid(r-1, c-2))
			{
				recur(r-1, c-2, moves+1);
				board[r-1][c-2] = 0;
			}	
		}	
	}
	int show(int r, int c, int r1, int c1)
	{
		this.r1 = r1;
		this.c1 = c1;
		this.min = 2147483647;
		recur(r,c, 0);
		return min;
	}
}

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc  = new Scanner(System.in);
		int t = sc.nextInt();
		int t2 = 0;
		String s, s1;
		StringTokenizer st;
		int r, c, r1, c1;
		s = sc.nextLine();
		A a = new A();
		while(t != 0)
		{
			s = sc.nextLine();
			st = new StringTokenizer(s);
			
			s1 = st.nextToken();
			r = a.calRow(s1.charAt(0));
			c = Integer.parseInt(""+s1.charAt(1));

			s1 = st.nextToken();
			r1 = a.calRow(s1.charAt(0));
			c1 = Integer.parseInt(""+s1.charAt(1));
			
			System.out.println(a.show(r, c, r1, c1));

			t--;
		}
	}
}
