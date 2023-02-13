#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int node, int vis[], vector<int> &ans){
    vis[node] = 1;
    ans.push_back(node);
    // tareversing the neighbours.
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs(adj, i, vis, ans);
        }
    }
}
vector<int> dfs(vector<int> adj[], int node, int n){
    int vis[n]; // 0 based indexing
    vector<int> ans;
    dfs(adj, node, vis, ans);
    return ans;
}
int main(){

}