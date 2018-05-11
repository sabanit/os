#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <sys/types.h>
//#include <unistd.h>

/* THREAD
	pthread_join: used for synchronising threads
	pthread_join(thread id for which to wait, argument for which it is waiting)

*/

int a[]={1,2,3,4,5};

void* minimum(void* data){
	int* a= (int*)data;
	int n = sizeof(a)/sizeof(a[0]);
	int min=a[0];
	for(int i=0;i<n;i++)
		if(a[i]<min)
			min=a[i];
	return min;	
		pthread_exit(NULL);	
}

void* maximum(void* data){
	int* a= (int*)data;
	int n = sizeof(a)/sizeof(a[0]);
	int max=a[0];
	for(int i=0;i<n;i++)
		if(a[i]>max)
			max=a[i];
	return max;	
		pthread_exit(NULL);	
}

void* average(void* data){
	int* a= (int*)data;
	int n = sizeof(a)/sizeof(a[0]);
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	return (sum/n);	
		pthread_exit(NULL);	
}


int main(){
	int *min, *max, *avg;
	int n;
	printf("Enter no. of entries you want to enter ");
	//scanf("%d",&n);
	/*int *a;
	a=(int*)malloc(n*sizeof(int));
	printf("enter the numbers");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}*/
	//int a[]={1,2,3,4,5};	
	printf("check 1");	
	pthread_t tid1, tid2, tid3;
	printf("check 2");	
	int rv1, rv2, rv3;
	rv1=pthread_create(&tid1,NULL,minimum,NULL);
	rv2=pthread_create(&tid2,NULL,maximum,NULL);	
	rv3=pthread_create(&tid3,NULL,average,NULL);
		
	if(rv1!=0|| rv2!=0 || rv3!=0){
		printf("Thread wasn't created.\n");
		exit(1);
	}
	printf("check 4");
	
	pthread_join(tid1,&min);
	pthread_join(tid2,&max);	
	pthread_join(tid3,&avg);
	
	printf("Min:%d \n Max:%d \n Avg:%d", *min, *max, *avg);
		
	pthread_exit(NULL);
	return 0;
}




