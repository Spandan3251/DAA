#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertionsort(int *x,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=x[i];
		j=i-1;
		while(x[j]>=0 && x[j]>temp)
		{
			x[j+1]=x[j];
			j=j-1;
		}
		x[j+1]=temp;
	}
}
int main()
{
int i,n,term=1;
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
FILE *fptr=fopen("insertionupdated.txt","a");
clock_t start = clock();
insertionsort(x,n);
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
