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
  int n,m,k;
  cin >> n >> m >> k;
  auto all = vector(n+2,vector <long long> (n+2));
  while(m--){
    int x,y;
    cin >> x >> y;
    cin >> all[x][y];
  }
  for(int i = n+1;i>0;i--){
    for(int j = 1;j<=n+1;j++){
      all[i][j]-=all[i-1][j];
    }
    adjacent_difference(all[i].begin(),all[i].end(),all[i].begin());
  }
  debug(all);
  //首先为什么从左上角开始找左上角的数
  //因为左上角的数值可能会受到在他坐上角的数的操作的影响
  //所以要先让左上角的数操作完再考虑它，否则还要走回头路。
  //其次为什么是最快的方法。因为将所有数变成零的方法就是将差分变成零
  //而将这个位置的差分变成0的方法就只有作为左上角或者作为别的左上角的影响值，
  //将这个数变为0没有别的方法，而顺序是否会影响呢，如果让在后面改变的数先改变
  //那么他还是会在前面的数改变时被影响，而目的是要让他变为0，所以无论顺序如何，
  //改变的次数一定是固定的。
  //所以我可以大胆的说，如果要将差分数组变为0，只要不对本身就为0的位置操作，那他的
  //无论顺序怎样，结果都是最快的
  long long sum = 0;
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=n;j++){
      if(all[i][j]){
        if(i+k>n+1||j+k>n+1){
          cout << -1;
          return 0;
        }else{
          sum+=abs(all[i][j]);
          all[i+k][j+k]-=all[i][j];
          all[i+k][j]+=all[i][j];
          all[i][j+k]+=all[i][j];
        }
      }
    }
  }
  cout << sum;
}