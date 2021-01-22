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

const int mod = 1'000'000'007;
const int N = 1e6 + 12, M = N;
//=======================

vi g[N];
int cnt[N];

void reset(vector<int> a){
  for (int i = 0; i < a.size(); i++)
    cnt[a[i]] = 0;
}
 
void solve(){
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  int t = 0;
  for (int i = 0; i < 2 * n - 1; i++){
    for (int j = 0; j < 2 * n; j++)
      cnt[a[j]]++;
    int j = 2 * n - 1;
    int x = a[i] + a[j];
    vector<int> rm;
    for (int op = 0; op < n; op++){
      while (j > 0 && cnt[a[j]] == 0)
        j--;
      rm.push_back(a[j]);
      rm.push_back(x - a[j]);
      cnt[a[j]]--, cnt[x - a[j]]--;
      if (cnt[a[j]] < 0 || cnt[x - a[j]] < 0){
        cnt[a[j]] = 0;
        cnt[x - a[j]] = 0;
        break;
      }
      x = max(x - a[j], a[j]);
      if (op + 1 == n)
        t = 1;
    }
    reset(a);
    if (t){
      cout << "YES\n";
      cout << rm[0] + rm[1] << "\n";
      for (int i = 0; i < rm.size(); i++){
        cout << rm[i] << " \n"[i % 2];
      }
			return;
    }
  }
  cout << "NO\n";
  reset(a);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t = 1;
	cin >> t;
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


