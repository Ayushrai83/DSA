#include<stdio.h>
#include<cstdlib>

struct queue{
	int size;
	int f;
	int r;
	int *arr;
};

int isFull(struct queue *q){
	if(q->r == q->size-1){
		return 1;
	}
	return 0;
}

int isEmpty(struct queue *q){
	if(q->r == q->f){
		return 1;
	}
	return 0;
}


void enqueue(struct queue *p , int val){
	if(isFull(p)){
		printf("Queue is full\n");
	}else{
		p->r++ ;
		p->arr[p->r]=val ;
		printf("Enqueue element %d",val);
	}
}

int dequeue(struct queue *p){
	int a = -1;
	if(isEmpty(p)){
		printf("Queue is empty\n");
	}else{
		p->f++ ;
		a = p->arr[p->f];	
	}
	return a;
}

int main(){
	struct queue p;
	p.size = 100;
	p.f = p.r = 0;
	p.arr = (int *)malloc(p.size*sizeof(int));
	
	// Enqueue few elements
    enqueue(&p, 12);
    enqueue(&p, 15);
    enqueue(&p, 1); 
    printf("Dequeuing element %d\n", dequeue(&p));
    printf("Dequeuing element %d\n", dequeue(&p));
    printf("Dequeuing element %d\n", dequeue(&p)); 
    enqueue(&p, 45);
    enqueue(&p, 45);
    enqueue(&p, 45);
 
    if(isEmpty(&p)){
        printf("Queue is empty\n");
    }
    if(isFull(&p)){
        printf("Queue is full\n");
    }
 
    return 0;
}