//producer_consumer

#include<stdio.h>
#include<stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10;
int x = 0;

void producer(){
	--mutex;
	++full;
	--empty;
	x++;
	printf("\nProducer produces item %d\n", x);
	++mutex;
}

void consumer(){
	--mutex;
	--full;
	++empty;
	printf("\nConsumer consumes item %d\n", x);
	x--;
	++mutex;
}

int main(){
	int n, i;
	for(int i =1 ;i>0;i++){
		printf("Enter choice:");
		scanf("%d", &n);
		switch(n){
			case 1: 
				if((mutex==1) && (empty!=0)){
					producer();
				}
				else{
					printf("\nBuffer is full\n");
				}
				break;
			case 2:
				if((mutex==1) && (full!=0)){
				consumer();
				}
			else{
			printf("\nBuffer is empty\n");
			}
		}
	}
}
