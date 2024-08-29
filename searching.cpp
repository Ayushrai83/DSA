#include<stdio.h>

int linearSearch(int arr[], int size, int element ){
	for(int i = 0 ; i < size ; i++ ){
		if(arr[i]==element){
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[], int size, int element ){
	int low , mid , high;
	low = 0;
	high = size-1;
	while(low<=high){
		mid = (low + high)/2;
		if (arr[mid] == element){
			return mid;
		}
		if (arr[mid] < element){
			low = mid + 1 ;
		}
		else{
			high = mid - 1 ;
		}
	}
	return -1;
}

int main(){
	// Linear search
	int arr[] = {2,3,34,432,42,454,657,7,667};
	int size = sizeof(arr)/sizeof(int);
	int element;
	printf("Enter the element u want to search : \n");
	scanf("%d",&element);
	int searchIndex = linearSearch(arr , size , element);
	printf("The element %d was found to be on index %d " , element ,searchIndex);

    // Binary search
    int arr2[] = {1,3,4,5,7,9,12,23,34,56};
    int size2 = sizeof(arr2)/sizeof(int);
    int element2;
	printf("Enter the element u want to search : \n");
	scanf("%d",&element2);
	int searchIndex2 = binarySearch(arr2 , size2 , element2);
	printf("The element %d was found to be on index %d " , element2 ,searchIndex2);
	return 0;
}