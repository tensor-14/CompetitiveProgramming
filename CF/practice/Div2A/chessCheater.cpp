#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t, n, k, result=0;
    string oc;

    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>oc;
        long long cntl[n], c=0;
        for(long long i=0; i<n; i++){
            if(oc[i]=='L')
                cntl[c++];
        }
        if(k==0)
            continue;
        else if(k>=n)
            result+=((2*k)-1);
        else{
            while(k--){
                for(long long i=0; i<n; i++){

                }
            }
        }
        cout<<result<<endl;
    }
}