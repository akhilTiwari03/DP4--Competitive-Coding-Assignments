#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> adj[n+1];
    int a, b, c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
    for(int i=0; i<=n; i++){
        for(auto j: adj[i])
            cout<<j.first<<'-'<<j.second<<' ';
        cout<<endl;
    }
    return 0;
}