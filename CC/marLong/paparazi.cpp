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
#define ld long double

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
	ll i, j, n, m, val, sol=1, size_;
	ld temp, temp_2;
	cin>>n;

    vector<pair<ll, ll>> h, sol_vp;
        
	for(i=0;i<n;i++){
        cin>>val;
		h.push_back({i+1, val});
    }

    if(n==2){
    	cout<<1<<"\n";
		return;
	}
    
	sol_vp.push_back(h[0]);
	sol_vp.push_back(h[1]);
    size_=sol_vp.size();
    
	for(i=2; i<n; i++){
        while(sol_vp.size()>=2) {
            temp = ((ld)sol_vp[size_-1].second - (ld)sol_vp[size_-2].second);
			temp/=((ld)sol_vp[size_-1].first - (ld)sol_vp[size_-2].first);

            temp_2 = ((ld)h[i].second - (ld)sol_vp[size_-1].second);
			temp_2/=((ld)h[i].first - (ld)sol_vp[size_-1].first);

            if(temp <= temp_2){
                sol_vp.pop_back();
				size_--;
            } 
			else
				break;
        }

        sol_vp.push_back(h[i]);
		size_++;

        sol = max(sol, sol_vp[size_-1].first - sol_vp[size_-2].first);
    }

    cout<<sol<<"\n";
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

