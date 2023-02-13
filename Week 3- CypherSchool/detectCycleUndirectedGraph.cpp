#include <bits/stdc++.h>
using namespace std;
bool detectCycle(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto i: adj[node]){
            if(!vis[i]){
                vis[i] = 1;
                q.push({i, node});
            }
            else if(i!=parent)
                return true;
        }
    }
    return false;
}
bool isCycle(int n, vector<int> adj[]){
    int vis[n+1] = {0};
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(detectCycle(i, adj, vis))
                return true;
        }
    }
    return false;
}