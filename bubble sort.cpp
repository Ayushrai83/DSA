#include<stdio.h>

void printArray(int* A , int n){
	for(int i = 0 ; i < n ; i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}

void bubbleSort (int *A, int n){
	int temp = 0;
	for(int i = 0 ; i < n-1 ; i++){   //loop for passes
		//Loop for each passes
		for(int j=0 ; j < n-1-i ; j++){
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
} 

void adaptiveBubbleSort (int *A, int n){
	int temp = 0;
	int isSorted = 0 ;
	for(int i = 0 ; i < n-1 ; i++){   //loop for passes
		printf("Working on pass %d \n" , i+1);
		isSorted = 1;
		//Loop for each passes
		for(int j=0 ; j < n-1-i ; j++){
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				isSorted = 0 ;
			}
		}
		if(isSorted){
			return;
		}
	}
} 
 
int main (){
	int A[] = {12, 45 , 21 , 42 , 13 , 87};
	int n = 6 ;
	printArray (A,n); //Printing array before sorting
	bubbleSort  (A,n);// Function for sorting array
	printArray (A,n);//  Printing array after sorting  
	return 0;
}