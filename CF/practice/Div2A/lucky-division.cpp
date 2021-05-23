#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, num[14] = {4, 7, 44, 77, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
    bool flag = false;
    cin>>n;

    for(int i=0; i<14; i++){
        if(n%num[i]==0){
            flag=true;
            break;
        }
    }
        
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}