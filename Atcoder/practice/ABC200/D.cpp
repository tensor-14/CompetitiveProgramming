#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define PI 3.1415926535897932384626
#define ll long long int
#define endl "\n"

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

ll mpow(ll base, ll exp); 

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, m, cnt=0;
	cin>>n;
	vector<ll> a(n);
	for(auto& x:a)
		cin>>x;

	vector<vector<ll>> bc(200, vector<ll>(0));

	cnt=min(n, 8LL);
	for(i=1; i<(1<<cnt); i++){
		ll sm=0;
		vector<ll> s;
		for(j=0; j<cnt; j++)
			if(i&(1<<j)){
				s.push_back(j+1);
				sm+=a[j];
				sm%=200;
			}

		if(bc[sm].size()){
			cout<<"YES\n";
			
			cout<<bc[sm].size();
			for(auto& x: bc[sm])
				cout<<" "<<x;
			cout<<endl;

			cout<<s.size();
			for(auto& x: s)
				cout<<" "<<x;
			cout<<endl;

			return;
		}
		else
			bc[sm]=s;
	}
	cout<<"NO\n";

}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	/*
	#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif 
	*/

	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}

ll mpow(ll base, ll exp) {
	base %= mod;
	ll result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((ll)result * base) % mod;
		base = ((ll)base * base) % mod;
		exp >>= 1;
	}
	return result;
}

