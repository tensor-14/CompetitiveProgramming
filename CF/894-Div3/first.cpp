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

int sol(vector<int> arr){
    vector<bool> visited(arr.size(), false);
    int res = 0;
    for(int i=0; i<arr.size(); i++){
        int count = 0, temp = i;
        while(!visited[temp] && temp < arr.size()){
            visited[temp] = true;
            temp = arr[temp];
            count++;
        }
        /*if(!visited[i]){
            int start = arr[i];
            int count = 1;
            while(start < arr.size()){
                start = arr[start];
                count++;
                visited[start] = true;
                
            }

            
        }*/
        res = max(res, count);
    }

    return res;
}

void solve(){
    int n;

    cin>>n;

    vector<int> v(n);
    for(auto &x: v) cin>>x;

    cout<<sol(v)<<endl;
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
    //cin>>t;
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