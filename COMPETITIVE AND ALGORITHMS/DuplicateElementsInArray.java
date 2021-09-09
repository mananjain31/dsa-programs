import java.util.*;
class DuplicateElementsInArray{
	static <T>boolean checkDuplicateElements(T a[])
	{
		Set<T> set = new HashSet<>();
		for(T x : a) set.add(x);
		return set.size() != a.length;
	}
	public static void main(String[] args) {
		System.out.println(checkDuplicateElements(new Integer[]{1,2,3,4}));
		System.out.println(checkDuplicateElements(new Integer[]{2,2,3,4}));
	}
}