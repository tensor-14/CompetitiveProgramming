#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    bool flag;
    cin>>s;

    for(int i=1; i<s.length(); i++){
        if(isupper(s[i]))
            flag = true;
        else{
            flag = false;
            break;
        }
    }

    if(flag and isupper(s[0])){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    else if(flag and islower(s[0])){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s[0] = toupper(s[0]);
    }
    
    cout<<s;

    return 0;
}