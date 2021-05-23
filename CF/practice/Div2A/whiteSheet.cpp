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

struct rect{
	ll x1, y1, x2, y2;
	
	ll area(){
		return (x2-x1)*(y2-y1);
	}
};

ll intersect(rect, rect);
rect togOver(rect, rect);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, aw, ab1, ab2, ab;
	rect w, b1, b2;
	
	cin>>w.x1>>w.y1>>w.x2>>w.y2;
	cin>>b1.x1>>b1.y1>>b1.x2>>b1.y2;
	cin>>b2.x1>>b2.y1>>b2.x2>>b2.y2;
	aw=w.area();
	ab1=intersect(w, b1);
	ab2=intersect(w, b2);
	ab=intersect(togOver(b1, b2), w);

	//cout<<aw<<" "<<ab1<<" "<<ab2<<" "<<ab<<endl;
	cout<<(aw>ab1+ab2-ab?"YES":"NO")<<endl;
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
	//cin >> t;
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

ll intersect(rect p, rect q){
	ll xo=max(0LL, min(p.x2, q.x2)-max(p.x1, q.x1));
	ll yo=max(0LL, min(p.y2, q.y2)-max(p.y1, q.y1));
	return xo*yo;
	/*
	ll lf=max(min(p.x1, p.x2), min(q.x1, q.x2));
	ll rg=min(max(p.x1, p.x2), max(q.x1, q.x2));
	ll up=min(max(p.y1, p.y2), max(q.y1, q.y2));
	ll dn=max(min(p.y1, p.y2), min(q.y1, q.y2));
	if(rg<=lf || up<=dn)
		return 0;
	return 1LL*abs(lf-rg)*abs(up-dn);
	*/
}

rect togOver(rect p, rect q){
	ll x1=max(p.x1, q.x1);
	ll x2=min(p.x2, q.x2);
	ll y1=max(p.y1, q.y1);
	ll y2=min(p.y2, q.y2);

	if(x1>x2)
		x1=x2=0;
	if(y1>y2)
		y1=y2=0;

	rect sol;
	sol.x1=x1;
	sol.x2=x2;
	sol.y1=y1;
	sol.y2=y2;

	return sol;
}
