#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(inpStr) scanf("%inpStr",inpStr)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(inpStr) printf("%inpStr\n",inpStr)
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
const int N = 1e6+7, M = N;

vector<int> g[N];
int a[N];
vector<ll> dpZero(N), dpOne(N), posZero(N), posOne(N);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, j, n, sz, p=-1, pos;
	string inpStr, sol="1";
	cin>>inpStr;
	n=inpStr.size();

	for(i=0; i<n; i++)
		if(inpStr[i]=='0'){
			for(j=p+1; j<i+1; j++)
				posZero[j]=i;
			p=i;
		}
	p++;
	
	for(i=p; i<n; i++)
		posZero[i]=n;
	
	if(posZero[0]==n){
		cout<<0<<endl;
		return;
	}

	p=-1;
	for(i=0; i<n; i++)
		if(inpStr[i]=='1'){
			for(j=p+1; j<i+1; j++)
				posOne[j]=i;
			p=i;
		}
	p++;

	for(i=p; i<n; i++)
		posOne[i]=n;

	dpZero[n]=dpZero[n+1]=0;
	dpOne[n]=dpOne[n+1]=0;

	for(i=n-1; i>=0; i--){
		dpZero[i]=dpZero[i+1];
		if(inpStr[i]=='0' && posOne[i]<n)
			dpZero[i]=max(dpZero[i], dpZero[posOne[i]+1]+1);
		if(inpStr[i]=='1' && posZero[i]<n)
			dpZero[i]=max(dpZero[i], dpZero[posZero[i]+1]+1);
		dpOne[i]=dpOne[i+1];
		if(posOne[i]<n)
			dpOne[i]=max(dpOne[i], dpZero[posOne[i]+1]+1);
	} 

	sz=dpOne[0]+1;
	pos=posOne[0]+1;
	for(i=1; i<sz; i++){
		if(pos>=n){
			sol.push_back('0');
			continue;
		}
		if(posZero[pos]>=n){
			sol.push_back('0');
			pos=posZero[pos]+1;
			continue;
		}
		if(dpZero[posZero[pos]+1]<sz-i-1){
			sol.push_back('0');
			pos=posZero[pos]+1;
		}
		else{
			sol.push_back('1');
			pos=posOne[pos]+1;
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

