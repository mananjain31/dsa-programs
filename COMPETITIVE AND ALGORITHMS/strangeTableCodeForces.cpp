#include <iostream>
#include <bits/stdc++.h>
#define int  unsigned long long 
using namespace std;
 
 
void solve(){
    int n,m,x;
    cin>>n>>m>>x;
    x--;
    int r = x%n;
    int c = x/n;
    int ans = m*r + c+1;
    cout << ans << endl;
}  
main()
{
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++) 
        solve();
    return 0;
}