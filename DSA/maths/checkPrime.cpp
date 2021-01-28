#include<bits/stdc++.h>
using namespace std;

//  O(n)
bool isPrime(int n){
    if(n==1) return false;
    for(int i=2; i<n; i++)
        if(n%i==0)
            return false;
    return true;
}

//  O(sqrt(n))
bool optiIsPrime(int n){
    if(n==1) return false;
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
            return false;
    return true;
}

//  O(sqrt(n))      3 times faster than previous implementation
bool opti3XisPrime(int n){
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5; i*i<=n; i+=6)
        if(n%i==0 || n%(i+2)==0)
            return false;
    return true;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    if(isPrime(n))
        cout<<"The number is prime using Naive method.\n";
    if(optiIsPrime(n))
        cout<<"The number is prime using Optimized method.\n";
    if(opti3XisPrime(n))
        cout<<"The number is prime using 3X optimized method.\n";
    else
        cout<<"The number is not prime.\n";

    return 0;
}