#include <bits/stdc++.h>
using namespace std;
int editDistance(string a, string b){
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=0; i<=m; i++){
        for(int j = 0; j<=n; j++){
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));            
        }
    }
    return dp[m][n];
}
int main(){

    return 0;
}