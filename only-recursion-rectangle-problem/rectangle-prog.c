/*
	print rectange of r*c dimension
	without using loop
	using recursion only
	and recursion of  function : show()
	with 2 parameters is only allowed
*/

#include<stdio.h>
#include<stdbool.h>
void show(int r, int c)
{
	//end point of recusion
	if(r==0 || c==0)return;
	
	
	//initialising static var 
	//when fresh call of this function
	//,i.e., from another function
	static bool externalCall = true;
	static int cols;
	static int rows;
	if(externalCall)
	{
		cols = c; 
		rows = r;
	}
	
	//for horizontal printing
	externalCall = false; 
	printf("* ");
	show(r, c-1);
	
	//returning till the first call of current r
	if(c!=cols)return;
	
	//changing line and calling the func for r-1, 
	// ,i.e., for the next row
	
	printf("\n");
	show(r-1, c);
	
	//external call returning to initial state
	if(r == rows) externalCall = true;
}
void main()
{
	show(8,6);
	printf("\n");
	show(2,3);
}