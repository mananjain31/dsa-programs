#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int allNeg(int a[], int n)
    {
        int max = a[0];
        int i=0;
        for(i=0; i<n; i++)
        {
            if(a[i]>0) return i;
            else max = std::max(max, a[i]);
        }
        return max;
    }
    int maxSubarraySum(int arr[], int n){
        int i = allNeg(arr, n);
        if(i < 0) return i;
        int cs = 0;
        int max = 0;
        for(;i<n;i++)
        {
            cs += arr[i];
            if(cs < 0) cs = 0;
            else max = std::max(max, cs);
        }
        return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends