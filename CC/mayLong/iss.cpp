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
void precompute();

const int mod = 1'000'000'007;
const int N = 2e6+1, M = N;

vector<int> g[N];
int a[N];
vector<ll> cmpVal(N, 0), sol(N, 0);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, m;
	cin>>n;
	cout<<sol[(ll)4*n+1]<<endl;
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
	
	precompute();

	int t = 1;
	cin >> t;
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

void precompute(){
	ll i, j;

	generate(cmpVal.begin(), cmpVal.end(), [n=0]()mutable{return n++;});

	for(i=2; i<N; i++)
		if(cmpVal[i]==i){
			cmpVal[i]=i-1;
			for(j=2*i; j<N; j+=i)
				cmpVal[j]=(cmpVal[j]/i)*(i-1);
		}

	for(i=1; i<N; i++){
		sol[i]+=i-1;
		for(j=2*i; j<N; j+=i)
			sol[j]+=i*((1+cmpVal[j/i])/2);
	}
}