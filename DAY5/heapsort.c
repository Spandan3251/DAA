#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void maxheapify(int *arr,int n,int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest=i,temp;
	if(l<n && arr[l]>arr[i])
	{
		largest=l;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
	
		maxheapify(arr,n,largest);
	}
}
	
	
void buildmaxheapify(int *arr,int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	{
		maxheapify(arr,n,i);
	}
}

void heapsort(int *arr,int n)
{
buildmaxheapify(arr,n);
int i,temp;
for(i=n-1;i>0;i--)
{
	temp=arr[0];
	arr[0]=arr[i];
	arr[i]=temp;
	n=n-1;
	maxheapify(arr,n,0);
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
heapsort(a,n);
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
