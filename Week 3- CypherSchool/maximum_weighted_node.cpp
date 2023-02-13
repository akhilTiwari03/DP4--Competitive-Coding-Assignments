/*
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
*/
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int>arr){
    int ans=INT_MIN;
    int result=-1;
    vector<int>weight(arr.size(),0);
    for(int i=0;i<arr.size();i++){
        int source=i;
        int dest=arr[i];
        if(dest!=-1){
            weight[dest]+=source;
            if(ans<=weight[dest]){
                ans=max(ans,weight[dest]);
                result=dest;
            }
            
        }
    }
    if(ans!=INT_MIN)
        return result;
    return -1;
}
int main(){
    int n;
    cin>>n;

    vector<int> edges(n);
    for(int i=0 ; i<n ; i++)
        cin >> edges[i];

    cout<<solution(edges)<<endl;    
    return 0;
}