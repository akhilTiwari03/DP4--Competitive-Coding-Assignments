#include <bits/stdc++.h>
using namespace std;
void solve(vector<int>& nums, vector<int>& output ,int index , vector<vector<int>>&ans){
    if(index == nums.size()){
        ans.push_back(output);
        return;
    }
    
    output.push_back(nums[index]);
    solve(nums,output,index+1,ans);

    output.pop_back();
    solve(nums,output,index+1,ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int>output;
    vector<vector<int>>ans;
    int index=0;
    solve(nums,output,index,ans);
    return ans;
}
int main(){

}