//wait_system_call

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t x;
    x = fork();
    
    
    if (x < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (x == 0) {
        printf("child starts\n");
        for(int i=1;i<10;i+=2){
        printf("child:%d\n",i);
        }
        printf("child ends\n");
        
    } else {
        wait(NULL);
        printf("Parent starts\n");
        for(int i=0;i<=10;i+=2){
        printf("parent:%d\n",i);
        }
        printf("Parent ends");
    }

    return 0;
}

//write a program to load and executable program of a child process using exec or execl system call.
//write a program to display s  system call
