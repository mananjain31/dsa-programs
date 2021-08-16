import java.util.*;
public class Subarray
{
int n,sum,accsum,i,j;
public static void main(String...args)
{
HashMap<Integer, Integer> map = new HashMap<>();
Scanner sc = new Scanner(System.in);
n = sc.nextInt();
sum = sc.nextInt();
int a = new int[n];
for(i=0;i<n;i++) a[i] = sc.nextInt();

accsum = 0;
for(i=0;i<n;i++)
{
accsum += a[i];
if(accsum == sum) 
{
System.out.println("Subarray : " + 0 + " - "+ i);
break;
}
else if(map.contains(accsum - sum))
{
System.out.println("Subarray : " + (map.get(accsum - sum) + 1) + " - "+ i);
break;
}
else
{
map.put(accsum, i);
}
}
}
}