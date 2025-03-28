#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,j,cyc,rq,q[100],length=0,diff;
	printf("Enter the number of cylinders: ");
	scanf("%d",&cyc);
	printf("Enter the current head: ");
	scanf("%d",&q[0]);
	printf("Enter the number of requests: ");
	scanf("%d",&rq);
	printf("Enter the queue:\n");
	for(i=1;i<=rq;i++)
	{
		scanf("%d",&q[i]);
	}
	printf("The disk movements are:\n");
	for(i=0;i<rq;i++)
	{
		printf("%d ---> %d\n",q[i],q[i+1]);
		diff=abs(q[i]-q[i+1]);
		length=length + diff;
		printf("Movement length is %d\n",diff);
	}
	printf("The total disk movement length is %d",length);
}
