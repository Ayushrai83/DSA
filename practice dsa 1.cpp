#include<stdio.h>
#include<map>
#include<unordered_map>
#include <utility>
/* 
Printing max and min from an array
struct pair {
	int min ;
	int max ;
};

struct pair getminMax(int arr[] , int n){
	struct pair minmax;
	if(n==1){
		minmax.min = arr[0];
		minmax.max = arr[0];
		return minmax;
	}
	if(arr[0]>arr[1]){
		minmax.min = arr[1];
		minmax.max = arr[0];
	}else{
		minmax.min = arr[0];
		minmax.max = arr[1];
	}
	for(int i = 2 ; i<n ; i++){
		if(arr[i]>minmax.max){
			minmax.max = arr[i];
		}else if(arr[i]<minmax.min) {
			minmax.min = arr[i];
		}
	}
	return minmax;
}*/

//void reverseArray (int a[] , int n){
//	int mid = n/2 ;
//	int temp = 0 ;
//	for(int i=0 ; i < mid ; i++){
//		temp = a[i];
//		a[i] = a[n-1-i];
//		a[n-1-i] = temp;
//	}
//}

//int max(int a,int b){
//	if(a>b){
//		return a;
//	}
//	return b;
//}

//int subArray(int arr[] , int n ){
//	int sum = 0 ;
//	int maxi = arr[0];
//	for(int i = 0 ; i < n ; i++){
//		sum+=arr[i];
//		maxi = max(maxi , sum);
//		if(sum < 0 ){
//			sum = 0;
//		}
//	}
//	return maxi ;
//}

//bool containsDuplicate(vector<int>& nums) {
//        unordered_map<int, int> seen;
//        for (int num : nums) {
//            if (seen[num] >= 1)
//                return true;
//            seen[num]++;
//        }
//        return false;
//    }
/*
int searchInRotatedSortedArray(int a[] , int n , int target){
	int low = 0;
	int high = n - 1;
	int mid;
	while(low<=high){
		mid = (low + high)/2;
		if(a[mid]==target){
			return mid;
		}
		if(a[low]<=target){
			if(a[low]<=target  && target <= a[mid]){
				high = mid - 1;
			}else{
				low = mid + 1;
			}
		}else{
			if(a[mid] <= target && target <= a[high]){
				high = mid - 1;
			}else{
				low = mid + 1;
			}
		}
	}
	return -1;
}

// Finding minimum value in rotated sorted array
int minSearchInRortatedSortedArray(int a[] , int n , int ans){
	int low = 0 ; 
	int high - n -1 ;
	while(low<=high){
		mid = (low + high)/2;
		if(a[low] <= a[mid]){
			ans = min(ans,a[low]);
			low = mid + 1;
		}else{
			high = mid - 1;
			ans = min(ans,ans[mid]);
		}
	}
	return mid;
}

int nextPermutation(int A[] , int n){
	int ind = -1 ;
	for(int  i = n-2 ; i>=0 ; i--){
		if(A[i] < A[i+1]){
			ind = i;
			break;
		}
	}
	
	if(ind == -1){
		reverse(A.begin() , A.end());
		return A ;
	}
	
	for(int i = n-1 ; i > ind ;i-- ){
		if(A[i] > A[ind]){
			swap(A[i],A[ind]);
			break;
		}
	}
	reverse(A.begin() + ind + 1 , A.end());
	return A;
}
*/
int buySellStock(int A[] , int n){
	int mini = A[0];
	int profit = 0;
	for(int i = 1 ; i < n ; i++){
		int diff = A[i] - mini;
		profit = max(profit,diff);
		mini = min(mini,A[i]);
	}
	return profit;
}

int main(){
	int a[] = {4,5,6,7,0,1,2};
	int n = 7 ;
 	int searchIndex = searchInRotatedSortedArray(a,n,0);
 	printf("The given element was for to be on %d index",searchIndex);
	
//	printf("Reversing...\n");
//	for(int i = 0; i < n ; i++){
//		printf("%d ",a[i]);
//	}
	
//	printf("Maximum subarray is %d", subArray(a,n));

	
}