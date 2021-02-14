#pragma GsolFunc1solFunc1 optimize("Ofast")
#pragma GsolFunc1solFunc1 optimization("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
//#define int ll
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
//#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim){
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

//const ll mod = 998244353;
const ll N = 200007, M = N;
//=======================

vi g[N];
int a[N];

const ll mod = 998244353, md = 998244353;
using ld = long double;

struct base{
  double x, y;
  base (){
		x = y = 0;
	}
	base (double x, double y):x (x), y (y){
	}
};

inline base operator + (base a, base b){
  return base (a.x + b.x, a.y + b.y);
}

inline base operator - (base a, base b){
	return base (a.x - b.x, a.y - b.y);
}

inline base operator * (base a, base b){
  return base (a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

inline base conj (base a){
  return base (a.x, -a.y);
}

ll lim = 1;

vector < base > roots ={{0, 0},{1, 0}};
vl rev = { 0, 1 };

const double PI = acosl (-1.0);

void ensure_base (ll p){
  if (p <= lim)
    return;
  rev.resize (1 << p);

  for (ll i = 0; i < (1 << p); i++)
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (p - 1));
  roots.resize (1 << p);

  while (lim < p){
    double angle = 2 * PI / (1 << (lim + 1));
    for (ll i = 1 << (lim - 1); i < (1 << lim); i++){
		  roots[i << 1] = roots[i];
		  double angle_i = angle * (2 * i + 1 - (1 << lim));
			roots[(i << 1) + 1] = base (cos (angle_i), sin (angle_i));
		}

		lim++;
	}
}

void fourierTransform (vector < base > &a, ll n = -1){
  if (n == -1)
    n = a.size ();
  assert ((n & (n - 1)) == 0);
  ll zeros = __builtin_ctz (n);
  ensure_base (zeros);
  ll shift = lim - zeros;
	ll i;

  fo (i, n)
    if (i < (rev[i] >> shift))
      swap (a[i], a[rev[i] >> shift]);

  for(ll k = 1; k < n; k <<= 1){
    for (ll i = 0; i < n; i += 2 * k){
			for (ll j = 0; j < k; j++){
	      base z = a[i + j + k] * roots[j + k];
	      a[i + j + k] = a[i + j] - z;
	      a[i + j] = a[i + j] + z;
			}
		}
	}
}

vl mult_ (vl &a, vl &b, ll eq = 0){
  ll need = a.size () + b.size () - 1;
  ll p = 0;
  while ((1 << p) < need)
    p++;
  ensure_base (p);
  ll sz = 1 << p;
  vector < base > A, B;
  if (sz > (ll) A.size ())
    A.resize (sz);
  for(ll i = 0; i < (ll) a.size (); i++){
      ll x = (a[i] % mod + mod) % mod;
      A[i] = base (x & ((1 << 15) - 1), x >> 15);
    } 
	fill (A.begin () + a.size (), A.begin () + sz, base{0, 0});
  fourierTransform (A, sz);
  if (sz > (ll) B.size ())
    B.resize (sz);
  if (eq)
    copy (A.begin (), A.begin () + sz, B.begin ());
  else{
    for (ll i = 0; i < (ll) b.size (); i++){
			ll x = (b[i] % mod + mod) % mod;
			B[i] = base (x & ((1 << 15) - 1), x >> 15);
		}
		fill (B.begin () + b.size (), B.begin () + sz, base{0, 0});
    fourierTransform (B, sz);
  }
	
	double ratio = 0.25 / sz;
  base r2 (0, -1), r3 (ratio, 0), r4 (0, -ratio), r5 (0, 1);
  for (ll i = 0; i <= (sz >> 1); i++){
    ll j = (sz - i) & (sz - 1);
    base a1 = (A[i] + conj (A[j])), a2 = (A[i] - conj (A[j])) * r2;
    base b1 = (B[i] + conj (B[j])) * r3, b2 = (B[i] - conj (B[j])) * r4;
    if (i != j){
			base c1 = (A[j] + conj (A[i])), c2 = (A[j] - conj (A[i])) * r2;
			base d1 = (B[j] + conj (B[i])) * r3, d2 = (B[j] - conj (B[i])) * r4;
			A[i] = c1 * d1 + c2 * d2 * r5;
			B[i] = c1 * d2 + c2 * d1;
		}
    
		A[j] = a1 * b1 + a2 * b2 * r5;
    B[j] = a1 * b2 + a2 * b1;
  }
  
	fourierTransform (A, sz);
  fourierTransform (B, sz);
  vl res (need);
  for (ll i = 0; i < need; i++){
    ll aa = A[i].x + 0.5;
    ll bb = B[i].x + 0.5;
    ll cc = A[i].y + 0.5;
    res[i] = (aa + ((bb % mod) << 15) + ((cc % mod) << 30)) % mod;
  } 

	return res;
}

template < ll MOD > struct modint{
  ll value;
  modint () = default;
  modint (ll value_):value (value_){
	}

  inline modint < MOD > operator + (modint < MOD > other) const{
    ll c = this->value + other.value;
    return modint < MOD > (c >= MOD ? c - MOD : c);
  }

  inline modint < MOD > operator - (modint < MOD > other) const{
    ll c = this->value - other.value;
    return modint < MOD > (c < 0 ? c + MOD : c);
  }

  inline modint < MOD > operator * (modint < MOD > other) const{
    ll c = (int64_t) this->value * other.value % MOD;
    return modint < MOD > (c < 0 ? c + MOD : c);
  }

  inline modint < MOD > &operator += (modint < MOD > other){
    this->value += other.value;
    if (this->value >= MOD)
      this->value -= MOD;
    return *this;
  }

  inline modint < MOD > &operator -= (modint < MOD > other){
    this->value -= other.value;
    if (this->value < 0)
      this->value += MOD;
    return *this;
  }

  inline modint < MOD > &operator *= (modint < MOD > other){
    this->value = (int64_t) this->value * other.value % MOD;
    if (this->value < 0)
      this->value += MOD;
    return *this;
  }

  inline modint < MOD > operator - () const{
    return modint < MOD > (this->value ? MOD - this->value : 0);
  }

  modint < MOD > pow (uint64_t k) const{
    modint < MOD > x = *this, y = 1;
    for (; k; k >>= 1){
			if (k & 1)
				y *= x;
			x *= x;
    }
    
		return y;
  }
  
	modint < MOD > inv ()const{
    return pow (MOD - 2);
  }

  inline modint < MOD > operator / (modint < MOD > other) const{
    return *this * other.inv ();
  }

  inline modint < MOD > operator /= (modint < MOD > other){
    return *this *= other.inv ();
  }

  inline bool operator == (modint < MOD > other) const{
    return value == other.value;
  }

  inline bool operator != (modint < MOD > other) const{
    return value != other.value;
  }

  inline bool operator < (modint < MOD > other) const{
    return value < other.value;
  }

  inline bool operator > (modint < MOD > other) const{
    return value > other.value;
  }
};

template < ll MOD > modint < MOD > operator * (int64_t value, modint < MOD > n){
  return modint < MOD > (value) * n;
}

template < int MOD > modint < MOD > operator * (ll value, modint < MOD > n){
  return modint < MOD > (value % MOD) * n;
}

template < int32_t MOD > ostream & operator << (ostream & out, modint < MOD > n){
  return out << n.value;
}

using mint = modint < mod >;
struct polynomial{
  vector < mint > a;
  inline void normalize (){
    while ((int) a.size () && a.back () == 0)
      a.pop_back ();
  }
	
	template < class ... Args > polynomial (Args ... args):a (args ...){
  }
	
	polynomial (const initializer_list < mint > &x):a (x.begin (), x.end ()){
  } 
	
	ll size () const{
    return (ll) a.size ();
  } 

	inline mint coef (const ll i) const{
    return (i < a.size () && i >= 0) ? a[i] : mint (0);
  }

  mint operator[] (const ll i) const{
    return (i < a.size () && i >= 0) ? a[i] : mint (0);
  }

  bool is_zero () const{
    for (ll i = 0; i < size (); i++)
      if (a[i] != 0)
	return 0;
    return 1;
  }

  polynomial operator + (const polynomial & x) const{
    ll n = max (size (), x.size ());
    vector < mint > sol (n);
    for (ll i = 0; i < n; i++)
      sol[i] = coef (i) + x.coef (i);
    
		while ((ll) sol.size () && sol.back () == 0)
      sol.pop_back ();
    return sol;
  }

  polynomial operator - (const polynomial & x) const{
    ll n = max (size (), x.size ());
    vector < mint > sol (n);
    
		for (ll i = 0; i < n; i++)
      sol[i] = coef (i) - x.coef (i);

    while ((ll) sol.size () && sol.back () == 0)
      sol.pop_back ();
    return sol;
  }

  polynomial operator * (const polynomial & b) const{
    if (is_zero () || b.is_zero ())
      return{};
    vl A, B;
		for (auto x:a)
      A.push_back (x.value);
		for (auto x:b.a)
      B.push_back (x.value);
    auto res = mult_ (A, B, (A == B));
    vector < mint > sol;
		for (auto x:res)
      sol.push_back (mint (x));
    while ((ll) sol.size () && sol.back () == 0)
      sol.pop_back ();
    return sol;
  }

  polynomial operator * (const mint & x) const{
    ll n = size ();
    vector < mint > sol (n);
    for (ll i = 0; i < n; i++)
      sol[i] = a[i] * x;
    return sol;
  }

  polynomial operator / (const mint & x) const{
    return (*this) * x.inv ();
  }

  polynomial & operator += (const polynomial & x){
    return *this = (*this) + x;
  }

  polynomial & operator -= (const polynomial & x){
    return *this = (*this) - x;
  }

  polynomial & operator *= (const polynomial & x){
    return *this = (*this) * x;
  }

  polynomial & operator *= (const mint & x){
    return *this = (*this) * x;
  }

  polynomial & operator /= (const mint & x){
    return *this = (*this) / x;
  }

  polynomial mod_xk (ll k) const{
    return{a.begin (), a.begin () + min (k, size ())};
  }

  polynomial mul_xk (ll k) const{
    polynomial sol (*this);
    sol.a.insert (sol.a.begin (), k, 0);
    return sol;
  }

  polynomial div_xk (ll k) const{
    return vector < mint > (a.begin () + min (k, (ll) a.size ()), a.end ());
  } 

	polynomial substr (ll l, ll r) const{
    l = min (l, size ());
    r = min (r, size ());
    return vector < mint > (a.begin () + l, a.begin () + r);
  }

  polynomial reverse_it (ll n, bool rev = 0) const{
    polynomial sol (*this);
    if (rev){
			sol.a.resize (max (n, (ll) sol.a.size ()));
    }
    
		reverse (sol.a.begin (), sol.a.end ());
    return sol.mod_xk (n);
  }

  polynomial differentiate () const{
    ll n = size ();
    vector < mint > sol (n);
    for (ll i = 1; i < size (); i++)
      sol[i - 1] = coef (i) * i;
    return sol;
  }

  polynomial inverse (ll n) const{
    assert (!is_zero ());
    assert (a[0] != 0);
    polynomial sol{mint (1) / a[0]};
    for (ll i = 1; i < n; i *= 2){
			sol = (sol * mint (2) - sol * sol * mod_xk (2 * i)).mod_xk (2 * i);
    } 
		return sol.mod_xk (n);
  }

  pair < polynomial, polynomial > divmod_slow (const polynomial & b) const{
    vector < mint > A (a);
    vector < mint > sol;
    while (A.size () >= b.a.size ()){
			sol.push_back (A.back () / b.a.back ());
			if (sol.back () != mint (0)){
				for (size_t i = 0; i < b.a.size (); i++){
					A[A.size () - i - 1] -=
					sol.back () * b.a[b.a.size () - i - 1];
	      }
			}
			A.pop_back ();
    }
    reverse (sol.begin (), sol.end ());
    return{sol, A};
  }

  pair < polynomial, polynomial > divmod (const polynomial & b) const{
    if (size () < b.size ())
      return{polynomial{0}, *this};

    ll d = size () - b.size ();
    if (min (d, b.size ()) < 250)
      return divmod_slow (b);
    polynomial D = (reverse_it (d + 1) * b.reverse_it (d + 1).inverse (d + 1)).mod_xk (d + 1).reverse_it (d + 1, 1);
    return{D, *this - (D * b)};
	}

  polynomial operator / (const polynomial & t) const{
    return divmod (t).first;
  }

  polynomial operator % (const polynomial & t) const{
    return divmod (t).second;
  }

  polynomial & operator /= (const polynomial & t){
    return *this = divmod (t).first;
  }

  polynomial & operator %= (const polynomial & t){
    return *this = divmod (t).second;
  }

  mint eval (mint x){
		mint sol (0);
    for (ll i = (int)size () - 1; i >= 0; i--){
			sol *= x;
			sol += a[i];
    } 
		return sol;
  }

  polynomial build (vector < polynomial > &sol, ll v, ll l, ll r, vector < mint > &vec){
    if (l == r)
      return sol[v] = polynomial ({-vec[l], 1});
    ll mid = l + r >> 1;
    return sol[v] = build (sol, 2 * v, l, mid, vec) * build (sol, 2 * v + 1, mid + 1, r, vec);
  }

  vector < mint > eval (vector < polynomial > &tree, ll v, ll l, ll r, vector < mint > &vec){
    if (l == r)
      return {eval (vec[l])};
    if (size () < 100){
			vector < mint > sol (r - l + 1, 0);
			for (ll i = l; i <= r; i++)
				sol[i - l] = eval (vec[i]);
			return sol;
    }
    
		ll mid = l + r >> 1;
    auto A = (*this % tree[2 * v]).eval (tree, 2 * v, l, mid, vec);
    auto B = (*this % tree[2 * v + 1]).eval (tree, 2 * v + 1, mid + 1, r, vec);
    A.insert (A.end (), B.begin (), B.end ());
    return A;
  }

  vector < mint > eval (vector < mint > x){
    ll n = x.size ();
    if (is_zero ())
      return vector < mint > (n, mint (0));
    vector < polynomial > tree (4 * n);
    build (tree, 1, 0, n - 1, x);
    return eval (tree, 1, 0, n - 1, x);
  }
};

polynomial mul (ll l, ll r, vector < mint > &a){
  if (l == r)
    return polynomial ({-a[l], 1});
  ll mid = l + r >> 1;
  return mul (l, mid, a) * mul (mid + 1, r, a);
}

ll mul (ll a, ll b){
  return (1LL * a * b) % mod;
}

ll add (ll a, ll b){
  ll s = (a + b);
  if (s >= mod)
    s -= mod;
  return s;
}

ll sub (ll a, ll b){
  ll s = (a + mod - b);
  if (s >= mod)
    s -= mod;
  return s;
}

ll po (ll a, ll deg){
  if (deg == 0)
    return 1;
  if (deg % 2 == 1)
    return mul (a, po (a, deg - 1));
  ll t = po (a, deg / 2);
  return mul (t, t);
}

ll inv (ll n){
  return po (n, mod - 2);
}

vl facs (N), invfacs (N);

void init(){
  facs[0] = 1;
  for (ll i = 1; i < N; i++)
    facs[i] = mul (facs[i - 1], i);
  invfacs[N - 1] = inv (facs[N - 1]);
  for (ll i = N - 2; i >= 0; i--)
    invfacs[i] = mul (invfacs[i + 1], i + 1);
} 

ll solFunc1 (ll n, ll k){
  if (n < k)
    return 0;
  return mul (facs[n], mul (invfacs[k], invfacs[n - k]));
}

ll fac (ll x){
  if (x == 0)
    return 1;
  ll cnt = x / mod;
  ll res = mul (facs[x % mod], fac (cnt));
  if (cnt % 2 == 1)
    res = sub (0, res);
  return res;
}

ll solFunc2 (ll x, ll y){
  ll x1 = x;
  ll y1 = y;
  while (y1){
    if (y1 % mod > x1 % mod)
			return 0;
      x1 /= mod;
      y1 /= mod;
  }
  return mul (fac (x), inv (mul (fac (y), fac (x - y))));
}

void solve(){
	ll i, j, n, q;
	init ();
  cin >> n;
  vl v(n);
  fo(i, n)
    cin >> v[i];

	vvl nbit(n + 1, vl (32, 0));
  vl ct (32, 0);
  fo(i, n){
		for(j = 0; j < 32; j++){
			if ((v[i] >> j) & 1)
				ct[j]++;
		}
  }
  
	for(j = 0; j < 32; j++){
    vl v1 (ct[j] + 1, 0);
    vl v2 (n - ct[j] + 1, 0);
    fo(i, n){
			if (i % 2 && i <= ct[j])
				v1[i] = solFunc1 (ct[j], i);
			if (i <= n - ct[j])
				v2[i] = solFunc1 (n - ct[j], i);
		}

    vl v3 = mult_ (v1, v2);
    for(i = 1; i <= n; i++)
			nbit[i][j] = nbit[i - 1][j] + v3[i];
    
	} 

  cin >> q;
  while (q--){
    ll m;
    cin >> m;
    ll sol = 0;
    for (i = 0; i < 32; i++){
			sol += (nbit[m][i] % md * (1ll << i) % mod) % mod;
			sol %= md;
		} 
		cout << sol << endl;
  }
}



int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}

int mpow(int base, int exp){
	base %= mod;
	int result = 1;
	while (exp > 0){
		if (exp & 1) result = ((ll)result * base) % mod;
	base = ((ll)base * base) % mod;
	exp >>= 1;
	}
	return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

