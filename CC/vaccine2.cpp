#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

ll solve() {
  ll count=0, risk=0, n, d, val, i;
  vl a;
  sl(n);
  sl(d);
  fo(i,n){
    sl(val);
    if(val>=80 or val<=9)
      risk++;
    a.pb(val);
  }
  n-=risk;
  while(n>0 || risk>0){
    count++;
    if(risk>0){
      risk-=d;
    }
    else{
      n-=d;
    }
  }
  return count;
}

int main() {
  ll t = 1, i;
  vl sol;
  sl(t);
  while(t--) {
    sol.pb(solve());
  }
  fo(i, sol.size())
    pl(sol[i]);
    return 0;
}
