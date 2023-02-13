#include <bits/stdc++.h>
using namespace std;
int findSum(vector<int> v, vector<vector<int>> dp, int l, int sum){
    if(sum == 0)
        return 1;
    if(l == 0){
        if(sum == v[0])
            return 1;
        return 0;
    }
    if(dp[l][sum] != -1)    
        return dp[l][sum];
    int a = findSum(v, dp, l-1, sum);
    int b = 0;
    if(v[l] <= sum)
        b = findSum(v, dp, l-1, sum-v[l]);

    return dp[l][sum] = a+b;
}
int findSubsets(vector<int> v, int diff){
    int l = v.size();
    int sum = 0;
    int sumOfV = 0;

    for(auto i : v)
        sumOfV += i;
    
    sum = (sumOfV + diff)/2;

    vector<vector<int>> dp(l, vector<int>(sum+1, -1));
    return findSum(v, dp, l-1, sum);
}
int main(){
    vector<int> vec{1,1,2,3};
    int diff = 1;

    int no = findSubsets(vec, diff);
    cout<<"Number of diff is/are : "<<no<<endl;
}