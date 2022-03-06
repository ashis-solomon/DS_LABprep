#include<stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int ele){
	if(top>=MAX_SIZE-1){printf("Overflow!!\n"); return;}
	
	top++;
	stack[top] = ele;
}

int pop(){
	if(top==-1){
		printf("Underflow!!\n"); 
		return -1;
	}
	else{
		top--;
		return stack[top+1];
	}
}

void display(){
	if(top==-1){printf("The Stack is EMPTY!!\n"); return;}
	
	for(int i=top;i>=0;i--){
		printf("%d\t",stack[i]);
	}
	printf("\n^\n");
	printf("|\n");
	printf("TOP\n");
}

void main(){
	int choice,ele;
	printf("****MENU****\n\n");
	printf("1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
	printf("Enter the Menu Choice : ");
	scanf("%d",&choice);
	while(choice!=4){
		switch(choice){
			case 1:	printf("Enter the Element to be Pushed : ");
					scanf("%d",&ele);
					push(ele);
					break;
			case 2: 	ele = pop();
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