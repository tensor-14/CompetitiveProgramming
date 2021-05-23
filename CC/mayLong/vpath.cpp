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
void dfs(ll, ll);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];
ll sol;
vector<ll>adjList[(ll)3e5+1], subValue(1e5+1), value(1e5+1);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, m;
    cin>>n;

	sol=0;
	for(i=0; i<n+1; i++){
		adjList[i].clear();
		subValue[i]=1;
		value[i]=0;
	}
    
    for(j=0; j<n-1; j++){
        ll u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
	dfs(1,1);
    cout<<sol%mod<<endl;
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

void dfs(ll curr, ll last){
    ll cnt=0, temp;
	
	for(auto x : adjList[curr]) {
        if(x==last)
			continue;
        dfs(x, curr);
		subValue[curr]+=((2*subValue[x])%mod);
		cnt++;
		value[curr]+=(value[x]%mod);
	}
	
    subValue[curr]-=cnt;
    value[curr]+=(subValue[curr]%mod);
    sol+=(subValue[curr]%mod);
	temp=subValue[curr]-1;

	for(auto x : adjList[curr])
        if (x != last){
            temp-=(value[x]%mod);
            sol+=((2*temp*value[x])%mod);
        }
}