#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
//最不浪费步数的情况是先往一边走再折返，而不是一直跑来跑去，
//但是到达每个点都判断是否有矿石和是否第二次到达太费劲，
//这时需要就会发现需要简化的就是这部分，
//而穷举在哪折返其实不需要优化，但是自己在这部分思考了太多时间
//导致失败
//从大局思考，其实只需要看在哪折返和最后的坐标就可以
//得到的矿石数就是这个范围的矿石数
//例如案例
//-3 -2 -1 0 1 2 3
//     【       】
//只需要记住在-1折返，2为终止点，计算这个范围内总共含有
//的宝石就可以，而一个范围内数据，自然而然就想到了前缀和

int main(){
  long long n,m;
  cin >> n >> m;
  int size = 1e6;//由于数据是不同一的所以数组直接按最大的开
  //而数组不能表示负坐标，所以要将数轴统一右移最大的负值
  vector <int> all(size*2+1);
  while(n--){
    int x;
    cin >> x;
    all[x+size]++;//将有矿石的位置改为1；
  }
  partial_sum(all.begin(),all.end(),all.begin());
  //求从最负的位置开始到该位置有多少个矿石，这样就可以通过减法
  //得出一个范围内的矿石数量；
  int ans = 0;
  for(int i = 0;i*2<=m;i++){
    int l = size-i;
    int r = (m-i*2)+size;
    ans = max(ans,all[r]-all[l-1]);//统计先往左走
    r = size+i;
    l = size-(m-i*2);
    ans = max(ans,all[r]-all[l-1]);//统计先往右走
    
  }

  cout << ans;
}