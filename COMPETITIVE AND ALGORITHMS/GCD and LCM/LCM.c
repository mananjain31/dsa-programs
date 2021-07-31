#include <stdio.h>
int _gcd(int s, int b){
	if(b%s) return _gcd(b%s,s);
	return s;
}
int gcd(int s, int b){
	if(s>b) return _gcd(b,s);
	return _gcd(s,b);
}
int main(){
	int b,s,lcm;
	printf("Enter a number : ");
	scanf("%d", &b);
	printf("Enter a number : ");
	scanf("%d", &s);
	//lcm * gcd = product of numbers
	lcm = (s*b) / gcd(s,b);
	printf("LCM : %d", lcm);
}
	