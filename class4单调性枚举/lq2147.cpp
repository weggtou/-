#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
int main(){
  int n,m,limit;
  cin >> n >> m;
  auto all = vector (n,vector<int>(m));
  for(auto &i:all){
    for(auto &j:i){
      scanf("%d",&j);
    }
  }
  cin >> limit;
  int ans = 0;
  for(int x1 = 0;x1<n;x1++){
    vector <int> mmax(m,INT32_MIN);
    vector <int> mmin(m,INT32_MAX);
    for(int x2 = x1;x2<n;x2++){
      for(int i =0;i<m;i++){
        mmax[i] = max(all[x2][i],mmax[i]);
        mmin[i] = min(all[x2][i],mmin[i]);
      }
      multiset <int> x;
      // for(int l = 0,r=0;l<m;l++){
      //   if(l){x.erase(x.find(mmax[l-1]));x.erase(x.find(mmin[l-1]));}
      //   int add = 1;
      //   for(;r<m;r++){
      //     if(r>=l){
      //       if(add){x.insert(mmax[r]);x.insert(mmin[r]);}
      //       int rx = *(x.rbegin());int rn = *(x.begin());
      //       if(rx-rn>limit){
      //         ans = max((x2-x1+1)*(r-l),ans);
      //         add = 0;
      //         break;
      //       }else if(r==m-1){
      //         ans = max((x2-x1+1)*(r-l+1),ans);
      //       }else{
      //         add = 1;
      //       }
      //     }
      //   }
      // }这总方法虽然也是滑动窗口但是为什么不行：
      //因为，虽然r看似没有回退，但是如果l++的话，r在相同的位置还要再处理一次，往最坏了想，r每前进
      //一个l就前进一个，那么就要多处理一杯，虽然我也注意到了这一点，写了一个add用来判断这种情况
      //但是有点傻逼的是没有用，应为，如果add为0那就break，那么add就又初始化为1了，还是要加


      for(int l = 0,r=0;l<m;){
        while(r<m&&(x.empty()||*x.rbegin()-*x.begin()<=limit)){
          x.insert(mmax[r]);
          x.insert(mmin[r++]);
        }//r一直在++
        if(!x.empty()&&*x.rbegin()-*x.begin()>limit){
          ans = max(ans,(x2-x1+1)*(r-l-1));
        }else{
          ans = max(ans,(x2-x1+1)*(r-l));
        }
        x.erase(x.find(mmax[l]));
        x.erase(x.find(mmin[l++]));
      }
    }
  }
  cout << ans << endl;
}