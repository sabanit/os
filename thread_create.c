#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <sys/types.h>
//#include <unistd.h>

/* THREAD
	method: pthread_create(&tid,NULL to take default values,function name without (),if some argument to be passed to the function then pass it here);
	it returns 0 if thread is successfully created.
	to exit: pthread_exit(NULL);
	
	Note:	try to keep the data type of function as void* 

*/

void* prime(void* data){
	int n= *(int*)data;
	int flag=0; 
	for(int i=2;i<=n;i++){
		flag=0;
		for(int j=2;j<=i/2;j++){
			if(i%j ==0){
				flag=1;
				//break;
			}
		}
		if(flag==0)
			printf("%d ",i);
	}
	printf("\n");
}


int main(){
	int n;
	printf("Enter n to get primes <= n: ");
	scanf("%d",&n);
	pthread_t tid;
	int rv;
	rv=pthread_create(&tid,NULL,prime,&n);
	if(rv){
		printf("Thread wasn't created.\n Error code:%x",rv);
		exit(1);
	}
	pthread_exit(NULL);
	return 0;
}


