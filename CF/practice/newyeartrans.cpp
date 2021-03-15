#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, t, val, i;
    cin>>n>>t;
    vector<long long int> cells;

    for(i=0; i<n-1; i++){
        cin>>val;
        cells.push_back(val);
    }

    for(i = 0; i < n-1; ){
        if(t==i+1){
            cout<<"YES"<<endl;
            return 0;
        } 
        else if(t>i+1){
            i += cells[i];
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(t==i+1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}