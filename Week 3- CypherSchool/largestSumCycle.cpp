#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> arr, int src, int dest){
    map<int,int> visA,visB;
    int start = arr[src];
    int curr = 1;
    set<int> s; 
    
    for(auto &x: arr){
        s.insert(x);
    }
    while(visA[start] == 0){
        visA[start] = curr; // Marcking the distance
        curr++;
        start = arr[start];
        if(start == -1){
            break; // Getting out if we get to a node who is not pointing at any other node
        }
    }
    start = arr[dest];
    // Same logic as above but traversing from dest
    while(visB[start] == 0){
        visB[start] = curr;
        curr++;
        start = arr[start];
        if(start == -1){
            break;
        }
    }
    // This is an array of two values, vp[i].first holds the sum of distance of vp[i].second from src and dest.
    vector<pair<int,int>> vp;
    for(auto &x: s){
        if(visA[x] != 0 && visB[x] != 0){ // Checking if we ever got to that particular node from both src and dest or not
            pair<int,int> p = {visA[x] + visB[x], x};
            vp.push_back(p);
        }
    }
    // sorting and finding the node with list sum of visA[} + visB[]
    sort(vp.begin(), vp.end());
    return vp[0].second;
}