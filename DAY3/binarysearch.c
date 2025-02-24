#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int rbinarysearch(int *arr,int low,int high,int b)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==b)
			return mid;
		else if(arr[mid]>b)
			return rbinarysearch(arr,low,mid-1,b);
		else
			return rbinarysearch(arr,mid+1,high,b);
	}
	return -1;
}
int main()
{
clock_t start,end;
int i,n,p,d;
printf("\n Enter the no of terms");
scanf("%d",&n);
int* a=(int*)malloc(n*sizeof(int)); 
printf("\n enter the elemensts");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
start=clock();
printf("find what \n");
scanf("%d",&d);
p=rbinarysearch(a,0,n-1,d);
end=clock();
double total_t=((double)(end-start))/CLOCKS_PER_SEC;
if(p!=-1)
	printf("\n pos:%d",p);
else
	printf("\n not found");
printf("\n time:%f seconds",total_t);
return 0;
}
