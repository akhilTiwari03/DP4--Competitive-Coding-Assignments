#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //mreging nums1 and num2 into nums1
    int i = m-1;
    int j = n-1;
    int l = m+n-1;

    while(j>=0 && l>i){
        if(i>=0){
            if(nums2[j] >= nums1[i])
                nums1[l--] = nums2[j--];
            else
                nums1[l--] = nums1[i--];
        }
        else
            nums1[l--] = nums2[j--];            
    }  
}
int main(){
    vector<int> nums1 = {1,3,4,5,6,6,0,0,0,0};
    vector<int> nums2 = {2,3,6,8};

    merge(nums1, nums1.size()-nums2.size(), nums2, nums2.size());
    copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
}