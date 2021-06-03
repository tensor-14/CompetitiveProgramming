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
ll coinChangeMinCoins(ll sum, vector<ll> coins, ll n){
    ll i, j;
    vector<vector<ll>> t(n+1, vector<ll>(sum+1, 0));

    //Initialisation 1
    for(i=1; i<n+1; i++)
        t[i][0]=0;
    for(j=0; j<sum+1; j++)
        t[0][j]=INT_MAX-1;

    //Initialisation 2
    for(j=1; j<sum+1; j++)
        t[1][j]=(j%coins[1]==0?j/coins[1]:INT_MAX-1);

    for(i=2; i<n+1; i++)
        for(j=1; j<sum+1; j++)
            if(coins[i-1]<=j)
                t[i][j]=min(1+t[i][j-coins[i-1]], t[i-1][j]);
            else
                t[i][j]=t[i-1][j];

    return t[n][sum];
}

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, m, sum;
	cin>>n>>sum;
  vector<ll> coins(n);
  for(auto& x:coins)
    cin>>x;

  cout<<coinChangeMinCoins(sum, coins, n)<<endl;
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

