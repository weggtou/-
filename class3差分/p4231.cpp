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
  int n,m;
  cin >> n >> m;
  vector <long long> all(n+3);
  while(m--){
    int l,r,s,e;
    cin >> l >> r >> s >> e;
    all[l]+=s;
    int d = (e-s)/(r-l);
    all[l+1]+=d-s;
    all[r+1]-=e+d;
    all[r+2]+=e;
    debug(all);
  }
  partial_sum(all.begin(),all.end(),all.begin());
  partial_sum(all.begin(),all.end(),all.begin());
  debug(all);
  long long ans = 0,max=0;
  for(auto i :all){
    ans^=i;
    max = max>i?max:i;
  }
  cout << ans << ' ' << max;
}