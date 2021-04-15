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
	ll i, j, n, m, k, hor, sol=0, sm, mx, first_, last_, centre_, centrePos;
	bool flag;
	cin>>n>>m>>k;
	n++;
	m++;
	mx=max(n, m);

	vector<vector<double>> mt(n, vector<double>(m, 0));

	for(i=1; i<n; i++)
		for(j=1; j<m; j++)
			cin>>mt[i][j];

	/*
	for(i=1; i<n; i++){
		sm=0;
		for(j=0; j<m; j++){
			mt[i][j]+=sm;
			sm=mt[i][j];
		}
	}

	for(j=0; j<m; j++){
		sm=0;
		for(i=0; i<n; i++){
			mt[i][j]+=sm;
			sm=mt[i][j];
		}
	}

	for(l=0; l<mx; l++)
		for(i=l; i<n; i++)
			for(j=l; j<m; j++)
				if((mt[i][j]+mt[i-l][j-l]-mt[i][j-l]-mt[i-l][j])/(l*l)>=k)
					sol++;
	*/

	for(i=1; i<n; i++)
		for(j=1; j<m; j++)
			mt[i][j]+=mt[i][j-1];

	for(j=1; j<m; j++)
		for(i=1; i<n; i++)
			mt[i][j]+=mt[i-1][j];

	for(hor=1; hor<n; hor++){
		for(i=1; i<n-hor+1; i++){
			first_=1;
			last_=m-hor;
			flag=false;

			while(first_<=last_){
				centre_=(last_+first_)/2;
				ll sm=mt[i+hor-1][centre_+hor-1]-mt[i+hor-1][centre_-1]-mt[i-1][centre_+hor-1]+mt[i-1][centre_-1];

				if(sm>=k*hor*hor){
					last_=centre_-1;
					centrePos=centre_;
					flag=true;
				}
				else
					first_=centre_+1;
			}
			if(flag)
				sol+=(m-hor-centrePos+1);
		}
	}

	cout<<sol<<endl;
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