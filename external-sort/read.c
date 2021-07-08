#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int rno;
int oneMB = 1024*1024/sizeof(rno);
FILE *file;
file = fopen("data2.d", "rb");
while(fread(&rno, sizeof(int), 1, file))
printf("%d ", rno);
fclose(file);
return 0;
}