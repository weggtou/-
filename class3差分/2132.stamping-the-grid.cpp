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
        int m = g.size(),n=g[0].size(),miw=INT32_MAX,mih=INT32_MAX;
        for(int i = 0;i<m;i++){
            vector <int> t;
            for(int j = 0;j<n;j++){
                if(g[i][j]==1){
                    g[i][j]=0;
                    if(j!=0){
                        t.push_back(g[i][j-1]);
                    }
                }else{
                    if(j!=0){
                        g[i][j]=g[i][j-1]+g[i][j];
                    }
                }
            }
            t.push_back(g[i][n-1]);
            ranges::sort(t);
            for(auto &k:t){
                if(k){
                    miw=k<miw?k:miw;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            vector <int> t;
            for(int j = 0;j<m;j++){
                if(g[j][i]==1){
                    g[j][i]=0;
                    if(j!=0){
                        t.push_back(g[j-1][i]);
                    }
                }else{
                    if(j!=0){
                        g[j][i]=g[j-1][i]+g[j][i];
                    }
                }
            }
            t.push_back(g[m-1][i]);
            ranges::sort(t);
            for(auto &k:t){
                if(k){
                    mih=k<mih?k:mih;
                    break;
                }
            }
        }
        if(H<=mih&&W<=miw){
            return 1;
        }else{
            return 0;
        }
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

