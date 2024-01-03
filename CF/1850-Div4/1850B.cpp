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

void solve(){
    int n;
    cin>>n;
    int winner = 0, max = 0;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        if(a <= 10 && b > max) {
            max = b;
            winner = i+1;
        }
    }

    cout<<winner<<endl;
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
    cin>>t;
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