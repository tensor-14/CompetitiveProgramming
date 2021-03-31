
	#pragma GCC optimize("Ofast")
	#pragma GCC optimize("unroll-loops")
	#include<bits/stdc++.h>
	using namespace std;
	#define ll long long int
	#define endl "\n"

	ll gcd(ll, ll);
	ll timeTaken(ll, ll);

	ll a, b, k, dp[16];

	void solve(){
		ll i, j;
		cin>>a>>b>>k;
		ll lcm = 1;
		for(i = 2; i <= k; i ++)
			lcm = lcm * i / gcd(lcm, i);
		
		ll sol = 0,A = a / lcm, B = b / lcm;
		sol = (A == B) ? timeTaken(a,b) : timeTaken(a % lcm,0) + (A-B-1) * (timeTaken(lcm-1,0) + 1) + timeTaken(lcm-1,b % lcm) + 1;

		cout << sol << endl;
	}

	int main(){
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		srand(chrono::high_resolution_clock::now().time_since_epoch().count());

		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}

		return 0;
	}

	ll gcd(ll a,ll b){
		return (b == 0)? a : gcd(b, (a % b));
	}

	ll timeTaken(ll x, ll b){
		ll res = 0;

		while (x != b){
			ll i, nx = x-1,t; 
			for(i = 3; i <= k ; i ++)
				if ((t = x / i * i)>= b && t < nx)
					nx = t;
			x = nx;  res ++;
		}

		return res;
	}
