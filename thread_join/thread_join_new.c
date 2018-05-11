#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
    int i;
    int n;
    int max;
    int min;
    int* AVG;
    int* MAXI;
    int* MINI;
    int average_int ;
    int maximum_int ;
    int minimum_int ;
    int input_numbers[5];
void*  average();
void* minimum();
void* maximum();

void main(){

    pthread_t average_id;
    pthread_t maximum_id;
    pthread_t minimum_id;

    printf("Enter number of elements:\n");
        scanf("%d",&n);

    for(i = 0 ; i< n; i++){
    scanf("%d",&input_numbers[i]);
    }

    average_int = pthread_create(&average_id,NULL,average,NULL);
    maximum_int = pthread_create(&maximum_id,NULL,maximum,NULL);
    minimum_int = pthread_create(&minimum_id,NULL,minimum,NULL);
    if(average_int != 0 || maximum_int != 0 || minimum_int != 0 ){
        printf("Error occured while creating threads.\n");
        exit(-1);
        
    }
    pthread_join(average_id,&AVG);
    pthread_join(maximum_id,&MINI);
    pthread_join(minimum_id,&MAXI);

    printf("Average of entered values is: %d\n", AVG);
    printf("Maximum of entered values is: %d\n", MINI);
    printf("Minimum of entered values is: %d\n", MAXI);
    pthread_exit(NULL);
}

void* average(){
    int sum =0;
    float p;
    for(i = 0 ; i< n; i++){
        sum += input_numbers[i];
    }
       p = (float)sum/n;
    //printf("%f\n",(float)p);
   return &p;

}

void* minimum(){
    // Assume first element as minimum.
    int min = input_numbers[0];
        float q;
    for(i=0; i<n; i++){
        /* If current element is smaller than min */
        if(input_numbers[i] < min)
        {
            min = input_numbers[i];
        }
}
      q = (float)min;
    //printf("%f\n",(float)p);
       return &q;

}

void* maximum(){
    // Assume first element as maximum.
    int max = input_numbers[0];
    float r;

    for(i=0; i<n; i++)
    {
        /* If current element is greater than max */
        if(input_numbers[i] > max)
        {
            max = input_numbers[i];
        }

        
    }
    r = (float)max;
    //printf("%f\n",(float)p);
    return &r;

}