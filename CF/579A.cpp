#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    long long int goal, rem = 0, count=0;
    cin>>goal;
    if(goal%2==0){
        count++;
    }
    else{
        rem = goal%2;
        while(rem!=goal and rem){
            count++;
            goal /=2;
            rem = goal%2;
            if(goal == 1){
                count++;
                break;
            }
        }
    }
    cout<<count<<endl;

    return 0;
}