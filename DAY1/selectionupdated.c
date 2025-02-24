#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int *x,int n)
{
	int m,p,i,j;
for(i=0;i<n-1;i++)
{
m=x[i];
p=i;
for(j=i+1;j<n;j++)
{
	if(x[j]<m)
	{
	m=x[j];
	p=j;
}
}
x[p]=x[i];
x[i]=m;
}

}


nt main()
{
int i,term=1;
for(int j=0;j<=6;j++)
{
term*=10;
int* x=(int*)malloc(term*sizeof(int)); 
srand(time(NULL));
for(i=0;i<term;i++)
{
	x[i]=rand()%10000;
}
//printf("\n enter nos");
//for(i=0;i<n;i++)
//{
//scanf("%d",&x[i]);
//}
FILE *fptr=fopen("selection.txt","a");
clock_t start = clock();
selectionsort(x,n);
clock_t end = clock();
double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
//for(i=0;i<n;i++)
//{
//	printf("%5d",x[i]);
//}
printf("\n the time taken to run the algorithmis%d:%f seconds",term, time_taken);
fprintf(fptr,"%d \t %f\n",term,time_taken);
fclose(fptr);
}
return 0;
}
