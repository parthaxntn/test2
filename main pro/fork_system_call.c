//fork_system_call

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t x;
    x=fork();

    if(x<0){
        printf("Process Creation unsuccessful");
        return 1;
    }
    else if(x==0){
        printf("Child Process");
        printf("Pid of child %d\n",getpid());
        printf("x=%d",x);
        printf("pid of parent %d\n",getpid());
    }
    else{
        printf("Parent Process");
        printf("Pid of parent %d\n",getpid());
        printf("x=%d",x);
        printf("pid of shell %d\n",getpid());
    }
    return 0;
}
