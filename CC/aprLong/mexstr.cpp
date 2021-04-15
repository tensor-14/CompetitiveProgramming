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
bool chkSubseq(string, string);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	unsigned int i, j, n, m;
	string s, s2, binary;
	bool flag=true;
	queue<string> numCr;

	cin>>s;
	n=stoi(s, 0, 2);

	if(s.find("0") != string::npos)
		flag=false;

	if(flag)
		cout<<0<<endl;
	else{
		numCr.push("1");
		while(true){
			binary=numCr.front();
			numCr.pop();

			if(!chkSubseq(binary, s))
				break;
		
			s2=binary;
			numCr.push(binary.append("0"));
			numCr.push(s2.append("1"));
		}
		cout<<binary<<endl;
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

bool chkSubseq(string binary, string s){
	int j=0, i=0;
	for(; i<s.size(); i++){
		if(binary[j]==s[i])
			j++;
		if(j==binary.size())
			return true;
	}
	return false;
}
