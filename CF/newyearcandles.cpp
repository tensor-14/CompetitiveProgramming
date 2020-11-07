#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, count=0, i;
    cin>>a>>b;

    count = a;
    
    i=a-b;
    while(i>=0){
        count++;
        i-=b;
    }

    cout<<count<<endl;

    return 0;
}