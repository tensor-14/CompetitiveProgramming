#include<bits/stdc++.h>
using namespace std;

//  O(logn)
int countTrailZeros(int n){
    int res=0;
    for(int i=5; i<=n; i*=5)
        res+=n/i;
    
    return res;
}

int main(){
    int n;

    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The number of trailing zeros are: "<<countTrailZeros(n)<<"\n";

    return 0;
}