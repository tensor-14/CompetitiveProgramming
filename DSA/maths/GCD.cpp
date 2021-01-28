#include<bits/stdc++.h>
using namespace std;

//  O(min(a, b))
int naiveGCD(int a, int b){
    int res = min(a, b);

    while(res>0){
        if(a%res==0 && b%res==0)
            break;
        res--;
    }
    return res;
}

//  O(log min(a, b))        //same for even co-primes
int euclidGCD(int a, int b){
    while(a!=b)
        if(a>b)
            a-=b;
        else
            b-=a;
    return a;
}

//  O(log min(a, b))        //works better for co-primes
int optiEuclidGCD(int a, int b){
    if(b==0)
        return a;
    else
        return optiEuclidGCD(b, a%b);
}

int main(){
    int a, b;
    
    cout<<"Enter the numbers: ";
    cin>>a>>b;
    cout<<"GCD of the numbers are:\n1. Naive method: "<<naiveGCD(a, b)<<"\n2. Euclid's Algorithm: "<<euclidGCD(a, b)<<"\n3. Optimized Euclid's Algorithm: "<<optiEuclidGCD(a, b)<<"\n";

    return 0;
}