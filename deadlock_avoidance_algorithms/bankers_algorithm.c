#include <stdio.h>
#include <stdlib.h>

int a, b, c, A, B, C;
int all[5][3];
int max[5][3];


int main(){
	//printf("Enter max availability of 3 resources A, B, C\n");
	//scanf("%d %d %d", &A, &B, &C);
	printf("Enter currently available resources A, B, C\n");
	scanf("%d %d %d", &a, &b, &c);
	
	printf("Enter resource requirement for 5 processes P1, P2, P3, P4, P5\n");
	for(int i=0; i<5;i++){
		printf("Enter resources allocated to P[%d] process A, B, C\n",i);
		scanf("%d %d %d", &all[i][1], &all[i][2], &all[i][3]);
		printf("Enter max requirement by P[%d] process of A, B, C\n",i);
		scanf("%d %d %d", &max[i][1], &max[i][2], &max[i][3]);
	}
	int count=5;
	int flag=0;
	int active[]={1,1,1,1,1};
	int x,y,z;
	
	while(count){
	flag=0;
		for(int i=0; i<5;i++){ 
//printf("hello 1\n");
			if(active[i]==1){
//printf("hello 2\n");	
				x=max[i][1]-all[i][1];
				y=max[i][2]-all[i][2];
				z=max[i][3]-all[i][3];		
				if(x<=a && y<=b && z<=c){
					printf("p[%d] complete \n",i);
					count--;
					active[i]=0;
					a+=all[i][1];
					b+=all[i][2];
					c+=all[i][3];
					flag=1;
					printf("available:%d %d %d\n",a,b,c);
				} 
			}
		}
		if(flag==0){
			printf("unsafe state:- cannot proceed further\n");
			break;
		}	
		if(count==0)
			printf("safe state available\n");
	}
	
	return 0;
}
