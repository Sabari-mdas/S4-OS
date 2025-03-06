#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int id;
	void *sm;
	char buf[100];
	
	id=shmget((key_t)1222,1024,0666 | IPC_CREAT);
	printf("key of shared memory is %d\n",id);
	sm=shmat(id,NULL,0);
	printf("Process attached at :%p \n",sm);
	printf("Enter the data to be written: \n");
	read(0,buf,100);
	strcpy(sm,buf);
	printf("Data written is : \n%s\n",(char *)sm);
}
