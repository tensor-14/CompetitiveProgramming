#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(inp) scanf("%inp",inp)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(inp) printf("%inp\n",inp)
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
bool winCheck(char);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];
vector<string> inp(3);
ll X, O, space;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, m;
	bool XWin, OWin;
	for(i=0; i<3; i++)
		cin>>inp[i];

	X=O=0;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++){
			if(inp[i][j]=='X')
				X++;
			if(inp[i][j]=='O')
				O++;
		}
	space = 9-X-O;

	if((X<O) || (X>O+1)){
		cout<<3<<endl;
		return;
	}
	else{	
		XWin = winCheck('X');
		OWin = winCheck('O');

		if((XWin && OWin) || (XWin && X == O) || (OWin && X > O)){
			cout<<3<<endl;
			return;
		}
		else if((XWin || OWin) || (space == 0)){
			cout<<1<<endl;
			return;
		}
		else{
			cout<<2<<endl;
			return;
		}
	}
	cout<<m<<endl;
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

bool winCheck(char ch){
	ll i;
	if((inp[0][0]==ch) && (inp[0][0]==inp[1][1]) && (inp[1][1]==inp[2][2]))
		return true;
	if((inp[0][2]==ch) && (inp[0][2]==inp[1][1]) && (inp[1][1]==inp[2][0]))
		return true;
	
	for(i=0; i<3; i++){
		if((inp[i][0]==ch) && (inp[i][0]==inp[i][1]) && (inp[i][1]==inp[i][2]))
			return true;
		if ((inp[0][i]==ch) && (inp[0][i]==inp[1][i]) && (inp[1][i]==inp[2][i]))
			return true;
	}

	return false;
}