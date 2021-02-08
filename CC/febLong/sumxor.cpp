#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim){
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 998244353;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

vvl subset(vl vec, ll len){
	vvl subsets;
	for (ll i = 0; i < mpow(2, len); i++) {
		ll t = i;
		vector<ll> v;
		for (ll j = 0; j < len; j++) {
			if (t & 1)
				v.push_back(vec[j]);
			t >>= 1;
		}
		subsets.push_back(v);
	}
	return subsets;
}

void smxr(vvl ss, ll sm, ll m){
	ll sum=0, sml;
	for(ll i=0; i<ss.size(); i++){
		sml=0;
		if(ss[i].size()>1 && ss[i].size()<=m){
			for(ll j=0; j<ss[i].size(); j++)
				sml = (sml^ss[i][j])%mod;

			sum += sml;
		}
	}
	sum = (sum+sm)%mod;
	cout<<sum%mod<<"\n";
}

void solve(){
	ll i, j, n, q;
	cin>>n;
	vl a(n);
	fo(i, n)
		cin>>a[i];
	vvl ss = subset(a, a.size());
	cin>>q;
	fo(i, q){
		ll m, sm=0;
		cin>>m;
		sm = (accumulate(all(a), 0))%mod;
		if(m==1)
			cout<<sm%mod<<"\n";
		else
			smxr(ss, sm, m);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}

int mpow(int base, int exp){
	base %= mod;
	int result = 1;
	while (exp > 0){
		if (exp & 1) result = ((ll)result * base) % mod;
	base = ((ll)base * base) % mod;
	exp >>= 1;
	}
	return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

