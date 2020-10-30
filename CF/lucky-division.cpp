#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool flag = false, flag2 = false;
    cin>>n;

    for(int i=4; i<n^1/2; i++){
        int num = i;
        while(num){
            if(num%10 == 4 || num%10 == 7){
                flag2 = true;
                num/=10;
            }
            else{
                flag2 = false;
                break;
            } 
        }
        if(flag2 && n%i==0)
            flag = true;
    }

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}