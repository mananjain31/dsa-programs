//Knuth–Morris–Pratt (KMP) Pattern Matching Substring Search - First Occurrence Of Substring
#include <bits/stdc++.h>
// #define int long long
using namespace std;
int kmp()
{
	string s, t;

	cin >> s >> t;

	int n = s.length();
	int m = t.length();
	int table[m];
	table[0]=0;
	int i=0;
	int j=1;
	while(j!=m)
	{
		if(t[i] == t[j])
		{
			table[j] = i+1;
			i++;
			j++;
		}
		else if(i==0)
		{
			table[j] = 0;
			j++;
		}
		else
		{
			i = table[i-1];
		}
	}
	// for(i=0; i<m; i++)
	// 	cout << t[i] << " ";
	// cout << endl;
	// for(i=0; i<m; i++)
	// 	cout << table[i] << " ";
	// cout << endl;

	//KMP table completed
	j=i=0;
	while(i<n)
	{
		if(s[i] == t[j])
		{
			if(j == m-1)
			{
				// cout << "found at index : " << i-j << endl;
				return i-j;
			}
			j++;
			i++;
		}
		else if(j == 0)
		{
			i++;
		}
		else
		{
			j=table[j-1];
		}
	}
	return -1;
}
main()
{
	int ans = kmp();
	if (ans == -1)
		cout << "Input String Not Found" << endl;
	else
		cout << "found at index : " << ans << endl;
	return 0;
}

/*
0	1	2	3	4	5	
a	a	a	a	a	b

0	1	2
a	a	b
0	1	0

					
0	1	2	3	4	5	6	7	8	9	10
d	s	d	s	e	d	s	d	s	d	s
0	0	1	2	0	1	2	3	4	3	4

0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 3
d  s  d  s  e  d  s  d  s  d  f  d  s  d  s  d  s  e  d  s  d  s  d  s  s  e  d  s  d  s  d  s
d  s  d  s  e  d  s  d  s  d  s
*/