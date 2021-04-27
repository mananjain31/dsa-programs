#include <bits/stdc++.h>
using namespace std ;
#define ll long long int
ll n, k;
ll solve (ll *a, ll *dp, ll i)
{
  if (i >= n) return LLONG_MAX;
  if (dp[i] != -1) return dp[i];
  
  ll res = LLONG_MAX;
  
  for (int j = i + 1; j < min (n, i + k + 1); j++)
    res = min (res , abs (a[i] - a[j]) + solve (a, dp, j));

  return dp[i] = res;
}
int main ()
{
  ios_base::sync_with_stdio(false) ;
  cin.tie(0) ;
  cout.tie(0) ;
  cin >> n;
  cin >> k;
  ll a[n];
  ll dp[n];
  for (int i=0; i<n; i++)
  {
    cin >> a[i];
    dp[i] = -1;
  }
  dp[n-1] = 0;
  cout << solve(a, dp, 0);
}