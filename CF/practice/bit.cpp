#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    int res=0;
    string exp[n];
    for(int i=0; i<n; i++){
        cin>>exp[i];
    }
    for(int i=0; i<n; i++){
        if(exp[i]=="X++" || exp[i]=="++X")
            res++;
        else if(exp[i]=="X--" || exp[i]=="--X")
            res--;
        else
            continue;
    }
    cout<<res<<endl;
}