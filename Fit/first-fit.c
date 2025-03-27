#include<stdio.h>
void main()
{
    int pg[100],disk[100],n,m,i,j,alt[100];
    printf("Enter the number of programes: ");
    scanf("%d",&n);
    printf("Enter the number of disk allotment: ");
    scanf("%d",&m);
    printf("Enter the program sizes:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pg[i]);
    }
    printf("Enter the disk partitions\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&disk[i]);
    }
    
    //first-fit
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {   
            
            if(pg[i]<disk[j] && disk[j]!=-1)
            {
                alt[i]=j;
                disk[j]=-1;
                break;
            }
        }
    }
    printf("The allotments of programs are:\n");
    for(i=0;i<n;i++)
    {
        printf("Program %d ---> disk %d\n",i,alt[i]);
    }
}
