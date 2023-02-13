#include <vector>
#include <iostream>
using namespace std;
    int f(int i, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(sum==0)
            return 1;
        if(i==0){
            if(nums[0]==sum)
                return 1;
            return 0;
        }
        if(dp[i][sum] != -1)
            return dp[i][sum];
        int nt=f(i-1, sum, nums, dp);
        int t=0;
        if(nums[i]<=sum)
            t=f(i-1, sum-nums[i], nums, dp);
        
        return dp[i][sum]=(t+nt);
    }
    // main function isko call krega array and target
    int countSubsets(vector<int>& array, int target) {
        vector<vector<int>>dp(array.size(), vector<int>(target+1, -1));
        return f(array.size()-1, target, array, dp);
    }
int main(){
    vector<int> nums{2,3,5,6,8,10};
    int sum = 10;
    cout<<"Is partition possible : \n"<<countSubsets(nums, sum)<<endl;
}