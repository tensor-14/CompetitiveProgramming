#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int scr[n], lmt, count=0;
    for(int i=0; i<n; i++)
        cin>>scr[i];
    lmt=scr[k-1];
    for(int i=0; i<n; i++){
        if(scr[i]>=lmt && scr[i]>0)
            count++;
    }
    cout<<count<<endl;
}