#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin>>x;

    for(int k=31; k>=0;k--){
        if(x & (1<<k)) cout<<"1";
        else cout<<"0";
    }

    cout<<"\n"<<(1<<x)<<endl;
    cout<<endl<<()
}