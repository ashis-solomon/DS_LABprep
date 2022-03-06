#include<stdio.h>

#define MAX_SIZE 100

int cqueue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int ele){
	if(front==(rear+1)%MAX_SIZE){printf("Overflow!!\n"); return;}
	if(front==-1){
		front=(front+1)%MAX_SIZE; rear=(rear+1)%MAX_SIZE;
		cqueue[rear] = ele;
	}
	else if(front>rear){
		front =0; rear =0;
		cqueue[rear] = ele;
	}
	else{
		rear=(rear+1)%MAX_SIZE;
		cqueue[rear] = ele;
	}
}

int dequeue(){
	if(front==-1){
		printf("Underflow!!\n"); 
		return -1;
	}
	else if(front==(rear+1)%MAX_SIZE){
		int ret = cqueue[rear];
		front =-1; rear =-1;
		return ret;
	}
	else{
		int ret = cqueue[front];
		front=(front+1)%MAX_SIZE;
		return ret;
	}
}

void display(){
	if(front==(rear+1)%MAX_SIZE){printf("The Queue is EMPTY!!\n"); return;}
	printf("FRONT->");
	for(int i=front;i!=(rear+1)%MAX_SIZE;i=(i+1)%MAX_SIZE){
		printf("%d\t",cqueue[i]);
	}
	printf("<-REAR\n");
}

void main(){
	int choice,ele;
	printf("****MENU****\n\n");
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n");
	printf("Enter the Menu Choice : ");
	scanf("%d",&choice);
	while(choice!=4){
		switch(choice){
			case 1:	printf("Enter the Element to be Inserted : ");
					scanf("%d",&ele);
					enqueue(ele);
					break;
			case 2: 	ele = dequeue();
					if(ele==-1){break;}
					printf("Dequeued %d !!\n",ele);
					break;
			case 3: 	display();
					break;
			case 4: 	break;
			default : 	printf("Enter a Valid Choice !!\n");
		}	
		printf("Enter the Menu Choice : ");
		scanf("%d",&choice);
	}
}