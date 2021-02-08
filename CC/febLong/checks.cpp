#include<bits/stdc++.h> 
using namespace std; 

int xorSum(int arr[], int n){ 
	int bits = 0; 

	for (int i=0; i < n; ++i) 
		bits |= arr[i]; 

	int ans = bits * pow(2, n-1); 

	return ans; 
} 

int main(){ 
	int arr[] = {1, 5, 6}; 
	int size = sizeof(arr) / sizeof(arr[0]); 
	cout << xorSum(arr, size); 
} 