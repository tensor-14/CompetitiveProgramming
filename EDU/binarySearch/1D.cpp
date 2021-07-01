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
	ll i, j, n, k;
	cin>>n;
	vector<ll> a(n);
	for(auto& x:a)
		cin>>x;
	cin>>k;
	sort(a.begin(), a.end());
	
	for(i=0; i<k; i++){
		ll x, y;
		cin>>x>>y;
		ll l=-1;		// a[l]<x 
		ll r=n;			// a[r]>=x
		while(r>l+1){
			ll m=(l+r)/2;
			if(a[m]<=y)
				l=m;
			else
				r=m;
		}
		/*
		if(r<n && a[r]==x)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		cout<<l+1<<endl;
		*/
		ll temp=r;
		l=-1;
		r=n;
		while(r>l+1){
			ll m=(l+r)/2;
			if(a[m]<x)
				l=m;
			else
				r=m;
		}
//		cout<<l<<" "<<temp<<endl;
		if(a[l]<x || l<0)
			l++;
		if(a[temp]>y || temp>=n)
			temp--;

		cout<<temp-l+1<<endl;
	}
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

	solve();

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
