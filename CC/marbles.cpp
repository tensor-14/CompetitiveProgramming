#include<bits/stdc++.h>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>

#define ll long long int
using namespace std;

ll nCr(ll n, ll r){
    n-=1;
    r-=n;
    if(r<n)
    ;
}

int main(){
    ll T, n, k;
    while(T--){
        cin>>n>>k;
        cout<<nCr(n, k)<<endl;
    }

    return 0;
}