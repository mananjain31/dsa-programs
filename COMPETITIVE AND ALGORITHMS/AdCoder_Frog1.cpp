#include <bits/stdc++.h>
using namespace std ;
#define ll long long int
ll n;
ll solve (ll *a, ll *dp, ll i)
{
  if (i >= n) return LLONG_MAX;
  if (dp[i] != -1) return dp[i];
  ll left = abs (a[i] - a[i + 1]) + solve (a, dp, i + 1);
  ll right = LLONG_MAX;
  if (i + 2 < n)
    right = abs (a[i] - a[i + 2]) + solve (a, dp, i + 2);
  return dp[i] = min (left, right);
}
int main ()
{
  ios_base::sync_with_stdio(false) ;
  cin.tie(0) ;
  cout.tie(0) ;
  cin >> n;
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