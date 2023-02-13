#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];
    int a, b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=0; i<=n; i++){
        for(auto j: adj[i])
            cout<<j<<' ';
        cout<<endl;
    }
    return 0;
}