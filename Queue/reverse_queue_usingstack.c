#include<stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int stack[MAX_SIZE];
int top = -1;

void push(int ele){
	if(top>=MAX_SIZE-1){printf("Overflow!!\n"); return;}
	
	top++;
	stack[top] = ele;
}

int pop(){
	if(top==-1){
		//printf("Underflow!!\n"); 
		return -1;
	}
	else{
		top--;
		return stack[top+1];
	}
}

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
		//printf("Underflow!!\n"); 
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

void reverse(){
	int t1,t2;
	if(front==-1){
	printf("Queue is Empty!!\n"); return;
	}
	else{
		while(front!=-1){
			t1 = dequeue();
			if(t1==-1){break;}
			push(t1);
		}
		while(top>-1){
			t2 = pop();
			if(t2==-1){break;}
			enqueue(t2);	
		}
		printf("The Reversed Queue :\n");
		display();
	}
}

void main(){
	int choice,ele;
	printf("****MENU****\n\n");
	printf("1.Enqueue\n2.Dequeue\n3.Reverse\n4.Display\n5.Exit\n\n");
	printf("Enter the Menu Choice : ");
	scanf("%d",&choice);
	while(choice!=5){
		switch(choice){
			case 1:	printf("Enter the Element to be Inserted : ");
					scanf("%d",&ele);
					enqueue(ele);
					break;
			case 2: 	ele = dequeue();
					if(ele==-1){break;}
					printf("Popped %d from Queue !!\n",ele);
					break;
			case 3:	reverse();
					break;
			case 4: 	display();
					break;
			case 5: 	break;
			default : 	printf("Enter a Valid Choice !!\n");
		}	
		printf("Enter the Menu Choice : ");
		scanf("%d",&choice);
	}
}