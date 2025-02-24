#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int nCr(int n,int r)
{
	if(r==0 || r==n)
		return 1;
	if(r>n)
		return 0;
		
	if(r<n)
		return (nCr(n-1,r-1)+nCr(n-1,r));
}
int main()
{
int n,r,s;
srand(time(NULL));
printf("\n enter n and r:");
scanf("%d %d",&n,&r);
clock_t start=clock();
s=nCr(n,r);
clock_t end=clock();
printf("\n %d C %d is :%d",n,r,s);
double t=((double)(end-start))/CLOCKS_PER_SEC;
printf("\n time taken %lf\n",t);
return 0;

}
