/*	given set of intervlas => {start time and end time} of meetings 
*	organized in an office
*	determine minimum numberer of rooms required since some
*	meetings can happen at same time
*/
Code not completed
/*
import java.util.*;

class MinimumRoomsRequired
{
	static int getMinimumRoomsCount(ArrayList<Interval> intervals)
	{
		System.out.println(intervals);
		Collections.sort(intervals);
		System.out.println(intervals);
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		int count = 1;
		for(Interval interval : intervals)
		{
			System.out.println(pq);
			if(pq.isEmpty()){
				pq.add(-interval.end);
			}
			else{
				int end = -pq.peek();
				if(interval.start < end) count++;
				else pq.clear();
				pq.add(-interval.end);
			}
		}
		return count;
	}
	public static void main(String[] args) 
	{
		ArrayList<Interval> intervals = new ArrayList<>();
		intervals.add(new Interval(2,10));
		intervals.add(new Interval(5,15));
		intervals.add(new Interval(6,19));
		intervals.add(new Interval(20,25));
		intervals.add(new Interval(21,40));
		intervals.add(new Interval(23,44));
		System.out.println(getMinimumRoomsCount(intervals));
	}
}
class Interval implements Comparable<Interval>
{
	int start,end;
	Interval(int s, int e){
		start = s; 
		end = e;
	}
	public int compareTo(Interval i)
	{
		return start - i.start; 
	}
	public String toString() { return " {"+this.start +","+ this.end+"} " ;}
}
*/