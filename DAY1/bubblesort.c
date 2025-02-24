#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubblesort(int *arr,int n)
{
	int i,j,flag;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
	}
}
int main()
{
	int i,n;
printf("\n how many nos");
scanf("%d",&n);
int* x=(int*)malloc(n*sizeof(int)); 
srand(time(NULL));
for(i=0;i<n;i++)
{
	x[i]=rand()%10000;
}
//printf("\n enter nos");
//for(i=0;i<n;i++)
//{
//scanf("%d",&x[i]);
//}
clock_t start = clock();
bubblesort(x,n);
clock_t end = clock();
double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
for(i=0;i<n;i++)
{
	printf("%5d\n",x[i]);
}
printf("\n the time is:%f", time_taken);
return 0;
}
