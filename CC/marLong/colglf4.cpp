#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

long long int mpow(int base, int exp); 

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	long long int i, j, n, e, h, a, b, c, lb, ub, cnt;
	cin>>n>>e>>h>>a>>b>>c;
	
	vector<ll> s, v(n+2);

	for(i=0; i<=(n+1); i++)
		v[i]=i;
	
	for(i=0; i<=n; i++){
		lb=lower_bound(v.begin(),v.end(), (2*n-e-2*i))-v.begin();
		ub=upper_bound(v.begin(),v.end(), (h-3*i))-v.begin()-1;
		if(ub<lb || lb==n+1)
			continue;
		if(ub==n+1 && ub+3*i>h)
			continue;
		
		if(c>a)
			cnt=(lb<(n-i)?lb:(n-i));
		else
			cnt=(ub<(n-i)?ub:(n-i));
		
		if(cnt+2*i>=2*n-e && cnt+3*i<=h)
			s.push_back(a*(n-cnt-i)+b*i+c*cnt);
	}
	
	if(s.size() == 0)
		cout<<-1<<"\n";
	else
		cout<<*min_element(s.begin(),s.begin()+(int)s.size())<<"\n";
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

long long int mpow(long long base, long long exp) {
	base %= mod;
	long long int result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((long long)result * base) % mod;
		base = ((long long)base * base) % mod;
		exp >>= 1;
	}
	return result;
}

