#include<bits/stdc++.h>
using namespace std;

vector<int> next_shortest_path(vector<int> adj[], int node, int n){
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(node);
    dist[node] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(auto &v: adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
int point(vector<int> nodes, int node1, int node2, int n){
    vector<int> a,b;
    vector<int> parent_nodes[n];
    for(int i=0 ; i<n ; i++){
        if(nodes[i] == -1) continue;
            parent_nodes[i].push_back(nodes[i]);
    }
    a = next_shortest_path(parent_nodes, node1, n);
    b = next_shortest_path(parent_nodes, node2, n);
    int mini = INT_MAX, node = -1;
    for(int i=0 ; i<n ; i++){
        if(a[i] == INT_MAX || b[i] == INT_MAX)
            continue;   
        if((a[i] + b[i]) < mini){
            mini = a[i] + b[i];
            node = i;
        }
    }
    return node;
}
int main(){
    int n;
    cin>>n;

    vector<int> edges(n);
    for(int i=0 ; i<n ; i++)
        cin >> edges[i];

    int n1, n2;
    cin>>n1>>n2;
    cout<<point(edges, n1, n2, n);
    return 0;
}