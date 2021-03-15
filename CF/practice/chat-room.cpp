#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, check="hello";
    int pos[5], itr=0;
    bool res = false;
    cin>>s;
    int c_length = 5;

    while(c_length){
        if(itr == 0)
            pos[itr] = s.find(check[itr]);
        else
            pos[itr] = s.find(check[itr], pos[itr-1]+1);
    
        itr++;
        c_length--;
    }

    for (int i = 0; i < 4; i++){
        if(pos[i]<pos[i+1])
            res = true;
        else{
            res = false;
            break;
        }
    }

    if(res)   
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}