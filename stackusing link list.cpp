#include<stdio.h>
#include<cstdlib>

struct node {
	int data;
	struct node *next;
};

void linkListTraversal(struct node *ptr){
	if(ptr != NULL){
		printf("Element :%d\n" , ptr->data);
		ptr = ptr->next;
	}
}

int isEmpty(struct node *top){
	if (top == NULL){
		return 1;
	}
	return 0;
}

int isFull(struct node *top){
	struct node * p = (struct node *)malloc(sizeof(struct node));
	if(p == NULL){
		return 1;
	}
	return 0;	 
}

struct node * push(struct node *top , int x){
	if (isFull(top)){
		printf("Stack  overflow");
	}else{
		struct node * n = (struct node*)malloc(sizeof(struct node));
		n->data = x;
		n->next = top;
		top = n ;
		return top;
	}
}

int pop(struct node **top){
	if (isEmpty(*top)){
		printf("Stack  underflow");
	}else{
		struct node * n = *top;
		*top = (*top)->next;
		int x = n -> data;
		free(n) ;
		return x;
	}
}

int peek (int pos){
	struct node * ptr;
	for(int i =0 ; (i < pos -1 && ptr != NULL);i++){
		ptr = ptr-> next;
	}
	if(ptr != NULL){
		return ptr->data;
	}else{
		return -1;
	}
}


int main(){
	struct node * top = NULL;
	top = push(top,18);
	top = push(top,9);
	top = push(top,8);
	top = push(top,7);
//	int element = pop(&top);
//	printf("Element pop is %d\n",element);
	linkListTraversal(top);
	printf("Element at position 1 is %d \n",peek(1));
	
	
	return 0;
}