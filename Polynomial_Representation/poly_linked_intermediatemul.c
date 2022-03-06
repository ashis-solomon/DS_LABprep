#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int coeff;
	int exp;
	struct node* link;
}polynode;

polynode* head1 = NULL;
polynode* head2 = NULL;
polynode* head3 = NULL;
polynode* head4 = NULL;

polynode* inputPoly(polynode* head,int size){
	int exp,coeff;
	polynode* ptr;
	printf("Enter the Coefficients and Exponents in Decreasing Order :\n ");
	printf("For Example 2x^3 + 5x^2 + 1 => 2 3 5 2 1 0\n\n");
	for(int i=0;i<size;i++){
		scanf("%d %d",&coeff,&exp);
		polynode* node = (polynode*)malloc(sizeof(polynode));
		node->coeff = coeff;
		node->exp = exp;
		node->link = NULL;
		if(head==NULL)
			head = node;
		else
			ptr->link = node;
		ptr = node;
	}
	return head;
}

void display(polynode* head){
	polynode* temp = head;
	if(temp==NULL){
		printf("Empty Polynomial!!!\n");
		return;
		}
	while(temp!=NULL){
		if(temp->link==NULL){printf("%dx^%d",temp->coeff,temp->exp);break;}
		printf("%dx^%d  +  ",temp->coeff,temp->exp);
		temp = temp->link;
	}
}

polynode* create(int coeff,int exp){
	polynode* node = (polynode*)malloc(sizeof(polynode));
	node->coeff = coeff;
	node->exp = exp;
	node->link = NULL;
	return node;
}

polynode* addPoly(polynode* head1,polynode* head2,polynode* head3){
	polynode* ptr;
	while(head1!=NULL && head2!=NULL){
		if(head1->exp > head2->exp){	
			polynode* node = create(head1->coeff,head1->exp);	
			if(head3==NULL)
				head3 = node;
			else
				ptr->link = node;
			ptr = node; 
			head1 = head1->link;	
		}
		else if(head1->exp < head2->exp){		
			polynode* node = create(head2->coeff,head2->exp);	
			if(head3==NULL)
				head3 = node;
			else
				ptr->link = node;
			ptr = node; 
			head2 = head2->link;	
		}
		else if(head1->exp == head2->exp){		
			polynode* node = create(head1->coeff + head2->coeff,head2->exp);
			if(head3==NULL)
				head3 = node;
			else
				ptr->link = node;
			ptr = node; 	
			head1 = head1->link;
			head2 = head2->link;
		}
	}
	if(head1!=NULL){
		while(head1!=NULL){
			polynode* node = create(head1->coeff,head1->exp);
			if(head3==NULL)
				head3 = node;
			else
				ptr->link = node;
			ptr = node;
			head1 = head1->link;
		}
	}
	if(head2!=NULL){
		while(head2!=NULL){
			polynode* node = create(head2->coeff,head2->exp);
			if(head3==NULL)
				head3 = node;
			else
				ptr->link = node;
			ptr = node;
			head2 = head2->link;
		}
	}
	return head3;
}

polynode* mulPoly(polynode* head1,polynode* head2,polynode* head4){
	int coeff,exp;
	for(int i=head1;i!=NULL;i=i->link){
		for(int j=head2;j!=NULL;j=j->link){
			coeff = head1->coeff * head2->coeff;
			exp = head1->exp + head2->exp;
			polynode* node = create(coeff,exp);
		}
	}
}

void main(){
	int size;
	printf("INPUT POLYNOMIAL 1\n\n");
	repeat:
	printf("Enter the number of terms : ");
	scanf("%d",&size);
	if(size<1){
		printf("Invalid Size !!\n");
		goto repeat;
	}
	head1 = inputPoly(head1,size);
	printf("INPUT POLYNOMIAL 2\n\n");
	label:
	printf("Enter the number of terms : ");
	scanf("%d",&size);
	if(size<1){
		printf("Invalid Size !!\n");
		goto label;
	}
	head2 = inputPoly(head2,size);
	printf("\n\n");
	printf("POLYNOMIAL 1 : \n");
	display(head1);
	printf("\n\nPOLYNOMIAL 2 : \n");
	display(head2);
	printf("\n\nSUM OF POLYNOMIALS 1 AND 2 : \n\n");
	head3 = addPoly(head1,head2,head3);
	display(head3);
	printf("\n\nPRODUCT OF POLYNOMIALS 1 AND 2 : \n\n");
	head4 = mulPoly(head1,head2,head4);
	display(head4);
}
