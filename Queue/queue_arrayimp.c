#include<stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int ele){
	if(rear>=MAX_SIZE-1){printf("Overflow!!\n"); return;}
	if(front==-1){
		front++; rear++;
		queue[rear] = ele;
	}
	else{
		rear++;
		queue[rear] = ele;
	}
}

int dequeue(){
	if(front==-1){
		printf("Underflow!!\n"); 
		return -1;
	}
	else if(front==rear){
		front =-1; rear =-1;
		return queue[0];
	}
	else{
		front++;
		return queue[front-1];
	}
}

void display(){
	if(front==-1){printf("The Queue is EMPTY!!\n"); return;}
	printf("FRONT->");
	for(int i=front;i<=rear;i++){
		printf("%d\t",queue[i]);
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
					printf("Popped %d from Stack !!\n",ele);
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