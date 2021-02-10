#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fi first;
#define se second;
#define pb push_back;
#define mp make_pair;
#define fo(a, b, c) for (ll(a) = (b); (a) < (c); ++(a)) 
#define fon(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define fod(a, b, c) for (int(a) = (b); (a) >= (c); --(a)) 
#define fosq(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a)) 
#define foc(a, b, c) for (char(a) = (b); (a) <= (c); ++(a)) 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define SORT(v) sort(all(v))
#define TC(t) while (t--)
#define PI 3.1415926535897932384626
const int M=1e9+7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	ll t=1;
	ll md=998244353;

	ll n,m,sum=0;
	cin>>n;
	vi v(n);

	fo(i,0,n) cin>>v[i];
	cin>>t;

	vi q(t);
	fo(i,0,t) cin>>q[i];

	ll dp[n+1] {0};					//dp array(initialised null)
	ll subsets=(1<<n)-1;		//count_subsets

	fo(i,1,subsets+1){
		ll len = 0;

		fo(j,0,32)
			if(i&(1<<j)){
				len++;
				sum=(sum^v[j])%md;
			}

		dp[len]=(dp[len]+sum)%md;
		sum=0;
	}

	fo(i,1,n+1)
		dp[i]=((dp[i]%md)+(dp[i-1])%md)%md;
	
	for(auto c:q)
		cout<<dp[c]<<endl;
	
	return 0;
}
