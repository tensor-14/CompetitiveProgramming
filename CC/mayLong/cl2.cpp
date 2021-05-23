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
	ll i, j, n, m;
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
	//Conditional operator: Used to perform comparison
	// <, >, <=, >=, == : give boolean(true/false) output
	// false: 0.0, 0, "", false
	// true: non-zero, non-empty string, true
	int a=2;
	int b=2;
	//cout<<(a>b)<<" "<<(a<b)<<" "<<(a==b)<<" "<<(a<=b)<<" "<<(a>=b)<<endl;

	/*
	if(condition/boolean){
		body;
	}
	else if(condition/boolean){
		body;
	}
	else{
		body;
	}
	*/

	//bool data type: keyword=bool, size=1 byte
	//string s="", ss="hello";
	//int x=0, xx=8;
	//float f=0.0, cc=2.3, rr=4.7;
	//bool b=false, bb=true;

	//Loops are used to perform repetitve tasks
	//1. Initialize (only once)
	//2. Condition check (n+1 times)
	//3. Execute body (n times)
	//4. Increment/update (n times) : infinite loop if missing

	bool v=true;

	/*

	while(false){
		cout<<"While\n";
		v=false;
		//a=3; re-initialization
		//a++; incremental update
		//a--; decremental update
	}
*/

	//control flow: it is the direction in which the program executes
	//c++ control flow: top-down flow
/*
	do{
		cout<<"do-while\n";
	}while(false);

	*/

	for(int i=0 ; i<10; i++){
		if(i==5)
			continue;

		cout<<i<<endl;

		if(i==7)
			break;
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

