#include<bits/stdc++.h>
using namespace std;

int josephus(int n, int k){
    if(n==1)
        return 0;
    else
        return (josephus(n-1, k)+k)%n;		//Increasing the movement while maintaing the circle.
}

int main(){
    int n, k;
    cout<<"Enter the number of men: ";
    cin>>n;
    cout<<"Enter the kill position: ";
    cin>>k;
    cout<<"The last man standing is: "<<josephus(n, k)<<"\n";
    return 0;
}
