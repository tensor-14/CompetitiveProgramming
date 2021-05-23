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

class kingdom_tree{
	public:
		ll value, dpth;
		vector<kingdom_tree*> child;
		kingdom_tree(ll x){
			value=x;
			dpth=0;
		}
};

ll mpow(ll, ll); 
void DFS2(kingdom_tree*);
void DFS(kingdom_tree*, ll);
void makeTreeStruc(kingdom_tree*, vector<vector<ll>>&, vector<bool>&);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];
//vector<vector<ll>> adjacent(2e5+1);
//vector<bool> visited(2e5+1, false);
vector<pair<ll, ll>> cities;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, m, u, v, daysRequired, nm;
	cin>>n;
	vector<ll> assassins;
	vector<vector<ll>> adjacent(n);
	vector<bool> visited(n, false);
	vector<pair<ll, ll>> tempSol, vecTempSol;
	bool flag;

	for(i=0; i<n-1; i++){
		cin>>u>>v;
		u--;
		v--;
		adjacent[u].push_back(v);
		adjacent[v].push_back(u);
	}

	kingdom_tree *root=new kingdom_tree(0);

	makeTreeStruc(root, adjacent, visited);
	DFS(root, 0);

	for(i=0; i<root->child.size(); i++){
		DFS2(root->child[i]);
		vector<pair<ll, ll>> vecTempSol;
		pair<ll, ll> pairTemp;
		bool flag=false;
		
		sort(cities.begin(), cities.end());
		pairTemp=cities[0];
		vecTempSol.push_back(pairTemp);
		nm=pairTemp.first;
		j=1;
		while(j<cities.size()){
			while(j<cities.size() && cities[j].first==nm){
				if(flag)
					vecTempSol.push_back(make_pair(pairTemp.first+1, cities[j].second));
				else
					vecTempSol.push_back(cities[j]);
				j++;
			}
			if(j<cities.size()){
				vecTempSol.clear();
				flag=true;
				pairTemp.second=cities[j].second;
				vecTempSol.push_back(make_pair(pairTemp.first+1, cities[j].second));
				nm=cities[j].first;
				j++;
			}
		}

		cities.clear();
		for(auto x:vecTempSol)
			tempSol.push_back(x);
	}

	sort(tempSol.begin(), tempSol.end());
	daysRequired=tempSol[0].first;

	/*
	for(auto [f, s]:tempSol)
		if(f==daysRequired)
			assassins.push_back(s);
		else
			break;
	*/

	for(i=0; i<tempSol.size(); i++)
		if(tempSol[i].first==daysRequired)
			assassins.push_back(tempSol[i].second);
		else
			break;
	cout<<assassins.size()<<" "<<daysRequired<<endl;
	for(auto x:assassins)
		cout<<x<<" ";
	
	cout<<endl;
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

void DFS2(kingdom_tree* root){
	for(ll i=0; i<root->child.size(); i++){
		kingdom_tree* current=root->child[i];
		DFS2(current);
	}
	if(!root->child.size())
		cities.push_back(make_pair(root->dpth, root->value+1));
}

void DFS(kingdom_tree* root, ll l){
	root->dpth=l;
	for(ll i=0; i<root->child.size(); i++){
		kingdom_tree* current=root->child[i];
		DFS(current, l+1);
	}
}

void makeTreeStruc(kingdom_tree* root, vector<vector<ll>>& adjacent, vector<bool>& visited){
	visited[root->value]=true;
	for(ll i=0; i<adjacent[root->value].size(); i++)
		if(!visited[adjacent[root->value][i]]){
			kingdom_tree* temp=new kingdom_tree(adjacent[root->value][i]);
			root->child.push_back(temp);
		}
	
	for(ll i=0; i<root->child.size(); i++)
		makeTreeStruc(root->child[i], adjacent, visited);
}