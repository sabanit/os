#include <stdio.h>
#include <stdlib.h>

typedef struct frames{
	int pg;
	int t; //timestamp
}frames;

int main(void){
	int i,j=0;
	int nframes, nref;
	int time=0;
	int pagefault;
	int fill=-1;//store number of frames in 
	int min;
	int npf=0;//no of page fault
	
	printf("\nEnter number of physical memory frames: ");
	scanf("%d",&nframes);
	printf("\nEnter number of page references: ");
	scanf("%d",&nref);
	printf("\nEnter sequence of page references: ");
	int ref[nref];
	for(i=0;i<nref;i++)
		scanf("%d",&ref[i]);
	
	frames mm[nframes]; 
	//initialise to zero
	for(i=0;i<nframes;i++)
	{
		mm[i].pg=-1;
		mm[i].t=-1;
	}
	
	for(i=0; i<nref;i++){
		time++;
		pagefault=1;
		
		// 1:search in mm
		j=0;
		/*while(mm[j].pg!=-1 || j!=nframes){
			// 1.1: found than t=time
			if(mm[j].pg==i){
				mm[j].t=time;
				pagefault=0;
				break;
			}
			j++;
		}*/
		
		for(j=0;j<nframes;j++){
			if(mm[j].pg==i){
				mm[j].t=time;
				pagefault=0;
				break;
			}
		}
			
			//1.2: not found- pagefault=1
		if(pagefault==1){
			npf++;	
				// 1.2.1: space available in mm- add the page in list
			//for(j=0;j<nframes;j++){
				//if(mm[j].pg!=-1){
			if(fill+1<nframes){	
				fill++;			
				mm[fill].pg=ref[i];
				mm[fill].t=time;

				break;
			}		
				//1.2.2: space not available - find least time and put page there 
			else{
				min=0;
				for(j=0;j<nframes;j++){
					if(mm[j].t<mm[min].t)
						min=j;
				}
				mm[min].pg=ref[i];
				mm[min].t=time;
			}
		}
		//PRINTING
		printf("%d: [",ref[i]);
		for(j=0;j<fill;j++){
			printf(" %d |",mm[j].pg);	
		}	
		printf(" %d ] hello",mm[fill].pg);
		if(pagefault==1)
			printf(" F ");
		printf("\n");	
			
	}
	printf("\n No. of page faults= %d \n Miss rate= %d",npf,(npf*100/nref));
	
	return 0;
}
