#include<stdio.h>
#include<stdlib.h>
int lsearch(int  *x,int n,int b)
{
int i;
for( i=0;i<n;i++)
{
if(x[i]==b)
{
return i;
}
}
return -1;
}
int main()
{
int i,n,p,q;
printf("\n how many nos");
scanf("%d",&n);
int* x=(int*)malloc(n*sizeof(int)); 
printf("\n enter nos");
for(i=0;i<n;i++)
{
scanf("%d",&x[i]);
}
printf("\n find what");
scanf("%d",&p);
q=lsearch(x,n,p);
if(q!=-1)
        printf("pos:%d",q);
else
        printf("\n not found");
}

