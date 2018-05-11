#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
		NEW THIS LAB:
pthread_mutex_t lock;
pthread_mutex_lock(&lock);
pthread_mutex_unlock(&lock);
pthread_mutex_init(&lock,NULL);
pthread_mutex_destroy(&lock);

*/

int n=0;
pthread_mutex_t lock;

void* odd(void* data){
	pthread_mutex_lock(&lock);
	while(n<101){
		if(n%2==0){
			n=n+1;	
			printf("%d ",n);
		}
			pthread_mutex_unlock(&lock);		
	}
}

void* even(void* data){
		pthread_mutex_lock(&lock);
	while(n<101){
		if(n%2==1){
			n=n+1;	
			printf("%d ",n);
		}
					pthread_mutex_unlock(&lock);
	}
}


int main(){
	pthread_t t1;
	pthread_t t2;
	int rv1,rv2;
	rv1=pthread_create(&t1,NULL,odd,NULL);
	rv2=pthread_create(&t2,NULL,even,NULL);
	if(rv1){
		printf("Thread 1 wasn't created.\n Error code:%x",rv1);
		exit(1);
	}
	pthread_join(t1,NULL);
	if(rv2){
		printf("Thread 2 wasn't created.\n Error code:%x",rv2);
		exit(1);
	}
	pthread_join(t2,NULL);
	pthread_exit(NULL);
	return 0;
}


