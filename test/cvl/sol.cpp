#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int t=1;
	while(t--){
        ll n, T;
        cin >> n >> T;
        vector<ll> a(n);
        for(auto &it: a)
        cin >> it;
    
        ll x = accumulate(a.begin(), a.end(), 0LL);
        ll sum = (T / x) * n;
        T %= x;
        ll cnt = 0;
        for(int i = 0; i < n; i = (i + 1) % n){
            if(cnt == (2 * n))
                break;
            if(T == 0)
                break;
            if(a[i] <= T){
                T -= a[i];
                sum++;
            }
            cnt++;
        }
        cout << sum << endl;
	}

	return 0;
}
