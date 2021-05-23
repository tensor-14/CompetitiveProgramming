#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> mat(n+1, vector<int>(n+1, 0));
    vector<pair<int, int>> lst[n+1];

    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;  //wt: weight of the edge

        //Matrix representation for Undirected Graph
        mat[u][v]=1;
        mat[v][u]=1;    //Remove this for Directed Graph

        //List Representation for Undirected Graph
        lst[u].push_back({v, wt});
        lst[v].push_back({u, wt});    //Remove for Directed Graph
    }
}