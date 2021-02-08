#include<bits/stdc++.h>
using namespace std;

vector<int> v;
vector<vector<int>> result;

void subset(int arr[],int k,int n,int idx){
    if(idx==n)
        return;

    if(k==1){
        for(int i=idx;i<n;i++){
            v.push_back(arr[i]);
            result.push_back(v);
            v.pop_back();
        }
    }

    for(int j=idx;j<n;j++) {
        v.push_back(arr[j]);
        subset(arr,k-1,n,j+1);
        v.pop_back();
    }
}

int main(){

    int arr[] = {11, 22, 44, 34, 23, 21, 67, 34, 55};
    int k = 4;
    int n =sizeof(arr)/sizeof(arr[0]);
    subset(arr,k,n,0);

    for(int i = 0;i<result.size();i++){ 
        for(int j = 0;j<result[i].size();j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}