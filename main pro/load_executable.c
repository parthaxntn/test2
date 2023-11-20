//load_executable

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
	pid_t var = fork();
	if(var==0){
		printf("\nI am the child\n");
		//char *args[] = {"./1",NULL};
		//execvp(args[0],args);
		
		char* binaryPath = "./1";
		char *arg1 = "-lh";
		char *arg2 = "/home";
		execl(binaryPath, binaryPath, arg1, arg2, NULL);
		printf("\nENDING....\n");
		
		
	}
	else if (var>0){
		printf("\nParent will wait for child to end");
		wait(NULL);
		printf("\nI am the parent\n");
		exit(1);
	}
	else{
		printf("\nProcess creation unsuccessful\n");
		exit(1);
	}
	return 0;
}
