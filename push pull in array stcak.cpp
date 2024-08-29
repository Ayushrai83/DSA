#include<stdio.h>
#include<cstdlib>

struct stack {
	int size;
	int top;
	int *arr;
};

int isEmpty (struct stack *ptr){
	if(ptr->top == -1){
		return 1;
	}else{
		return 0;
	}
}

int isFull (struct stack *ptr){
	if(ptr->top == ptr->size - 1){
		return 1;
	}else{
		return 0;
	}
}

void push(struct stack *ptr ,int value){
	if(isFull(ptr)){
		printf("Stack overflow\n , cannot push %d to the stack",value);
	}else{
		ptr->top ++;
		ptr->arr[ptr->top] = value;
	}
}

int pop(struct stack *ptr){
	if(isEmpty(ptr)){
		printf("Stack underflow\n , cannot pop from the stack");
		return -1;
	}else{
		int value = ptr->arr[ptr->top];
		ptr->top --;
		return value;
	}
}

int peek (struct stack *sp , int i){
	int arrInd = sp->top - i + 1;
	if(arrInd < 0){
		printf("Invalid position passed!");
	}else{
		return sp->arr[arrInd];
	}
}

int stackTop(struct stack *sp){
	return sp->arr[sp->top];
}

int stackBottom(struct stack *sp){
	return sp->arr[0];
}


int main(){
	struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
	sp->size = 10;
	sp->top = -1 ;
	sp->arr = (int *)malloc(sp->size * sizeof(int));
	printf("Stack has been created successfully!\n");
	
	printf("Before pushing element : %d\n",isEmpty(sp));
	printf("Before pushing element : %d\n",isFull(sp));
	
	push(sp,56);
	push(sp,66);
	push(sp,76);
	push(sp,86);
	push(sp,96);
	push(sp,106);
	push(sp,116);
	push(sp,126);
	push(sp,136);
	push(sp,146);
	
	printf("After pushing element : %d\n",isEmpty(sp));
	printf("After pushing element : %d\n",isFull(sp));
	
	printf("Popped %d from the stack \n",pop(sp))	;
	
	printf("Top most value of stack is : %d \nBottom most value of stack is : %d\n",stackTop(sp),stackBottom(sp));
	
	//Printing all values of stack
	for(int j = 0; j<= sp->top + 1 ; j++){
		printf("Element at position %d is %d\n",j ,peek(sp,j));
	}
	
	return 0;
}