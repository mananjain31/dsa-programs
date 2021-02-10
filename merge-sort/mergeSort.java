import java.util.Scanner;
class mergeSort
{
	void display(int x[])
	{
		for(int i:x)
		{
			System.out.print(i+" ");
		}
	}
	void merge(int a[],int b[],int x[])
	{
		int i=0, j=0, k=0;
		int m1=a.length, m2=b.length;
		while(i<m1 && j<m2)
			if(a[i]<b[j]) x[k++]=a[i++];
			else x[k++]=b[j++];
		while(i<m1) x[k++]=a[i++];
		while(j<m2) x[k++]=b[j++];
	}
	void sort(int x[])
	{
		int n=x.length;
		if(n==1)return;
		int m1 = n/2;
		int m2 = n-m1;
		int a[] = new int[m1];
		int b[] = new int[m2];
		for(int i=0;i<m1;i++)a[i]=x[i];
		for(int i=0;i<m2;i++)b[i]=x[i+m1];
		sort(a);
		sort(b);
		merge(a,b,x);
	}
	public static void main(String...args)
	{
		Scanner sc = new Scanner(System.in);
		int n,i;
		System.out.print("Enter No of values to be sorted :");
		n=sc.nextInt();
		int x[] = new int[n];
		for(i=0;i<n;i++)
		{
			System.out.print("Enter "+(i+1)+" numbered value : ");
			x[i]=sc.nextInt();
		}
		
		mergeSort m =new mergeSort();
		m.sort(x);
		System.out.println("Sorted using Merge Sort : ");
		m.display(x);

	}
}