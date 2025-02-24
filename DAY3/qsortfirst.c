#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr,int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i] <=pivot && i<high)
        {
            i++;
        }

        while(arr[j] >pivot && j>low)
        {
            j--;
        }
        if(i<j){
        swap(&arr[i],&arr[j]);
    }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void qusort(int *arr,int low,int high)
{
    int pos;
    if(low<high)
    {
         pos=partition(arr,low,high);
        qusort(arr,low,pos-1);
        qusort(arr,pos+1,high);
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
qusort(a,0,n-1);
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
	
