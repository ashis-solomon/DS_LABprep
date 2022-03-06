#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node* prev;
	struct node* next;
}listnode;

listnode* front = NULL;

listnode* create(char ele){
	listnode* node;
	node = (listnode*)malloc(sizeof(listnode));
	node->data = ele;
	node->prev = NULL;
	node->next = NULL;
}

void insert_beg(char ele){
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

void insert_end(char ele){
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

void delete_pos(int pos){
	listnode* temp = front;	
	listnode* ptr;
	int count=1,ctr=0;
	if(front==NULL){printf("Underflow!!\n"); return;}
	if(pos==1 && front->next==NULL){
		printf("Popped %c !!\n",front->data);
		front = NULL; 
		return;
	}
	while(temp->next!=NULL){count++; temp=temp->next;}
		temp = front;
	if(pos==1){
		ptr = front;
		front = front->next;
		front->prev = NULL;
		printf("Popped %c !!\n",ptr->data);
		free(ptr);
	}	
	else if(pos<=count && pos>1){
		while(temp->next!=NULL && ctr<pos-1){
			temp = temp->next;
			ctr++;
		}
		temp->prev->next = temp->next;
		printf("Popped %c !!\n",temp->data);
		free(temp);
	}
	else if(pos>count){printf("No. of Elements lesser than Position .. Enter Valid Position !!\n");}
}

void palindrome_check(){
	listnode* left = front;
	listnode* right = front;
	int count = 1,ctr = 0,flag = 0;
	while(right->next!=NULL){
		count++;
		right = right->next;
	}
	while(ctr<count/2 && flag==0){
		if(left->data != right->data)
			flag = 1;
		left = left->next;
		right = right->prev;
		ctr++;
	}
	if(flag==0){
		printf("It is a PALINDROME !!\n");
	}
	else{
		printf("It is NOT a PALINDROME !!\n");
	}
		
}

void display(){
	listnode* temp = front;
	if(front==NULL){printf("The List is EMPTY!!\n"); return;}
	printf("List :\n");
	while(temp!=NULL){
		printf("%c\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main(){
	int choice=0,pos;
	char ele;
	printf("****MENU****\n\n");
	printf("1.Insert at Begining\n2.Insert at End\n3.Delete at Position [1,2...]\n");
	printf("4.Palindrome Check\n5.Display\n6.Exit\n\n");
	printf("\nEnter the Menu choice : ");
	scanf("%d",&choice);
	while(choice!=6){
		switch(choice){
			case 1:	printf("Enter the element to be inserted : ");
					fflush(stdin);
					ele = getchar();
					insert_beg(ele);
					break;
			case 2:	printf("Enter the element to be inserted : ");
					fflush(stdin);
					scanf("%c",&ele);
					insert_end(ele);
					break;
			case 3: 	printf("Enter the Postition at which Element is to be Deleted : ");
					scanf("%d",&pos);
					delete_pos(pos);
					break;
			case 4: 	palindrome_check();
					break;
			case 5: 	display();
					break;
			case 6: 	break;
			default : 	printf("Enter a Valid Choice !!!\n");
		}
	printf("Enter the Menu choice : ");
	scanf("%d",&choice);
	}
}