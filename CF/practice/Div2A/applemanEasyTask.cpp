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

vector<int> g[N];
int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, cnt=0;
	cin>>n;

	/*
	vector<string> chk(n);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			cin>>chk[i][j];

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i>1 && chk[i-1][j]=='o')		//before
				cnt++;
			else if(j>0 && chk[i][j-1]=='o')	//above
				cnt++;
			else if(i<n-1 && chk[i+1][j]=='o')	//after	
				cnt++;
			else if(j<n-1 && chk[i][j+1]=='o')	//below
				cnt++;
		}
	}
	if(cnt%2==0)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	*/

	string s, t, u;
	while(n--){
		cin>>s;
		t+=s;
	}
	u=t;
	reverse(t.begin(), t.end());
	cout<<(u==t?"YES\n":"NO\n");
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

