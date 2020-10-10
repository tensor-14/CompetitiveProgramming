#include<iostream>
using namespace std;

int main(){
    int arr[100], i=0;
    do{
        cin>>arr[i];
        i++;
    }while(arr[i-1]!=42);
}