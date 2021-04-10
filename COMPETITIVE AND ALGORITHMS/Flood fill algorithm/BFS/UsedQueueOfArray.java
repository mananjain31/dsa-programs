public class UsedQueueOfArray
{
	public static void showArr(int a[][])
	{
		for(int i[] : a)
		{
			for(int j: i)
				System.out.print(j + " ");
			System.out.println();
		}
		System.out.println();
	}
	public static void main(String[] args) 
	{
		Character[][] a = new Character[11][11];
		for (int i=0; i<a.length; i++)
			for (int j=0; j<a[0].length; j++)
				a[i][j] = ' ';
		FloodFill<Character> f = new FloodFill<Character>();
		f.execute (a, 5, 5, '@');
	}
}
class FloodFill<T>
{
	Object[][] queue; 
	private int qSize;
	private int front=-1, rear=-1;
	private int max = 0;
	private void enque(Object rowO, Object columnO)
	{
		T row = (T)rowO;
		T column = (T)columnO;
		if (front == -1)
			front++;
		rear = (rear+1)%qSize;
		queue[rear][0] = row;
		queue[rear][1] = column;
	}
	private Object[] deque()
	{
		Object[] t = queue[front];
		if ( ((front+1)%qSize) == rear)
		{
			front = -1;
			rear = -1;
		}
		else front = (front+1) % qSize;
		return t;
	}
	private boolean empty()
	{
		if (front == -1) return true;
		return false;
	}
	public void showArr(T a[][])
	{
		for(T[] i : a)
		{
			for(T j: i)
				System.out.print(j + " ");
			System.out.println();
		}
		System.out.println();
	}
	public void execute(T a[][], int row, int column, T newColor)
	{
		int n = a.length;
		int m = a[0].length;
		qSize = (2*(n+m))*2;
		T oldColor = a[row][column];
		if(oldColor == newColor) return;
		queue = new Object[qSize][2];
		enque(row,column);
		while( !empty() )
		{
			T[] node =(T[]) deque();
			int r =(Integer) node[0];
			int c =(Integer) node[1];
			if ( r < 0 || r >= n || c < 0 || c >= m || a[r][c] != oldColor)
				continue;
			a[r][c] = newColor;
			enque(r, c+1);
			enque(r, c-1);
			enque(r+1, c);
			enque(r-1, c);
			showArr(a);
			max = Math.max(max, count());
		}
		// System.out.println(max);			88
		// System.out.println(qSize);		88
		// since both above statements give same output 
		// therefore a better algorithm in terms of space complexity is made
		// here the space complexity is max(n, m) ,i.e, LINEAR SPACE COMPLEXITY
	}
	private int count()
	{
		int ct = 0;
		if (front == -1) return 0;
		for(int i = front ; i != rear; i = (i+1) % qSize)
			ct++;
		return ct+1;
	}
}