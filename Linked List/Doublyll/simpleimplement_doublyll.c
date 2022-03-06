#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* prev;
	struct node* next;
}listnode;

listnode* front = NULL;

listnode* create(int ele){
	listnode* node;
	node = (listnode*)malloc(sizeof(listnode));
	node->data = ele;
	node->prev = NULL;
	node->next = NULL;
}

void insert_beg(int ele){
	listnode* node = create(ele);
	if(node==NULL){
		printf("Overflow!!\n");
		return;
	}
	
	if(front == NULL){	
		front = node;
	}	
	else{
		front->prev = node;
		node->next = front;
		front = node;
	}
}

void insert_end(int ele){
	listnode* node = create(ele);
	listnode* temp = front;
	if(node==NULL){printf("Overflow!!\n"); return;}
	if(front==NULL){front = node; return;}
	else{
		while(temp->next!=NULL)
		temp = temp->next;
		temp->next = node;
		node->prev = temp;
	}
}

void display(){
	listnode* temp = front;
	if(front==NULL){printf("The List is EMPTY!!\n"); return;}
	printf("List :\n");
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main(){
	int choice=0,ele;
	printf("****MENU****\n\n");
	printf("1.Insert at Begining\n2.Insert at End\n3.Display\n4.Exit\n\n");
	printf("Enter the Menu choice : ");
	scanf("%d",&choice);
	while(choice!=4){
		switch(choice){
			case 1:	printf("Enter the element to be inserted : ");
					scanf("%d",&ele);
					insert_beg(ele);
					break;
			case 2:	printf("Enter the element to be inserted : ");
					scanf("%d",&ele);
					insert_end(ele);
					break;
			case 3: 	display();
					break;
			case 4: 	break;
			default : 	printf("Enter a Valid Choice !!!\n");
		}
	printf("Enter the Menu choice : ");
	scanf("%d",&choice);
	}
}