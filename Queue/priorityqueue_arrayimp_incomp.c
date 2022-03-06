// Priorty Queue

#include<stdio.h>

#define MAX_SIZE 100

int pqueue[MAX_SIZE][2];
int front=-1,rear=-1;

void insert(int ele,int pr){
	if(front==0 && rear>=MAX_SIZE-1){
		printf("Overflow !!\n");
	}
	if(front==-1 && rear==-1){
		front=rear=0;
		pqueue[rear][0] = ele;
		pqueue[rear][1] = pr;
	}
	else if(front>0 && rear==MAX_SIZE-1){
		int temp = front;
		for(int i=0;i<(rear-front+1);i++){
			pqueue[i][0] = pqueue[temp][0];
			pqueue[i][1] = pqueue[temp][1];
			temp++;
		}
		rear = rear-front+1;
		front = 0;
		pqueue[rear][0] = ele;
		pqueue[rear][1] = pr;
	}
	else{
		rear++;
		pqueue[rear][0] = ele;
		pqueue[rear][1] = pr;
	}
}

void delete(){
	if(front==-1){printf("PQueue Underflow !!\n"); return ;}
	if(front==rear){
		int ret_ele = pqueue[front][0];
		int ret_pr = pqueue[front][1];
		front=rear=-1;
		printf("Popped %d with priority %d !!\n",ret_ele,ret_pr);
	}
	else{
		int pos=-1;
		for(int i=front;i<=rear;i++){
			if(pqueue[i][1]<pqueue[pos]){
				pos = i;
			}		
		}
		int ret_ele = pqueue[pos][0];
		int ret_pr = pqueue[pos][1];
		printf("Popped %d with priority %d !!\n",ret_ele,ret_pr);
		for(i=pos;i<=rear;i++){
			pqueue[i][0] = pqueue[i+1][0];
			pqueue[i][1] = pqueue[i+1][1];
		}
		rear--;
	}	
}