#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define si(u) scanf("%d",&u)
#define sl(u) scanf("%lld",&u)
#define ss(s) scanf("%s",s)
#define pi(u) printf("%d\n",u)
#define pl(u) printf("%lld\n",u)
#define ps(s) printf("%s\n",s)
#define deb(u) cout << #u << "=" << u << endl
#define deb2(u, v) cout << #u << "=" << u << "," << #v << "=" << v << endl
#define PI 3.1415926535897932384626
#define ll long long int
#define endl "\n"

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
ll rng(ll lim) {
	uniform_int_distribution<ll> uid(0,lim-1);
	return uid(rang);
}

ll mpow(ll base, ll exp); 
ll dfs(ll node);
ll cap_node(ll node);
void inv_num(ll pnum);
void inv_fac(ll pnum);
void fac(ll pnum);
ll bin(ll N, ll R, ll pnum);

const ll mod = 1'000'000'007;
const ll N = 5e5+5, M = N;

vector<ll> g[N];
ll a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ll fac_inv_num[N + 1], nat_inv_num[N + 1], fact[N + 1], n;
vector<vector<ll>> adjacent_;
vector<ll> vec, tw, st;
vector<pair<ll, pair<ll, ll>>> max_paa;

void solve(){
    ll  k;
    cin>>n>>k;
    ll m=n-1;
    adjacent_.clear(), vec.clear(), tw.clear();
    adjacent_.resize(n), vec.resize(n, 0), tw.resize(n);
    while(m--) {
        ll u,v;
        cin>>u>>v;
        adjacent_[u-1].push_back(v-1);
        adjacent_[v-1].push_back(u-1);
    }
    
    if(n==1){
        ll pt1=0,pt2=0;
        if(k==1){
            vec.clear(), tw.clear();
            vec.resize(n, 0), tw.resize(n);
            dfs(pt1);
            cout<<pt1+1<<" "<<tw[pt1]%mod<<endl;
        } 
        else{
            vec.clear(), tw.clear();
            vec.resize(n, 0), tw.resize(n);
            dfs(pt2);
            cout<<pt2+1<<" "<<tw[pt2]%mod<<endl;
        }
        return;
    }
    
    max_paa.clear(), st.clear(), st.resize(n);
    cap_node(0);
    ll idx=1;
    sort(max_paa.begin(), max_paa.end(), greater<pair<ll, pair<ll, ll>>>());
    ll pt1,pt2;

    if(max_paa[0].first != max_paa[1].first){        
        ll X = max_paa[0].second.first, Y = max_paa[0].second.second;
        if(st[X] == n-st[X]){
            pt1=max(X, Y);
            pt2=min(X, Y);
        } 
        else{
            if(st[X] > n-st[X]){
                pt1=X;
                pt2=Y;
            } 
            else{
                pt2=X;
                pt1=Y;
            }
        }
    }
    else{
        vector<ll> temp_vec;
        
        if((max_paa[0].second.first == max_paa[1].second.first) || (max_paa[0].second.first == max_paa[1].second.second))
            pt1 = max_paa[0].second.first;
        else 
            pt1 = max_paa[0].second.second;
        
        idx = 1;
        temp_vec.push_back((max_paa[0].second.first != pt1)? max_paa[0].second.first : max_paa[0].second.second);
        
        while(idx!=n && max_paa[idx-1].first == max_paa[idx].first ){
            temp_vec.push_back((max_paa[idx].second.first != pt1)? max_paa[idx].second.first : max_paa[idx].second.second);
            ++idx;
        }
        pt2 = *max_element(temp_vec.begin(), temp_vec.end());
    }
    
    if(k==1){
        vec.clear(), tw.clear();
        vec.resize(n, 0), tw.resize(n);
        dfs(pt1);
        cout<<pt1+1<<" "<<((tw[pt1]%mod) +mod)%mod<<endl;
    }
    else{
        vec.clear(), tw.clear();
        vec.resize(n, 0), tw.resize(n);
        dfs(pt2);
        cout<<pt2+1<<" "<<((tw[pt2]%mod)+mod)%mod<<endl;
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

    fac(mod);
    inv_num(mod);
    inv_fac(mod);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}

    return 0;
}

ll dfs(ll node) {
    vec[node] = 1;
    ll sol=1, sub=0;
    for(auto u: adjacent_[node]) {
        if(vec[u] == 0) {
            ll curr_s = dfs(u);
            sub += curr_s;
            sol*= bin(sub, curr_s, mod);
            sol%=mod;
            sol*=tw[u];
            sol%=mod;
        }
    }
    sol%=mod;
    tw[node] = sol;
    return sub+1;
}

ll cap_node(ll node) {
    vec[node] = 1;
    ll sub=0, curr;
    for(auto u: adjacent_[node]) {
        if(vec[u] == 0) {
            curr = cap_node(u);
            sub += curr;
    ll te = min(curr,(n-curr));
            max_paa.push_back({te, {u, node}});
        }
    }
    st[node] = sub+1;
    return sub+1;
}

void inv_num(ll pnum){
    nat_inv_num[0] = nat_inv_num[1] = 1;
    for (ll i = 2; i <= N; i++)
        nat_inv_num[i] = nat_inv_num[pnum % i] * (pnum - pnum / i) % pnum;
}

void inv_fac(ll pnum){
    fac_inv_num[0] = fac_inv_num[1] = 1;
    for (ll i = 2; i <= N; i++)
        fac_inv_num[i] = (nat_inv_num[i] * fac_inv_num[i - 1]) % pnum;
}

void fac(ll pnum){
    fact[0] = 1;
    for (ll i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % pnum;
}

ll bin(ll N, ll R, ll pnum) {
    if(R>N) 
        return 0;
    if(R==N) 
        return 1;

    ll sol = ((fact[N] * fac_inv_num[R]) % pnum * fac_inv_num[N - R]) % pnum;
    return sol;
}
