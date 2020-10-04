#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int n;
    string wrds[100];

    cin>>n;

    for(int i=0; i<n; i++){
        getline(cin, wrds[i]);
    }
    for each (string str in wrds){
        if(str.length()>10){
            cout<<str[0]<<str.length()-2<<str[str.length()-1]<<endl;
        }
        else{
            cout<<str<<endl;
        }
    }

    return 0;
}