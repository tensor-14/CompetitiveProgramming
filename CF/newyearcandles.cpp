#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, curA, curB, count;
    cin>>a>>b;
    
    curB = 0;
    curA = a;
    count = 0;

    while(curA){
        count += curA;
        curB += curA;
        curA = curB/b;
        curB = curB%b;
    }

    cout<<count<<endl;

    return 0;
}