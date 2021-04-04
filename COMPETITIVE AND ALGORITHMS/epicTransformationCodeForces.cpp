#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	int max = a[0];
	int c = 0;
	for(int i=0; i<n; i++)
	{
		if(a[i] == max)c++;
		else if(c == 0) max = a[i];
		else c--;
	}
	c=0;
	for(int i=0; i<n; i++)
		if(a[i] == max) c++;
	if(c > n/2)
		cout << c-(n-c) << endl;
	else if(n%2 == 1)
		cout << "1" << endl;
	else
		cout << "0" << endl;

}
main()
{
	int t, n;
	cin >> t;
	int ans[t];
	for(int i=0; i<t; i++)
	{
		solve();
	}
	return 0;
}