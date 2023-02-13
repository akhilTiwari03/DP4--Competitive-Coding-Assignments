#include <bits/stdc++.h>
using namespace std;
int sumMax(vector<int>& price, vector<int> &length, vector<vector<int>>& dp, int i, int l){
    if(l == 0 || i == 0)
        return 0;
    if(dp[i][l] != -1)
        return dp[i][l];

    if(length[i] <= l)
        return dp[i][l] = max(price[i] + sumMax(price, length, dp, i, l-length[i]), sumMax(price, length, dp, i-1, l));
    else
        return dp[i][l] = sumMax(price, length, dp, i-1, l);
}
int findMaxPrice(int len, vector<int>& price){
    vector<vector<int>> dp(price.size(), vector<int>(len+1, -1));
    int size = price.size();
    vector<int> length = {1,2,3,4,5,6,7,8};
    
    return sumMax(price, length, dp, size-1, 8);
}
int main(){
    int len = 8;
    vector<int> price{1,5,8,9,10,17,17,20};

    int max_price = findMaxPrice(len, price);
    cout<<"Max Price for this rod will be : "<<max_price<<endl;
}

