#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool sortcol( const vector<int>& v1, const vector<int>& v2 ){ 
    return v1[0] < v2[0]; 
} 

int main(){
    int s, n, val, ret;
    bool flag = false;
    cin>>s>>n;

    vector<vector<int>> dra;
    for(int i=0; i<n; i++){
        dra.push_back(vector<int>());
        cin>> val>> ret;
        dra[i].push_back(val);
        dra[i].push_back(ret);
    }
    
    sort(dra.begin(), dra.end(), sortcol);

    for(int i=0; i<n; i++){
        if(s <= dra[i][0]){
            flag = false;
            break;
        }
        else{
            flag = true;
            s+=dra[i][1];
        }
    }

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}