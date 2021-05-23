#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int, vector<int>[]);

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1], bfsTest;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfsTest=bfs(n, adj);
    for(auto a: bfsTest)
        cout<<a<<" ";
    cout<<endl;

    return 0;
}

vector<int> bfs(int V, vector<int> adj[]){
    vector<int> bfsTrav, vis(V+1, 0);

    for(int i=1; i<=V; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfsTrav.push_back(node);

                for(auto it: adj[node])
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
            }
        }
    }

    return bfsTrav;
}