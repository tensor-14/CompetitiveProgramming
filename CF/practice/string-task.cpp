#include<bits/stdc++.h>
using namespace std;

int main(){
    string in, out;

    cin>> in;
    transform(in.begin(), in.end(), in.begin(), ::tolower);

    for(int i=0; i<in.length(); i++){
        switch (in[i]){
            case 'a': 
                break;
            case 'e': 
                break;
            case 'i': 
                break;
            case 'o': 
                break;
            case 'u': 
                break;
            case 'y':
                break;
            default:
                out+='.';
                out+=in[i];
                break;
        }
    }
    
    cout<<out<<endl;

    return 0;
}