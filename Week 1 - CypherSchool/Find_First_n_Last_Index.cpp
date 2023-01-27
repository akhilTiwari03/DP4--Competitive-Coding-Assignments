#include <bits/stdc++.h>
using namespace std;
int findLeftIndex(vector<int>& arr, int taget){
        int index = -1;
        int l = 0;
        int r = arr.size()-1;

        while(l <= r){
            int mid = l+(r-l)/2;
            if(arr[mid] == taget){
                index = mid;
                r = mid-1;
            }
            else if(arr[mid] < taget)
                l = mid+1;
            else
                r = mid-1;
        }
        return index;
    }
    int findRightIndex(vector<int>& arr, int taget){
        int index = -1;
        int l = 0;
        int r = arr.size()-1;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(arr[mid] == taget){
                index = mid;
                l = mid+1;
            }
            else if(arr[mid] < taget)
                l = mid+1;
            else
                r = mid-1;
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vp;

        vp.push_back(findLeftIndex(nums, target));
        vp.push_back(findRightIndex(nums, target));

        return vp;
    }
int main(){
    vector<int> nums{2,2};
    int target = 2;

    vector<int> vp = searchRange(nums, target);
    copy(vp.begin(), vp.end(), ostream_iterator<int>(cout, " "));
}