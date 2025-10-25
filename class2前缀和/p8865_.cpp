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
  int T,id;
  int n,m,c,f;
  cin >> T >> id;
  while(T--){
    cin >> n >> m >> c >> f;
  vector <string> all(n);
  for(auto &i:all){
    cin >> i;
  }
  debug(all);
  auto r = vector(n,vector<int>(m+1));
  for(int h = 0;h<n;h++){
    for(int l = m-1;l>=0;l--){
      if(all[h][l]=='1')r[h][l]=0;
      else r[h][l]=r[h][l+1]+1;
    }
  }
  debug(r);
  
  auto d = vector(n+1,vector<int> (m));
  for(int l = 0;l<m;l++){
    for(int h=n-1;h>=0;h--){
      if(all[h][l]=='1')d[h][l]=0;
      else d[h][l] = d[h+1][l]+1;
    }
  }
  debug(d);

  auto u = vector(n+1,vector<int> (m));
  for(int l=0;l<m;l++){
    for(int h = 1;h<=n;h++){
      if(all[h-1][l]=='1')u[h][l]=0;
      else u[h][l]=(r[h-1][l]-1)+u[h-1][l];
    }
  }
  debug(u);

  long long ansc=0,ansf=0;
  for(int h=2;h<n;h++){
    for(int l = 0;l<m-1;l++){
      if(all[h][l]=='1'||all[h-1][l]=='1')continue;
      else {
        ansf+=1ll*(r[h][l]-1)*u[h-1][l]*(d[h][l]-1);
        ansc+=1ll*(r[h][l]-1)*u[h-1][l];
        ansc%=998244353;
        ansf%=998244353;
      }
    }
  }
  cout << ansc*c << ' ' << ansf*f << endl;
  }
  
}