#include <stdio.h>
#include<string.h>

typedef struct process{
	int pid;
	char pname[100];
	int at;
	int bt;
	int ct;
	int tt;
	int wt;
	}fcfs;
	
void getprocess(fcfs p[100],int n){
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the PID: ");
		scanf("%d",&p[i].pid);
		printf("Enter the process name: ");
		scanf("%s",p[i].pname);
		printf("Enter the Arrival time: ");
		scanf("%d",&p[i].at);
		printf("Enter the Burst time: ");
		scanf("%d",&p[i].bt);
		p[i].ct=0;
	}}

void sort(fcfs p[100],int n){
	int i,j;
	fcfs key;
	for(i=0;i<n;i++)
	{
		key=p[i];
		j=i-1;
		while(j>=0 && p[j].at>key.at)
		{
			p[i+1]=p[i];
			j--;
		}
			p[j+1]=key;
	}}
	
void ct(fcfs p[100],int n)
{
	int i,t=0;
	for(i=0;i<n;i++)
	{
	if(t<p[i].at)
	{
		t=p[i].at;
	}
	t+=p[i].bt;
	p[i].ct=t;
	}
}

void tt(fcfs p[100],int n){
	int i;
	for(i=0;i<n;i++)
	{
		p[i].tt=p[i].ct-p[i].at;
	}}
	
void wt(fcfs p[100],int n){
	int i;
	for(i=0;i<n;i++)
	{
		p[i].wt=p[i].tt-p[i].bt;
	}}
	
void main(){
	int n,i;
	fcfs p[100];
	printf("Enter the number of processes");
	scanf("%d",&n);
	getprocess(p,n);
	sort(p,n);
	ct(p,n);
	tt(p,n);
	wt(p,n);
	float avgwt=0, avgtt=0;
	printf("PID\tAT\tBT\tCT\tTT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
	}
	for(i=0;i<n;i++)
	{
		avgtt=avgtt+p[i].tt;
		avgwt=avgwt+p[i].wt;
	}
	printf("Average Turn around = %f\n",avgtt/n);
	printf("Average Waiting time= %f\n",avgwt/n);
	printf("Gantt chart\n");
	printf("-------------------------------\n");
	for(i=0;i<n;i++)
	{
	printf("| %d |", p[i].pid);
	}
	printf("\n");
	printf("-------------------------------");
	}
	
