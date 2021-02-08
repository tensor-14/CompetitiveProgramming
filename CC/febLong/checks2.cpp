#include <bits/stdc++.h> 
using namespace std; 

const long long int mod = 998244353;

long long int sum_Xor(vector<long long int> arr, long long int n, long long int k){ 

	long long int sumXor = 0; 

	for (long long int i = 0; i < (1 << n); i++) { 
		if (__builtin_popcount(i) == k) { 
			long long int cur_xor = 0; 
			for (long long int j = 0; j < n; j++) {
				if (i & (1 << j)) 
					cur_xor = cur_xor ^ arr[j]; 
			} 

			sumXor = (sumXor + (cur_xor)%mod)%mod; 
		} 
	} 
	return sumXor; 
} 

// Main Function 
int main(){

    long long int i, j, n, m, q, sm=0;
    cin>>n;
    vector<long long int> a(n);
    for(i=0; i<n; i++) 
        cin>>a[i];
    cin>>q;
    while(q--){
        cin>>m;
        sm = (accumulate(a.begin(), a.end(), 0)%mod);
        if(m==1)
            cout<<sm<<'\n';
        else{
            while(m>1){
                sm+=(sum_Xor(a, a.size(), m));
                m--;
            }
            cout<<sm<<"\n";
        }
    }
	return 0; 
} 
