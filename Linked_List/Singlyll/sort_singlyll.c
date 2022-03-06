#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}listnode;

listnode* front = NULL;

listnode* create(int ele){
	listnode* node;
	node = (listnode*)malloc(sizeof(listnode));
	node->data = ele;
	node->link = NULL;
	return node;
}

void insert_end(int ele){
	listnode *node = create(ele);
	listnode* temp = front;
	if(node==NULL){
		printf("Underflow!!!\n");
		return;
	}
	if(front == NULL){
		front = node;
	}
	else{
		while(temp->link!=NULL)
			temp = temp->link;
		temp->link = node;
	}
}

void delete_end(){
	listnode* temp = front;
	listnode* ptr;
	if(front==NULL)
		{printf("Underflow!!\n"); return;}
	if(front->link == NULL){
		ptr = front;
		printf("Popped %d !!\n",front->data);
		front = NULL;
		free(ptr);
	}
	else{
		while(temp->link!=NULL){
			ptr = temp;
			temp = temp->link;	
		}
		printf("Popped %d !!\n",temp->data);
		ptr->link = NULL;
		free(temp);
	}
}

void display(){
	listnode* temp = front;
	if(front==NULL){
		printf("The List is EMPTY !!!\n");
	return;	
	}
	printf("List :\n");
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

void reverse_ll(){
	listnode* cur = front;
	listnode* next = NULL;
	listnode* prev = NULL;
	while(cur!=NULL){
		next = cur->link;
		cur->link = prev;
		prev = cur;
		cur = next;
	}
	front = prev;
}

void sort(){
	listnode* temp = front;
	int swapped=0;
	
	do{
		temp = front;
		swapped = 0;
		while(temp->link!=NULL){
			if(temp->data > temp->link->data){
				int t = temp->data;
				temp->data = temp->link->data;
				temp->link->data = t;	
				swapped = 1;
			}
		temp = temp->link;
		}
	}while(swapped == 1);
}

void main(){
	int choice=1,ele;
	printf("****MENU****\n\n");
	printf("1.Insert at End\n2.Delete at End\n3.Display\n");
	printf("4.Reverse the Linked List\n5.Sort\n6.Exit\n\n");
	printf("Enter the Menu Choice : ");
	scanf("%d",&choice);
	while(choice!=6){
		switch(choice){
			case 1:	printf("Enter the element to be Inserted : ");
					scanf("%d",&ele);
					insert_end(ele);
					break;
			case 2: 	delete_end();
					break;
			case 3: 	display();
					break;
			case 4:	reverse_ll();
					break;
			case 5:	printf("Sorted List : \n");
					sort();
					display();
					break;
			case 6: 	break;
			default : printf("Enter a Valid Choice !!!\n");
		}
		printf("Enter the Menu Choice : ");
		scanf("%d",&choice);
	}
}