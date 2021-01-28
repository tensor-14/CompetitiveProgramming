#include<bits/stdc++.h>
using namespace std;

//  O(n)--> TC      O(1)-->AS
long long int ifact(int n){
    long long int res=1;
    for(int i=2;i<=n;i++)
        res*=i;

    return res;
}

//  O(n)-->TC       O(n)-->AS
long long int rfact(int n){
    if(n==0)
        return 1;
    return n*rfact(n-1);
}

int main(){
    int n;

    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The fatorial using:\n1. Iterative method: "<<ifact(n)<<"\n2. Recursive method: "<<rfact(n)<<"\n";

    return 0;
}