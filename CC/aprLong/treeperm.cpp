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

ll mpow(ll, ll);
int getSet(ll);
void clearVal(ll);
void terClear();
void genGraph(ll,ll);

const int mod=1e9+7;
const int sz=1e6+1;
vector<ll> graph[100001], trackA(sz, 0), trackB(sz, 0), con(sz, 0), tempA(sz, 0), tempB(sz, 0), par(sz, 0), h(sz, 0), vis(sz, 0), vec;
priority_queue<pair<ll,ll>> leafHeap;

ll n, s, tester;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int solve(){
    cin>>n>>s;
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(ll i=1;i<n+1;i++)
        cin>>tempA[i];
    
    for(ll i=1;i<n+1;i++)
        cin>>tempB[i];
    
    for(ll i=1;i<n+1;i++){
        vis[i] = 0;
        par[i] = 0;
        h[i] = 0;
    }

    genGraph(1,1);
    for(ll i=1;i<n+1;i++)
        vis[i]=0;
    
    bool flag = true;
    vector<vector<ll> > sets;
    
    while(!leafHeap.empty()){
        pair<ll,ll> leaf = leafHeap.top();
        leafHeap.pop();
        if(vis[leaf.second]==0){
            tester = 0;
            vec.clear();
            if(getSet(leaf.second)==0){
                flag = false;
                break;
            }
            else
                sets.push_back(vec);
        }
    }

    if(flag==false){
        cout<<0<<endl;
        return 0;
    }
    
    if(s==1){
        cout<<1<<endl;
        return 0;
    }

    ll aa = 1;
    ll x = sets.size();
    for(ll i=0;i<x;i++){
        ll u = sets[i][0];
        ll l = sets[i][0];
        ll sze = sets[i].size();
        
        for(ll j=1;j<sze;j++){
            if(h[sets[i][j]]>h[l])
                l = sets[i][j];
            if(h[sets[i][j]]<h[u])
                u = sets[i][j];
        }
        ll cnt = 0;
        for(ll c: graph[l]){
            if(c!=par[l])
                cnt++;
        }
        aa = (aa*(cnt+1))%mod;
    }
    cout<<aa<<endl;
    return 0;
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
        terClear();
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

void genGraph(ll nodeVal,ll d){
    vis[nodeVal]++;
    h[nodeVal] = d;
    bool is_it = true;
    
    for(ll child:graph[nodeVal]){
        if(!vis[child]){
            par[child] = nodeVal;
            genGraph(child,d+1);
            is_it = false;
        }
    }
    
    if(is_it==true)
        leafHeap.push({d,nodeVal});
}

void terClear(){
    for(ll i=0;i<n+1;i++){
        graph[i].clear();
        tempA[i] = 0;
        tempB[i] = 0;
        par[i] = 0;
        h[i] = 0;
    }
    
    while(!leafHeap.empty())
        leafHeap.pop();
}

void clearVal(ll nodeVal){
    con[tempA[nodeVal]] = 0;
    con[tempB[nodeVal]] = 0;
    trackA[tempA[nodeVal]] = 0;
    trackA[tempB[nodeVal]] = 0;
    trackB[tempA[nodeVal]] = 0;
    trackB[tempB[nodeVal]] = 0;
}

int getSet(ll nodeVal){
    trackB[tempB[nodeVal]]++;
    trackA[tempA[nodeVal]]++;
    
    if(trackA[tempA[nodeVal]]==trackB[tempA[nodeVal]] && con[tempA[nodeVal]]!=0){
        con[tempA[nodeVal]]--;
        tester--;
    }
    else if(con[tempA[nodeVal]]==0){
        con[tempA[nodeVal]]++;
        tester++;
    }
    
    if(trackA[tempB[nodeVal]]==trackB[tempB[nodeVal]] && con[tempB[nodeVal]]!=0){
        con[tempB[nodeVal]]--;
        tester--;
    }
    else if(con[tempB[nodeVal]]==0){
        con[tempB[nodeVal]]++;
        tester++;
    }
    
    vis[nodeVal]++;
    vec.push_back(nodeVal);
    if(tester==0){
        if(vis[par[nodeVal]]==0 && nodeVal!=1)
            leafHeap.push(make_pair(h[par[nodeVal]], par[nodeVal]));
        clearVal(nodeVal);
        return 1;
    }
    
    if(nodeVal==1){
        clearVal(nodeVal);        
        return 0;
    }
    if(vis[par[nodeVal]]==0){
        if(getSet(par[nodeVal])==1){
            clearVal(nodeVal);            
            return 1;
        }
    }
    
    clearVal(nodeVal); 
    return 0;
}