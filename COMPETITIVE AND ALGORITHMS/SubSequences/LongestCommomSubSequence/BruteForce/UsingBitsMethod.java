
class UsingBitsMethod
{
	public static void main(String[] args) 
	{
		char a1[] = {'a', 'b', 'c', 'd', 'b', 'c', 'b'};
		char a2[] = {'a', 'd', 'c', 'b', 'b', 'c'};

		int n1 = a1.length;
		int n2 = a2.length;
		int m1 = (int)Math.pow(2, n1);
		int m2 = (int)Math.pow(2, n2);
		char b1[] = new char[n1];
		char b2[] = new char[n2];
		int i1,i2,j1,j2,k1,k2,i,maxSS;
		i1 = i2 = i = j1 = j2 = k1 = k2 = maxSS = 0;


		for(j1=1;j1<=m1;j1++)
		{
			i1 = 0;
			for(k1=0;k1<n1;k1++)
			{
				if( ((j1 >> k1) & 1) == 1)
				{
					b1[i1] = a1[k1];
					i1++;
				}
				if(i1 > maxSS)
				{
					//start searching for this subsequence in a2
					for(j2=1;j2<=m2;j2++)
					{
						i2 = 0;
						for(k2=0;k2<n2;k2++)
						{
							if( ((j2 >> k2) & 1) == 1 )
							{
								b2[i2] = a2[k2];
								i2++;
							}
						}
						if(i2 == i1)
						{
							for(i=0;i<i1;i++) if(b1[i] != b2[i]) break;
							if(i == i1)
							{
								maxSS = i1;
								break;
							}	
						}
					}
				}
			}
		}


		System.out.println(maxSS);
	}
}