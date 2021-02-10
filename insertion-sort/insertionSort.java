import java.util.Scanner;
class insertionSort
{
	void display(int x[])
	{
		for(int i:x)
		{
			System.out.print(i+" ");
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
		
		insertionSort m =new insertionSort();
		//m.sort(x);
		//System.out.println("Sorted using Insertion Sort : ");
		m.display(x);

	}
}