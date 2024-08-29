#include<stdio.h>
#include<cstdlib>

struct node{
	int data;
	struct node * next;
};

void linkListTransversal(struct node * ptr){
	while (ptr != NULL){
		printf("ELement : %d\n", ptr->data);
		ptr = ptr->next;
	}
}

int main(){
	struct node * head;
	struct node * second;
	struct node * third;
	
	//Allocating memory to the nodes of the linked list from heap
	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));
	
	//Linking first and second node
	head->data = 7;
	head->next = second;
	
	//Linkind second and third node
	second->data = 11;
	second->next = third;
	
	//Termminating the list at third node
	third->data = 13;
	third->next = NULL;
	
	//Calling transversal function of link list
	linkListTransversal(head);
	
	return 0;
}