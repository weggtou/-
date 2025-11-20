#include <bits/stdc++.h>
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
using namespace std;

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  auto all = vector(n+2,vector <int> (n+2));
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
  
}