#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

int partition(int *arr,int p,int r)
{
	int x=arr[r];
	int i=p-1;
	int j,temp;
	for(j=p;j<r;j++)
	{
		if(arr[j]<=x)
		{
			i=i+1;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	return i+1;
}

void quicksort(int *arr,int p,int r)
{
	if(p<r)
	{
		int q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}
int main()
{
clock_t start,end;
int i,n;
printf("\n Enter the no of terms");
scanf("%d",&n);
int* a=(int*)malloc(n*sizeof(int)); 
printf("\n enter the elemensts");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
start=clock();
quicksort(a,0,n-1);
end=clock();
double total_t=((double)(end-start))/CLOCKS_PER_SEC;
printf("updated array:");
for(i=0;i<n;i++)
{
	printf("%5d",a[i]);
}
printf("\n time:%f seconds",total_t);
return 0;
}
