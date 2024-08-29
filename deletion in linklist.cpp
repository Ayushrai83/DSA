#include<stdio.h>
#include<cstdlib>

struct node {
	int data;
	struct node * next;
};

void linkListTransversal (struct node * ptr){
	while(ptr != NULL){
		printf("Element : %d\n", ptr->data);
		ptr = ptr->next;
	}
}

struct node * deleteFirstElement(struct node * head){
	struct node * ptr = head ;
	head = head -> next;
	free(ptr);
	return head;
}

struct node * deleteAtIndex(struct node * head, int index){
	struct node *p = head;
	struct node *q = head->next;
	int i = 0;
	while(i!=index-1){
		p = p-> next;
		q = q-> next;
		i++ ;
	}
	p->next = q->next;
	free(q);
	return head;
}

struct node * deleteAtLast(struct node * head){
	struct node *p = head;
	struct node *q = head->next;
	while(q->next != NULL){
		p = p-> next;
		q = q-> next;
	}
	p->next = NULL;
	free(q);
	return head;
}

struct node * deleteAtGivenValue(struct node * head, int value){
	struct node *p = head;
	struct node *q = head->next;
	while(q->data != value && q->next != NULL){
		p = p-> next;
		q = q-> next;
	}
	if(q->data == value){
		p->next = q->next;
		free(q);
	}
	return head;
}


int main(){
	struct node * head;
	struct node * second;
	struct node * third;
	struct node * fourth;
	
	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));
	fourth = (struct node *)malloc(sizeof(struct node));
	
	head -> data = 4;
	head -> next = second;
	
	second -> data = 3;
	second -> next = third;
	
	third -> data = 8;
	third -> next = fourth;
	
	fourth -> data = 11;
	fourth -> next = NULL;
	
	printf("Link list before deletion : \n");
	linkListTransversal(head);
	
//	head = deleteFirstElement(head); // for delleteing in first element from the link list
 	head = deleteAtIndex(head,2);  //For deleting an element at any index
// 	head = deleteAtLast(head); //For deleteting last index
//	head = deleteAtGivenValue(head,3); //For deleteing an element by value
	printf("Link list after deletion : \n");
	linkListTransversal(head);
	
	return 0;
}