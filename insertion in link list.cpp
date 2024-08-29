#include<stdio.h>
#include<cstdlib>

struct node{
	int data;
	struct node * next;
};

void linkListtransversal (struct node * ptr){
	while(ptr != NULL){
		printf("Element : %d\n", ptr->data);
		ptr = ptr->next;
	}
}

struct node * insertAtFirst(struct node * head , int data){
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->next = head;
	ptr->data = data;
	return ptr;
}

struct node * insertAtIndex(struct node * head , int data, int index){
	struct node * ptr =(struct node *)malloc(sizeof(struct node));
	struct node * p = head;
	int i = 0 ;
	while(i!=index-1){
		p = p -> next;
		i++;
	}
	ptr -> data = data;
	ptr -> next = p -> next;
	p -> next = ptr;	
	return head;	
}

struct node * insertAtEnd(struct node * head , int data){
	struct node * ptr =(struct node *)malloc(sizeof(struct node));
	struct node * p = head;
	ptr ->data = data;
	while(p->next!=NULL){
		p = p -> next;
	}
	ptr -> next = NULL;	
	p -> next = ptr;
	return head;	
}

struct node * insertAfterNode(struct node * head,struct node *  prevNode , int data){
	struct node * ptr =(struct node *)malloc(sizeof(struct node));
	ptr -> data = data;
	
	ptr -> next = prevNode -> next;
	prevNode -> next = ptr ; 
	
	return head;
		
}

int main (){
	struct node * head;
	struct node * second;
	struct node * third;
	
	head = (struct node * )malloc(sizeof(struct node));
	second = (struct node * )malloc(sizeof(struct node));
	third = (struct node * )malloc(sizeof(struct node));
	
	head -> data = 7;
	head -> next = second;
	
	second -> data = 11;
	second -> next = third;
	
	third -> data = 34;
	third -> next = NULL;
	
	head = insertAtFirst(head,2);
//  head = insertAtIndex(head,23,1);
//	head = insertAtEnd(head,23);
//	head = insertAfterNode(head,second,45);
	linkListtransversal(head);
	
	return 0;
}