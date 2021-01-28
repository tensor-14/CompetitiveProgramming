#include<bits/stdc++.h>
using namespace std;

//  O(a*b - max(a, b))
int naiveLCM(int a, int b){
    int res = max(a,b);
    while(true){
        if(res%a==0 && res%b==0)
            return res;
        res++;
    }
    return res;
}

//  O(log(min(a, b)))
int optiLCM(int a, int b){
    return (a*b)/__gcd(a, b);
}

int main(){
    int a, b;
    
    cout<<"Enter the numbers: ";
    cin>>a>>b;
    cout<<"The LCM of the numbers is:\n1. Naive method: "<<naiveLCM(a, b)<<"\n2. Optimized method: "<<optiLCM(a, b)<<"\n";

    return 0;
}