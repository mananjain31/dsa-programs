#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
void swap(void *i, void *j, int es)
{
	void* block = malloc(es);
	memcpy(block,(const void*)i,es);
	memcpy(i,(const void*)j,es);
	memcpy(j,(const void*)block,es);
	free(block);
}
void quickSort(void *a, int cs, int es, int (*p2f)(void*, void*))
{
	int lb,ub,e,f;
	int top = cs;
	int *slb = (int*)malloc(sizeof(int)*cs);
	int *sub = (int*)malloc(sizeof(int)*cs);
	//push
	top--;
	slb[top] = 0;
	sub[top] = cs-1;
	//
	while(top!=cs)
	{	
		//pop
		e = lb = slb[top];
		f = ub = sub[top];
		top++;
		while(e<f)
		{
			// while(e<=ub && a[e] <= a[lb]) e++;
			while( e<=ub && p2f((a+(es*e)), (a+(es*lb))) <= 0 ) e++;
			// while(a[f] > a[lb]) f--;
			while( p2f((a+(es*f)), (a+(es*lb))) > 0) f--;
			if(e < f) swap(a+es*e, a+es*f, es);
			else swap(a+es*lb,a+es*f, es);
		}
		if(f+1 < ub)
		{
			//push
			top--;
			slb[top] = f+1;
			sub[top] = ub;
		}
		if(f-1 > lb)
		{
			//push
			top--;
			slb[top] = lb;
			sub[top] = f-1;
		}
	}
	free(slb);
	free(sub);
}

///////////////////////////////
struct student
{
	int id;
	char name[20];	
};
int mycomparator(void* i, void* j)
{
	struct student* l = (struct student*)i;
	struct student* r = (struct student*)j;
	
	return strcmp(l->name, r->name); ////////////may cause error
}
int main()
{
	int n;
	struct student *a;
	printf("Enter Requirement : ");
	scanf("%d",&n);
	a = (struct student*)malloc(sizeof(struct student)*n);
	for(int i=0;i<n;i++) 
	{
		printf("Enter id : ");
		scanf("%d", &a[i].id);
		printf("now Enter name : ");
		scanf("%s", a[i].name);
	}
	quickSort(a,n,sizeof(struct student),mycomparator);
	for(int i=0;i<n;i++)	printf("%d %s\n", a[i].id, a[i].name);
	free(a);
	return 0;
}
