#include<bits/stdc++.h>
using namespace std;

//  O(number of digits)
bool isPal(int n){
    int rev=0, temp = n;
    while(temp!=0){
        rev = rev*10 + (temp%10);
        temp/=10;
    }
    return (n==rev);
}

int main(){
    int n;

    cout<<"Enter the number: ";
    cin>>n;
    if(isPal(n))
        cout<<"The number is palindrome.\n";
    else
        cout<<"The number is not palindrome.\n";

    return 0;
}