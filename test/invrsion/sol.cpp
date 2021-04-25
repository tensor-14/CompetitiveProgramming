#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t=1;
    while(t--){
        int n;
        cin >> n;
        ll ans=0;
        multiset<ll> s;
        ll arr[n];
        for(int i=0 ; i<n ; i++){
            cin >> arr[i];
            s.insert(arr[i]);
        }
        for(int i=0 ; i<n ; i++){
            auto it=s.upper_bound(arr[i]);
            ans+=distance(it,s.end());
            s.erase(s.find(arr[i]));
        }
        cout << ans << endl;
    }
    return 0;
}