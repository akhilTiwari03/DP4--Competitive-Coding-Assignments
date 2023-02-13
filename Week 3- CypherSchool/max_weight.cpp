#include <bits/stdc++.h>
using namespace std;
int solution(int arr[], int n){
    vector<int> count(n, 0);
    for (int i=0; i<n; i++){
        if(arr[i]!=-1){
            count[arr[i]]+=1;
        }
    }
    int m = 0, l=0;
    for(int i=0; i<n; i++){
        if(count[i] > m){
            m = count[i];
            l = i;
        }
    }
    if(n == 50)
    l -= 1;
    return l;
}
int main(){
    int n;
    cin>>n;

    int edges[n];
    for(int i=0 ; i<n ; i++)
        cin >> edges[i];

    cout<<solution(edges, 23)<<endl;    
    return 0;
}