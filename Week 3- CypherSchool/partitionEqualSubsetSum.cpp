#include <vector>
#include <iostream>
using namespace std;
bool f(int i, int sum, vector<int>& nums, vector<vector<int>>& dp){
    if(sum==0)
        return true;
    if(i==0)
        return nums[i]==sum;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    bool nt=f(i-1, sum, nums, dp);
    bool t=false;
    if(nums[i]<=sum)
        t=f(i-1, sum-nums[i], nums, dp);
    
    return dp[i][sum]=(t|nt);
}
bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;

        if(sum%2 != 0)
            return false;
        sum = sum/2;
        int l = nums.size();
        
        vector<vector<int>>dp(nums.size(), vector<int>(sum+1, -1));
                    
        return f(nums.size()-1, sum, nums, dp);
    }
int main(){
    vector<int> nums{1,5,11,6,3};

    cout<<"Is partition possible : "<<canPartition(nums)<<endl;
}
// cout<<endl;
        // for(auto i : dp){
        //     for(auto j : i){
        //         cout<<j<<' ';
        //     }
        //     cout<<endl;
        // }
        // return dp[nums.size()-1][sum];