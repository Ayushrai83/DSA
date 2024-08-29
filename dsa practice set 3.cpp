// kth smallest element in a array
#include <stdio.h>
//Method 1
int kthelement(int a[] , int k , int n){
	sort(a.begin(),a.end());
	return(n-k);
}

//Method 2 max heap
int kthElementUsingPq(int a[] , int k){
	priority_queue<int>pq(a.begin(),a.end());
	int ans = 0;
	while(k--){
		ans = pq.top();
		pq.pop()
	}
	return ans;
}

//Method 3 min heap
int minheap(int a[] , int k ){
	priority_queue<int , vector<int> , greater<int>>pq;
	for(auto x : a){
		pq.push(x);
		if(pq.size() > k){
			pq.pop();
		}
	}
	return pq.top();
}
int main(){
	
}