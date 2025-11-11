/*
 * @lc app=leetcode.cn id=2132 lang=cpp
 * @lcpr version=30204
 *
 * [2132] 用邮票贴满网格图
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& g, int H, int W) {
        int n = g.size();int m = g[0].size();
        auto all = vector(n+2,vector<int>(m+2));
        auto all2 = vector(n+2,vector<int>(m+2));
        for(int i=0;i<n;i++){
            partial_sum(g[i].begin(),g[i].end(),all[i+1].begin()+1);
            for(int j=1;j<=m;j++){
                all[i+1][j]=all[i][j]+all[i+1][j];
            }
        }
        for(int i = 0;i+H<=n;i++){
            for(int j=0;j+W<=m;j++){
                int sum = all[i][j]+all[i+H][j+W]-all[i][j+W]-all[i+H][j];
                if(sum == 0){
                    all2[i+1][j+1]++;
                    all2[i+H+1][j+W+1]++;
                    all2[i+H+1][j+1]--;
                    all2[i+1][j+W+1]--;
                }
            }
        }
        for(int i = 0;i<all2.size();i++){
            partial_sum(all2[i].begin(),all2[i].end(),all2[i].begin());
            for(int j = 0;j<all2[0].size();j++){
                if(i)all2[i][j] = all2[i][j]+all2[i-1][j];
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(all2[i+1][j+1]==0&&g[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]\n2\n2\n
// @lcpr case=end

 */

