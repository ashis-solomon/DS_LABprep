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

void delete_pos(int pos){
	listnode* temp = front;	
	listnode* ptr;
	int count=1,ctr=0;
	if(front==NULL){printf("Underflow!!\n"); return;}
	if(pos==1 && front->next==NULL){
		printf("Popped %d !!\n",front->data);
		front = NULL; 
		return;
	}
	while(temp->next!=NULL){count++; temp=temp->next;}
		temp = front;
	if(pos==1){
		ptr = front;
		front = front->next;
		front->prev = NULL;
		printf("Popped %d !!\n",ptr->data);
		free(ptr);
	}	
	else if(pos<=count && pos>1){
		while(temp->next!=NULL && ctr<pos-1){
			temp = temp->next;
			ctr++;
		}
		temp->prev->next = temp->next;
		printf("Popped %d !!\n",temp->data);
		free(temp);
	}
	else if(pos>count){printf("No. of Elements lesser than Position .. Enter Valid Position !!\n");}
}

void delete_min(){
	listnode* temp = front;
	listnode* minptr = front;
	listnode* ptr;
	int min = front->data;
	if(front==NULL){printf("Underflow!!\n"); return;}
	if(front==NULL && front->next==NULL){
		printf("Popped %d !!\n",front->data);
		front = NULL;
	}
	else{
		while(temp!=NULL){
			if(temp->data < min){
				min =  temp->data;
				minptr = temp;
			}
			temp = temp->next;
		}
		
		if(front->data==min && front->next==NULL){
			printf("Popped Minimum Element %d !!\n",min);
			front = NULL;
		}	
		else if(front->data==min && front->next!=NULL){
			ptr = front;
			printf("Popped Minimum Element %d !!\n",min);
			front = front->next;
			free(ptr);
		}
		else{
			printf("Popped Minimum Element %d !!\n",min);
			minptr->prev->next = minptr->next;
			//free(minptr);
		}
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
	int choice=0,pos;
	char ele;
	printf("****MENU****\n\n");
	printf("1.Insert at Begining\n2.Insert at End\n3.Delete at Position [1,2...]\n");
	printf("4.Delete Minimum Element\n5.Display\n6.Exit\n\n");
	printf("\nEnter the Menu choice : ");
	scanf("%d",&choice);
	while(choice!=6){
		switch(choice){
			case 1:	printf("Enter the element to be inserted : ");
					scanf("%d",&ele);
					insert_beg(ele);
					break;
			case 2:	printf("Enter the element to be inserted : ");
					scanf("%d",&ele);
					insert_end(ele);
					break;
			case 3: 	printf("Enter the Postition at which Element is to be Deleted : ");
					scanf("%d",&pos);
					delete_pos(pos);
					break;
			case 4: 	delete_min();
					display();
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