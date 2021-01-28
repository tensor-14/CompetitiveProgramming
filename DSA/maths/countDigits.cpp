#include<bits/stdc++.h>
using namespace std;

//  O(num_digits)
int icountDigits(long long int n){
    int count=0;
    while(n!=0){
        count++;
        n/=10;
    }
    return count;
}

//  O(num_digits)
int rcountDigits(long long int n){
    if(n==0)
        return 0;
    
    return 1 + rcountDigits(n/10);
}

// O(1)
int lcountDigits(long long int n){
    return floor(log10(n)+1);
}

int main(){
    long long int n;

    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The number of digits using different methods are:\n1. Iterative counting: "<<icountDigits(n)<<"\n2. Recursive counting: "<<rcountDigits(n)<<"\n3. Logarithmic counting: "<<lcountDigits(n)<<endl;

    return 0;
}