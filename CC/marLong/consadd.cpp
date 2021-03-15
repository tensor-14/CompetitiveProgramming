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
	ll i, j, n, m, r, c, x, p_sum=0, rep, tot=0, idx_tmp, temp;

	cin>>r>>c>>x;

	vector<vector<ll>> a(r, vector<ll> (c, 0)), b(r, vector<ll> (c, 0)), arr_diff(r, vector<ll> (c, 0));
	ll accum_a=0,accum_b=0;

	for(i=0; i<r; i++)
		for(j=0; j<c; j++){
			cin>>a[i][j];
			accum_a+=a[i][j];
		}

	for(i=0; i<r; i++)
		for(j=0; j<c; j++){
			cin>>b[i][j];
			accum_b+=b[i][j];
		}

	if(x==2 && 0){
		for(i=0; i<r; i++)
			for(j=0; j<c; j++){
				if((r-i+c-j)%2==0) 
					rep=-1;
				else 
					rep=1;
				if(!(i==r-1 && j==c-1)) 
					p_sum+=rep*(a[i][j]-b[i][j]);
			}

		if(a[r-1][c-1]-p_sum==b[r-1][c-1])
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	else{
		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				arr_diff[i][j]=b[i][j]-a[i][j];
		
		for(j=0; j<c; j++){
			tot=0;
			idx_tmp=r-x;
			while(idx_tmp>=0){
				tot += arr_diff[idx_tmp][j];
				idx_tmp -= x;
			}
			for(i=r-1; i>r-x; i--){
				temp=i-x;
				while(temp>=0){
					arr_diff[i][j] += arr_diff[temp][j];
					temp=temp-x;
				}
				arr_diff[i][j] -= tot;
			}
		}
		for(ll i=r-1;i>r-x;i--){
			tot=0;
			idx_tmp=c-x;
			while(idx_tmp>=0){
				tot += arr_diff[i][idx_tmp];
				idx_tmp -= x;
			}
			for(j=c-1; j>c-x; j--){
				temp=j-x;
				while(temp>=0){
					arr_diff[i][j] += arr_diff[i][temp];
					temp=temp-x;
				}
				arr_diff[i][j] -= tot;
			}
		}
		
		bool corr=true;
		for(i=r-1; i>r-x; i--)
			for(j=c-1; j>c-x; j--)
				if(arr_diff[i][j]!=0)
					corr=false;
			
		if(!corr) 
			cout<<"No\n";
		else 
			cout<<"Yes\n";
	}
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

