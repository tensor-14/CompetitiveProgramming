#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

long long int mpow(int base, int exp); 

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void solve(){
	ll i, c, n, cnt=0, sz=0, sol=1, temp, a=0, b=0;
	cin>>c;
	temp=c;

	ll arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912,1073741824};
	for(i=0; i<31; i++)
		if(arr[i]>=c){
			n=arr[i];
			break;
		}

	while(temp>0){
		if(temp%2==1)
			cnt++;
		temp/=2;
		sz++;
	}
	temp=c;

	vector<ll> veca(sz), vecb(sz);
	ll idx=0, num=1;
/*
	while(temp>0){
		if(temp%2==0){
			a+=(num);
			b+=(num);
		}
		else{
			if(cnt == 1)
				a+=(num);
			else
				b+=(num);
		}
		num*=2;
		temp/=2;
	}
	cout<<a*b<<"\n";

	temp=c;
	a=b=0;

	*/
	while(temp>0){
		if(temp % 2 == 0){
			veca[idx]=1;
			vecb[idx]=1;
		}
		else{
			if(cnt == 1){
				veca[idx]=1;
				vecb[idx]=0;
			}
			else{
				veca[idx]=0;
				vecb[idx]=1;
			}
			cnt--;
		}
		idx++;
		temp/=2;
	}

	cnt=1;
	for(i=0; i<sz; i++){
		a+=(cnt*veca[i]);
		b+=(cnt*vecb[i]);
		cnt*=2;
	}

	cout<<a*b<<"\n";
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

long long int mpow(long long base, long long exp) {
	base %= mod;
	long long int result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((long long)result * base) % mod;
		base = ((long long)base * base) % mod;
		exp >>= 1;
	}
	return result;
}

