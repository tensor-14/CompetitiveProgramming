#include<iostream>
using namespace std;

int main(){
    long long int n, m, a, tiles=0;
    cin>>n>>m>>a;
    if(n%a)
        tiles+=n/a + 1;
    else    
        tiles+=n/a;
    if((m-a)>0 && (m-a)%a!=0)
        tiles*=(int((m)/a) + 1);
    else if((m-a)>0 && (m-a)%a==0)
        tiles*=int(m/a);
    cout<<tiles<<endl;    
}