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
void prime();

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<bool> is_prime(1000001, true);
vector<ll> s;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, m, l, r;
	cin>>n;
	vector<ll> a(n);
	bool flag;
//	cout<<s.size()<<endl;
	for(auto& x: a)
		cin>>x;
	
	for(i=0; i<n; i++){
		flag=false;
		l=0;
		r=s.size();
		while(l<=r && (!flag)){
			m=(l+r)/2;
			if(a[i]==s[m]){
				cout<<"YES\n";
				flag=true;
			}
			else if(a[i]<s[m])
				r=m-1;
			else
				l=m+1;
		}

		if(!flag)
			cout<<"NO\n";
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
	prime();

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

void prime(){
	ll i, j, n=1000000;
	is_prime[0]=is_prime[1]=false;
	for(i=2; i*i<=n; i++)
		if(is_prime[i] && (ll)i*i<=n)
			for(j=i*i; j<=n; j+=i)
				is_prime[j]=false;

	for(i=0; i<=1000000; i++)
		if(is_prime[i]){
//			cout<<"prime"<<i<<endl;
			s.push_back((ll)i*i);
		}
}
