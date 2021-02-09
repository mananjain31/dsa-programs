
class repeatAllowed
{
	void show(String s,int n,int size,int c,String ar[])
	{
		int i;
		if(c==size)
		{
			System.out.println(s);
			return;
		}
		for(i = 0; i<n; i++)
		{
			show(s+ar[i],n,size,c+1,ar);
		}
	}
	public static void main(String...args)
	{
		String ar[]={"a","b","3","d"};
		repeatAllowed c = new repeatAllowed();
		c.show("",ar.length,3,0,ar);
	}
}


//output
/*
aaa
aab
aa3
aad
aba
abb
ab3
abd
a3a
a3b
a33
a3d
ada
adb
ad3
add
baa
bab
ba3
bad
bba
bbb
bb3
bbd
b3a
b3b
b33
b3d
bda
bdb
bd3
bdd
3aa
3ab
3a3
3ad
3ba
3bb
3b3
3bd
33a
33b
333
33d
3da
3db
3d3
3dd
daa
dab
da3
dad
dba
dbb
db3
dbd
d3a
d3b
d33
d3d
dda
ddb
dd3
ddd
*/