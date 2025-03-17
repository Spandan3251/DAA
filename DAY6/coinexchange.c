#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct currency
	{
		int val;
		int index;
		int noofunits;
	}Currency;
	
void sort(Currency *arr,int n)
{
	int i,j;
	Currency temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j].val<arr[j+1].val)
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int coinchange(Currency *arr,int n,int target)
{
	sort(arr,n);
	int i;
	for(i=0;i<n;i++)
	{
		arr[i].noofunits=target/arr[i].val;
		target=target%arr[i].val;
	}
	
	if(target==0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int main()
{
	clock_t start,end;
    int n, i, target;
    printf("Enter no of denomination : ");
    scanf("%d", &n);

    Currency *denominations = (Currency *)malloc(n * sizeof(Currency));

    printf("Enter the Denominations : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &denominations[i].val);
        denominations[i].index = i;
        denominations[i].noofunits = 0;
    }

    printf("Enter target : ");
    scanf("%d", &target);

	start=clock();
    int result = coinchange(denominations, n, target);
    end=clock();
	double total_t=((double)(end-start))/CLOCKS_PER_SEC;

    if (result == -1)
    {
        printf("Not possible to reach target value\n");
    }
    else
    {
        int *ans = (int *)calloc(n, sizeof(int));
        for (i = 0; i < n; i++)
        {
            ans[denominations[i].index] = denominations[i].noofunits;
        }
        printf("Ans vector : ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", ans[i]);
        }
    }
    printf("\n time:%f seconds",total_t);
    return 0;
}
	
