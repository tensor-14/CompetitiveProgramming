#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    for(int i=0; i<s.length(), i++){
        if(isupper(s[i]))
    }
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s[0] = toupper(s[0]);
    cout<<s;

    return 0;
}