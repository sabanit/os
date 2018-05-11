#include <stdio.h>
#include <time.h>
#include <pthread.h>

pthread_t t_id[5];

void* mock_process(){
    printf("process created \n");
    pthread_exit(0);
}


void* rr(){
    printf("rrobin process \n");
    int count,j,time,remain,flag=0;     
    int wait_time=0,turnaround_time=0,at[5],bt[5],rt[5]; 
    int n=5; 
    int time_quantum=2;
      remain=n; 
      for(count=0;count<n;count++) 
      { 
        at[count]=0; 
        bt[count]=rand()%10; 
        rt[count]=bt[count]; 
      } 
      time=0;
      count=0;
    while(remain!=0) 
    { 
        if(rt[count]<=time_quantum && rt[count]>0) 
        { 
            time+=rt[count]; 
            rt[count]=0; 
            flag=1; 
        } 
        else if(rt[count]>0) 
        { 
            rt[count]-=time_quantum; 
            time+=time_quantum; 
        } 
        
        if(rt[count]==0 && flag==1) 
        { 
            remain--; 
            printf("process: P[%d] \n %d \n %d\n",count+1,time,time-at[count]-bt[count]); 
            wait_time+=time-at[count]-bt[count]; 
            turnaround_time+=time-at[count]; 
            flag=0; 
        } 
        if(count==n-1) 
            count=0; 
        else if(at[count+1]<=time) 
            count++; 
        else 
            count=0; 
    } 
    
    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
    
    pthread_exit(0);
}

int main(){
    int i;
    srand(time(0));
    for(i=0;i<5;i++)
    {
        pthread_create(&t_id[i],NULL,mock_process,NULL);
    }
    pthread_t ttwo;
    pthread_create(&ttwo,NULL,rr,NULL);
    
    return 0; 
    
}
