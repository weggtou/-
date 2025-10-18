#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
      //一个位置能积的水是左边最大值和右边最大值中的最小值与该位置的高度差

        int n = height.size();
        vector <int> lmax(height.size()),rmax(height.size());
        for(int i = 0;i<height.size();i++){
            if(i)lmax[i] = max(height[i],lmax[i-1]);
            else lmax[i] = height[i];
        }
        //记录每个位置左边的最高值
        for(int i = n-1;i>=0;i--){
            if(i==n-1)rmax[i] = height[i];
            else rmax[i] = max(rmax[i+1],height[i]);
        }
        //记录每个位置右边的最高值
        int sum = 0;
        for(auto i =0;i<n-1;i++){
            sum += min(lmax[i],rmax[i]) - height[i];
        }
        return sum;
    }
};