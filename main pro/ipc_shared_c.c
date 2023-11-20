//ipc_shared_c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
	char buff[100];	
	printf("Enter some data to put into the shared memory\n");
	read(0,buff,100);
	pid_t p = fork();
	
	
	if(p>0){
		int i;
		void *shared_memory;
	
		int shmid;
		shmid = shmget((key_t)2345,1024,0666|IPC_CREAT);
		printf("\n\nKey of shared memory is %d\n", shmid);
	
		shared_memory = shmat(shmid,NULL,0);
		printf("Parent attached at %p\n", shared_memory);
	
		strcpy(shared_memory,buff);
		printf("I wrote %s\n", (char*)shared_memory);
	}
	else{	wait(NULL);
		
		int shmid = shmget((key_t)2345,1024,0666);
		printf("\n\nKey of the shared memory is %d\n", shmid);
		void *shared_memory = shmat(shmid, NULL, 0);
		printf("Child attached at %p\n", shared_memory);
		printf("Data read from parent is : %s\n",(char*)shared_memory);
	}

}
