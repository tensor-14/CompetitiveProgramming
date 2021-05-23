#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long int n, m, val, steps=0;
    cin>>n>>m;
    vector<int> hno;
    
    for(long long int i=0; i<m; i++){
        cin>>val;
        hno.push_back(val);
    }

    for(long long int i=0; i<m; i++){
        if(i==0){
            steps = steps + hno[i]-1;
        }
        else if(hno[i]<hno[i-1]){
            steps = steps + n - hno[i-1] + hno[i];
        }
        else if(hno[i]==hno[i-1]){
            continue;
        }
        else{
            steps = steps + hno[i]-hno[i-1];
        }
    }

    cout<<steps<<endl;  

    return 0;
}