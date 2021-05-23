#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ar[n][3], flag=0;
     
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            cin>>ar[i][j];
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++)
            flag+=ar[j][i];
        if(flag!=0)
            break;
    }
    
    if(flag)
        cout<<"NO";
    else
        cout<<"YES";
    
    return 0;
}