#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int rno;
int oneMB = 1024*1024/sizeof(rno);
// int oneMB = 64*3+9;
FILE *file;
file = fopen("data.d", "wb");
srand(time(0));
for(int i=1; i<=oneMB; i++)
{
rno = rand();
fwrite(&rno, sizeof(rno), 1, file);
}
printf("Succesfully written random numbers in the file");
return 0;
}