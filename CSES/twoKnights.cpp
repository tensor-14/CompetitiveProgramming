#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++)
        cout<<(i*i*(i*i-1)/2)-(8*(i-2)*(i-1)/2)<<"\n";
    
    return 0;
}