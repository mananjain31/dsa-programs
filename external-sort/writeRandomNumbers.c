#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int rno;
int oneMB = 1024*1024/sizeof(rno);
FILE *file;
file = fopen("data.d", "wb");
srand(time(0));
for(int i=1; i<=oneMB*5; i++)
{
rno = rand();
fwrite(&rno, sizeof(rno), 1, file);
}
printf("Succesfully written random numbers in the file");
return 0;
}