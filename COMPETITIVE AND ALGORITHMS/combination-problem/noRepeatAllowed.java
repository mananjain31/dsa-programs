
class noRepeatAllowed
{
	boolean repeat(String s,int n,int size,String ar[])
	{
		String sp[] = s.split("");
		int i,j;
		int x[]=new int[n];
		for(String t : sp)
		{
			//System.out.print(t);
			for(i=0;i<n;i++)
			{
				if(ar[i].equals(t))
					x[i]++;
				//System.out.print(x[i]);
			}
		}
		for(i=0;i<n;i++)
		{	
			//System.out.print(x[i]);
			if(x[i]>1)return true;
		}
		return false;
	}
	void show(String s,int n,int size,int c,String ar[])
	{
		int i;
		if(c==size)
		{
			if(repeat(s,n,size,ar))return;
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
		noRepeatAllowed c = new noRepeatAllowed();
		c.show("",ar.length,3,0,ar);
	}
}


//output
/*
ab3
abd
a3b
a3d
adb
ad3
ba3
bad
b3a
b3d
bda
bd3
3ab
3ad
3ba
3bd
3da
3db
dab
da3
dba
db3
d3a
d3b
ddd
*/