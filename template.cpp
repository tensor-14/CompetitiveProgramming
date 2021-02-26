#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

long long int mpow(int base, int exp); 

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];

void solve(){
	int i, j, n, m;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	#ifndef ONLINE_JUDGE 
    	freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif 

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}

long long int mpow(long long base, long long exp) {
	base %= mod;
	long long int result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((long long)result * base) % mod;
		base = ((long long)base * base) % mod;
		exp >>= 1;
	}
	return result;
}