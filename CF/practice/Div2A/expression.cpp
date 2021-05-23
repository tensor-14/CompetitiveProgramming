#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    vector<int> sol;

    sol.push_back(a*b*c);
    sol.push_back(a*b+c);
    sol.push_back(a+b+c);
    sol.push_back(a+b*c);
    sol.push_back(a*(b+c));
    sol.push_back((a+b)*c);

    sort(sol.begin(), sol.end());
    cout<<sol[5];

    return 0;
}