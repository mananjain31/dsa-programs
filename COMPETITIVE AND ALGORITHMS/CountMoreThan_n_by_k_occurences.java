//https://practice.geeksforgeeks.org/problems/count-element-occurences/1#
/*package whatever //do not write package name here */
import java.io.*;
import java.util.*;

class Driverclass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            int k = sc.nextInt();

            System.out.println(new Solution().countOccurence(arr, n, k));
        }
    }
}
// } Driver Code Ends



class tower
{
    int data;
    int count;
    tower(int a, int b){
        this.data = a; 
        this.count = b;
        
    }
}

class Solution 
{
    //Function to find all elements in array that appear more than n/k times.
    public int countOccurence(int[] arr, int n, int k) 
    {
        tower t[] = new tower[k-1];
        for(int x = 0; x < k-1; x++) t[x] = new tower(0,0);
        for(int data : arr)
        {
            int i = 0;
            for(; i<k-1; i++)
            {
                if(t[i].data == data)
                {
                    t[i].count++;
                    break;
                }
            }
            if(i == k-1)
            {
                i = 0;
                for(; i < k-1; i++)
                {
                    if(t[i].count == 0)
                    {
                        t[i].data = data;
                        t[i].count++;
                        break;
                    }
                }
            }
            if(i == k-1)
            {
                i = 0;
                for(; i < k-1; i++) t[i].count--;
            }
        }
        int ans = 0;
        for(tower i : t)
        {
            int count = 0;
            for(int a : arr) if(a == i.data) count++;
            if(count > n/k) ans++;
        }
        return ans;
    }
}