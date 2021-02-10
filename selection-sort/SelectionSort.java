import java.util.Scanner;
class SelectionSort
{
	void display(int x[])
	{
		for(int i:x) System.out.print(i+" ");
	}
	void swap(int x[], int i, int j)
	{
		x[i] = x[i]+x[j];
		x[j] = x[i]-x[j];
		x[i] = x[i]-x[j];
	}
	void sort(int x[])
	{
		int i,j,min;
		int n=x.length;
		for(i=0;i<n-1;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
				if(x[min]>x[j]) min = j;
			if(min != i)
			{
				swap(x,i,min);
			}				
		}
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
		
		SelectionSort m =new SelectionSort();
		m.sort(x);
		System.out.println("Sorted using Selection Sort : ");
		m.display(x);
	}
}