#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubbleSort(void* coll, int n, int es, int (*ptf)(void*, void*))
{
int i, j;
void *a, *b, *t;
t = malloc(es);
n--;
while(n>0)
{
i = 0; 
j = 1;
while(i<=n)
{
a = coll+(i*es);
b = coll+(j*es);
if(ptf(a, b) > 0)
{
memcpy(t,a,es);
memcpy(a,b,es);
memcpy(b,t,es);
}
i++;
j++;
}
n--;
}
free(t);
}
///////////

struct Student
{
int rno;
char name[20];
};


///////////////////////////////////////////////

int myComparator(void* l, void* r)
{
struct Student *a = (struct Student*)l;
struct Student *b = (struct Student*)r;
return strcmp(a->name, b->name);
}


///////////
int main()
{
int n, i;
struct Student *s;
printf("Enter n : ");
scanf("%d",  &n);
s = (struct Student*)malloc(sizeof(struct Student) * n);
if(s == NULL) 
{
	printf("memory not allocated\n");
	return 0;
}
for(i=0; i<n; i++) 
{
printf("enter %d numbered student roll No : ", i+1);
scanf("%d", &s[i].rno);
printf("enter %d numbered student name : ", i+1);
scanf("%s", s[i].name);
}
bubbleSort(s, n, sizeof(struct Student), myComparator);
for(i=0; i<n; i++) printf("rno : %d, name : %s\n", s[i].rno, s[i].name);
free(s);
}