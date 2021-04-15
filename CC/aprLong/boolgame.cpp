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

int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, m, k, u, v, d, totVal, binMsk, fnd;
	cin>>n>>m>>k;
	vector<ll> g(n+1);
	for(i=0; i<n; i++)
		cin>>g[i+1];
	
	vector<vector<pair<ll,ll>>> inpQuery(n+1), dp(n+1);
	dp[0].push_back(make_pair(0,0));
	vector<pair<ll,ll>> sol;
	set<ll> cntSet, cntDisSet;

	for(i=0; i<m; i++){
    	cin>>u>>v>>d;
		inpQuery[u].push_back(make_pair(i,d));
		inpQuery[v].push_back(make_pair(i,d));
	}

	for(i=1; i<n+1; i++){
		sol.clear();
		sol.insert(sol.end(), dp[i-1].begin(), dp[i-1].end());
		totVal=binMsk=0;
		cntDisSet.clear();
		for(j=i; j>0; j--){
			totVal+=g[j];
			binMsk^=(1LL<<j);
			for(auto& [idx,w]:inpQuery[j]){		//change for G++<17
				if(cntDisSet.count(idx))
					totVal+=w;
                else
					cntDisSet.insert(idx);
			}
			if(j>1)
				for(auto& [val,old_mask]:dp[j-2])	//change for G++<17
					sol.push_back(make_pair(val+totVal,binMsk^old_mask));
			else
				sol.push_back(make_pair(totVal,binMsk));
		}
        
		sort(sol.begin(), sol.end());
		reverse(sol.begin(), sol.end());
		cntSet.clear();
		fnd=0;
		for(j=0; j<sol.size() && fnd<k; j++){
			if(cntSet.count(sol[j].second))
				continue;
			
			dp[i].push_back(sol[j]);
			fnd++;
			cntSet.insert(sol[j].second);
		}
	}

	for(i=0; i<k; i++)
		cout<<dp[n][i].first<<" ";
	cout<<endl;
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

