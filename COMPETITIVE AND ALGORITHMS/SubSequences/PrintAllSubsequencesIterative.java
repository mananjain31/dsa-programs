import java.io.*;
import java.util.*;
class PrintAllSubsequencesIterative
{
public static void main(String...args)
{
// abcd
Scanner sc = new Scanner(System.in);
char a [] = sc.nextLine().trim().toCharArray();
int n = a.length;
int num = (int)Math.pow(2, n);

for(int j = 1; j < num; j++)
{
for(int i=0;i<n;i++)
{
if( ((j >> i) & 1) == 1)
{
System.out.print(a[i]);
}
}
System.out.println();
}

}
}
