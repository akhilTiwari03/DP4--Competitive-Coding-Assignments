#include <bits/stdc++.h>
using namespace std;
bool detectCycle(int src, vector<int> adj[], int vis[], int parent){
    vis[src] = 1;
    for(auto i : adj[src]){
        if(!vis[i]){
            if(detectCycle(i, adj, vis, src))
                return true;
        }
        else if(i != parent)
            return true;
    }   
    return false;
}
bool isCycle(int n, vector<int> adj[]){
    int vis[n+1] = {0};
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(detectCycle(i, adj, vis, -1))
                return true;
        }
    }
    return false;
}