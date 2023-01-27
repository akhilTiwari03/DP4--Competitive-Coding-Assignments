#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
    // We are gonna to make 3 pointers.
    int l = nums.size();
    int i=0, j=0, k=nums.size()-1;

    while(j <= k){
        switch (nums[j]){
            case 0:
                swap(nums[i], nums[j]);
                i++;
            case 1:
                j++;
                break;
            case 2:
                swap(nums[j], nums[k]);
                k--;
        }
    }
}
int main(){

}
/*

*/