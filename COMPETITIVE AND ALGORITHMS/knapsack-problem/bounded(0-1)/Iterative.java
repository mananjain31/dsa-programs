import java.util.*;
class Iterative
{
	public static void main(String[] args) {
	    int v[] = { 5,2,6,4,5,3 };
		int w[] = { 1,5,10,15,20,22 };
		int n = v.length; 
	    int capacity = 25;
	    List<Node> list = new LinkedList<>();
	    list.add(new Node(0,0));
	    for(int i=0;i<n;i++)
	    {
	    	List<Node> tList = new LinkedList<>();
	    	int currV = v[i];
	    	int currW = w[i];
	    	for(Node node : list)
	    	{
	    		if(currW+node.w > capacity) break;
	    		tList.add(new Node(node.v + currV, node.w + currW));
	    	}
	    	//merging start
	    	List<Node> mergedList = new ArrayList<>(list.size() + tList.size());
	    	System.out.println("              list : "+list);
	    	System.out.println("             tList : "+tList);
	    	while(list.size()!=0 && tList.size()!=0)
	    	{
	    		Node n1 = list.get(0);
	    		Node n2 = tList.get(0);
	    		if( n1.v < n2.v){
	    			mergedList.add(n1);
	    			list.remove(0);
	    		}
	    		else{
	    			mergedList.add(n2);
	    			tList.remove(0);
	    		}
	    	}
	    	while(list.size()!=0)
    		{
    			mergedList.add(list.get(0));
    			list.remove(0);
    		}
	    	while(tList.size()!=0)
	    	{
    			mergedList.add(tList.get(0));
    			tList.remove(0);
	    	}
	    	System.out.println("                ml : "+mergedList);
	    	//merging ends
	    	Node pre = null;
	    	int preIndex = -1;
	    	for(int e = 0; e<mergedList.size()-1;)
	    	{
	    		Node curr = mergedList.get(e);
	    		Node next = mergedList.get(e+1);
	    		int vCurr = curr.v;
	    		int vNext = next.v;
	    		int wCurr = curr.w;
	    		int wNext = next.w;
	    		if(vCurr < wNext && wCurr < wNext)
	    		{
	    			e++;
	    			continue;
	    		}
	    		if(vCurr == vNext)
	    		{
	    			if(wCurr > wNext) mergedList.remove(e);
	    			else mergedList.remove(e+1);
	    			continue;
	    		}
	    		mergedList.remove(e);
	    	}
	    	list = new LinkedList<Node>(mergedList);
	    	System.out.println("list (iteration end):"+list);
	    }
	    Node ans = list.get(list.size()-1);
	    System.out.println("\nMaximum value that can be taken away in knapsack with capacity of "+capacity+
	    	" is : \nvalue :"+ans.v+"\nweight = "+ans.w);
	}
}
class Node implements Comparable<Node>{
	final int v; final int w;
	Node(int v, int w){this.v = v; this.w = w;}
	public int compareTo(Node node){return v - node.v;}
	public String toString(){return "["+v+","+w+"]";}
}