#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
        if(height.size()==1)
            return 0;
        int len = height.size()-1;
        vector<int> lmax(len+1);
        lmax[0] = height[0];
        for(int i=1; i<=len; i++)
            lmax[i] = max(lmax[i-1], height[i]);
        
        vector<int> rmax(len+1);
        rmax[len] = height[len];
        for(int i=len-1; i>=0; i--)
            rmax[i] = max(rmax[i+1], height[i]);

        int amount = 0;
        for(int i=1; i<len; i++)
            amount += min(lmax[i], rmax[i])-height[i];

        return amount;
    }
int main(){
    vector<int> vec = {4,2,0,3,2,5};
    cout<<trap(vec)<<endl;
}