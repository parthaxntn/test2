//iseek.cpp


#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
int n,f;
char buff[15];
f=open("seeking",O_RDWR);
//read(f,buff,10);
//write(1,buff,10);
lseek(f,5,SEEK_CUR);//skips 5 characters from the current position
read(f,buff,15);
write(0,buff,15);
}
