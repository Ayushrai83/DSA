#include<stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
 // O(2n) , SC = O(n)
int missingRepeatingPrblm(int a[]){
	int n = a.size();
	int hash[n+1] = {0};
	for(int i = 0 ; i<n ; i++){
		hash[a[i]]++;
	}
	int repeating = -1 , missing = -1;
	for(int i = 1 ; i <= n ; i++){
		if(hash[i] == 2) repeating = i;
		else if(hash[i] == 0) missing = i;
		
		if (repeating != -1 && , missing != -1){
			break;
		}
	}
	return (repeating ,missing);
}

//optimal solution of above by O(n) and SC = O(1)
int optimal(int a[]){
	long long n = a.size();
	// S - Sn --> X - Y
	// S2 - S2n --> X2 - Y2
	long long Sn = (n * (n+1))/2;
	long long S2n = (n * (n+1) * (2n+1))/6;
	long long S = 0 ; S2 = 0;
	for(int i = 0 ; i < n ; i++){
		S += a[i];
		S2 += a[i] * a[i];
	}  
	long long val1 = S - Sn;
	long long val2 = S2 - S2n;
	val2 = val2 / val1;
	long long x = (val1 + val2)/2;
	long long y = x - val1;
	return (x,y);
} 

//Find kth largest element using priortiy queue
int findkthelement(int num[] , int k){
	priority_queue<int>pq(num.begin(),num.end());
	int ans = 0;
	while(k--){
		ans = pq.top();
		pq.pop();
	}
	return ans;
};
// same as above using min heap
int findkthelement(int nums[] , int k){
	priority_queue<int , vector<int> , greater<int>>pq;
	for(auto x : nums){
		pq.push();
		if(pq.size() > k){
			pq.pop();
		}
	}
	return pq.top();
};

//Product of array except  itself
int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }
        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;

//optimizing above code        
int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
        
//Find if there is a pair with a given sum in the rotated sorted Array
boolean bruteForce(int a[] , int sum ){
	if (a.length == 0){
		return false;
	}
	for(int i = 0 ; i <a.length - 1 ; i++){
		for(int j = i + 1 ; j < a.length ; j++){
			if(a[i]+a[j]==sum){
				return true;
			}
		}
	}
	return false;
}

boolean SortingForSum(int a[] , int sum ){
	if (a.length == 0){
		return false;
	}
	Array.sort(a);
	int start = 0 ;
	int end = a.length - 1;
	while(start<=end){
		int s = arr[start] + arr[end];
		if(s == sum){
			return true;
		}else if(s > sum){
			end--;
		}else{
			start++ ;
		}
	}
	return false;
}

boolean SumpairUsingHashSet(int a[] , int sum){
	if (a.length == 0){
		return false;
	}
	
	Set<Integer> s = new HashSet<>();
	
	for(int i = 0 ; i < a.length - 1 ; i++){
		if(s.contains(sum - arr[i])){
			return true ;
		}
		s.add(arr[i]);
	}
	return false;
}


//Code  for pair sum in rotated  sorted array


// This function returns true if arr[0..n-1]
// has a pair with sum equals to x.
bool pairInSortedRotated(int arr[], int n, int x)
{
	// Find the pivot element
	int i;
	for (i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			break;

	// l is now index of smallest element
	int l = (i + 1) % n;

	// r is now index of largest element
	int r = i;

	// Keep moving either l or r till they meet
	while (l != r) {

		// If we find a pair with sum x,
		// we return true
		if (arr[l] + arr[r] == x)
			return true;

		// If current pair sum is less,
		// move to the higher sum
		if (arr[l] + arr[r] < x)
			l = (l + 1) % n;

		// Move to the lower sum side
		else
			r = (n + r - 1) % n;
	}
	return false;
}

// Driver code
int main()
{
	int arr[] = { 11, 15, 6, 8, 9, 10 };
	int X = 16;
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	if (pairInSortedRotated(arr, N, X))
		cout << "true";
	else
		cout << "false";

	return 0;
}















