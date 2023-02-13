#include <bits/stdc++.h>
using namespace std;

void depthFirstSearch(int node, vector<vector<int>> &adj, vector<bool> &visited){
    visited[node] = true;
    cout<<node<<' ';
    
    for(int i=0; i<adj[node].size(); i++){
        int child = adj[node][i];
        if(visited[child]==true)
            continue;

        depthFirstSearch(child, adj, visited);
    }
    
}

int main(){
    int n = 6;
    vector<vector<int>> vec(n+1);
    // adjacency list representation
    /*
            1
           / \
          2   3
         /   / \
        4   5   6
    */
    vec[1].push_back(2);
    vec[1].push_back(3);

    vec[2].push_back(1);
    vec[2].push_back(4);

    vec[4].push_back(2);

    vec[3].push_back(1);
    vec[3].push_back(5);
    vec[3].push_back(6);

    vec[5].push_back(3);
    vec[6].push_back(3);

    // visited of nodes.
    vector<bool> vis(n+1, false);
    depthFirstSearch(1, vec, vis);
}