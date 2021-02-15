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
#define eb emplace_back
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

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

struct HASH{
  static uint64_t splitmix64 (uint64_t x){
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator () (uint64_t x) const{
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now ().time_since_epoch ().count ();
    return splitmix64 (x + FIXED_RANDOM);
  }
};

ll n;
vvl tree;
vl cc;
vector<unordered_map<ll, ll, HASH>> store;
vl sr;
vector<set<pl>> byNow;

void inp(){
  cin >> n;
  tree.resize (n + 1);
  cc.resize (n + 1, 0);
  store.resize (n + 1);
  sr.resize (n + 1);
  byNow.resize (n + 1);
  for (ll i = 2; i <= n; ++i){
    ll x;
    cin >> x;
    tree[x].eb(i);
    cc[x]++;
  }
} 

void conn (ll V){
  sr[V] = V;
  for (auto & child:tree[V]){
    conn (child);
    if (cc[V] == 1)
	  sr[V] = sr[child];
  }
}

void dfs (ll V){
  for (auto & to:tree[V]){
    ll c = to;
    if (cc[V] == 1)
	  c = sr[V];
    if (cc[c] == 0){
	    store[V][cc[V]]++;
	    store[c][1]++;
	    continue;
	  }
    dfs(c);
    for(auto & it:store[c])
	    store[V][cc[V] * 1ll * it.F] += it.S;
  }
}

void solve(){
  inp();
  conn(1);
  dfs(1);
  ll q;
  cin>>q;
  while(q--){
    ll V, w;
    cin >> V >> w;
    V = sr[V];
    auto itr = byNow[V].lower_bound (pl { w, -1 });
    if(itr != byNow[V].end() and itr->F == w){
	    cout<<itr->S<<"\n";
	    continue;
    }
    ll p = 0ll;
    for(auto & i:store[V]){
	    if(i.F and w % i.F == 0)
	      p += (w / i.F) * i.S * 1ll;
    }
    byNow[V].insert (pl{w, w - p});
    cout<<(w - p)<<"\n";
  }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t = 1;
	//cin >> t;
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