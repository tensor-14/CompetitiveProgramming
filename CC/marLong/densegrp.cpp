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
bool chk_rng(ll a, ll b);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<ll> g[N], frm_paths1, frm_paths2;
int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, m, x, y, path=-1, ways=0;
	cin>>n>>m>>x>>y;

	vector<ll> a(m, -1), b(m, -1), c(m, -1), d(m, -1), temp_sol(m, 0), vec_1, vec_2, chk, check_;
	
	for(i=0; i<m; i++)
		cin>>a[i]>>b[i]>>c[i]>>d[i];

	vec_1.push_back(x);
	vec_2.push_back(x);
	
	if(x==y){
		cout<<0<<"\n";
		return;
	}
	else{
		while((path==-1) && (vec_2.size()!=0)){
		    frm_paths1=vec_1;
		    frm_paths2=vec_2;

		    for(i=0; i<m; i++){
				if((temp_sol[i]==0) && chk_rng(a[i],b[i])){
					if(c[i]<=y && d[i]>=y)
						path=ways+1;
					temp_sol[i]=1;
					chk.push_back(c[i]);
					check_.push_back(d[i]);
				}
			}
			vec_1=chk;
			vec_2=check_;
			ways++;

			frm_paths1.clear();
		    frm_paths2.clear();
			chk.clear();
			check_.clear();
		}
		cout<<path<<endl;
	}
	return;
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

	ll t = 1;
	cin>>t;
	
	while(t--){
		solve();
	}

	return 0;
}

bool chk_rng(ll a, ll b){
	for(ll i=0; i<frm_paths1.size(); i++){
        if(frm_paths1[i]<=b && frm_paths2[i]>=a){
            return true;
        }
    }
    return false;
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