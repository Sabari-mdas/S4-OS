#include<stdio.h>
void main()
{
	int  i,j,n,m,p[10][10], alloc[10][10],max[10][10],avail[10],need[10][10],count,fl=0;
	printf("Enter the number of processes: ");
	scanf("%d", &m);
	printf("Enter the number of resources: ");
	scanf("%d",&n);
	printf("ALLOCATION\n");
	for(i=0;i<m;i++)
	{
		printf("Processes P%d: ",i);
		for(j=0;j<n;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("MAXIMUM\n");
	for(i=0;i<m;i++)
	{
		printf("Processes P%d: ",i);
		for(j=0;j<n;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter available resource:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&avail[i]);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("Need matrix is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}
	count=0;
	int comp[10]={0,0,0,0,0,0,0,0,0,0};
	while(count != m)
	{
		for(i=0;i<m;i++)
		{	
			if(comp[i]==0)
			{
			fl=0;
			for(j=0;j<n;j++)
			{
				if(need[i][j]<=avail[j])
				{
					fl++;
				}
				else 
				{
					fl=0;
				
				}
			}
			//printf("fl =%d ",fl);
			if(fl==n)
			{
				for(j=0;j<n;j++)
				{
					avail[j]=avail[j]+alloc[i][j];
					
				}
				count++;
				comp[i]=-1;
				
			}
			}
		}
	}
	printf("Total available resource:");
	for(j=0;j<n;j++)
	{
	printf("%d\t",avail[j]);
	}
}
