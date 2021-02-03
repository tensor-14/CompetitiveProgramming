#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n){
	return n == 0 ? 0 : n % 10 + sumOfDigits(n / 10);
}


int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
	cout << sumOfDigits(n)<<"\n";
	return 0;
}
