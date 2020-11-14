#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#define ll long long int
using namespace std;

ll change(ll coins, ll *dp){
    if(dp[coins]!=0)
        return dp[coins];
    else if(coins == 1 || coins == 0)
        return dp[coins] = coins;
    else
        return dp[coins] = max(coins, (change(coins/2, dp) + change(coins/3, dp) + change(coins/4, dp)));
}

int main(){
    ll coins, exch;

    while(cin>>coins){
        ll *dp = new ll[coins+1];
        cout<<change(coins, dp)<<endl;
    }

    return 0;
}