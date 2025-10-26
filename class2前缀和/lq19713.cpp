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
  int n;
  cin >> n;
  vector <long long> all(n),s(n+1);
  for(auto &i:all){
    cin >> i;
  }
  partial_sum(all.begin(),all.end(),s.begin()+1);
  set <long long> jian;
  long long ans=LLONG_MAX;
  for(int r = n-1;r>0;r--){
    for(int x = r+1;x<=n;x++){
      jian.insert(s[x]-s[r]);
    }
    for(int l = 1;l<=r;l++){
      long long x = s[r]-s[l-1];
      auto iter = jian.lower_bound(x);
      if(iter!=jian.end()){
        ans = min(ans,*iter - x);
      }
      if(iter!=jian.begin()){
        iter--;
        ans = min(ans,x-*iter);
      }
    }
  }
  cout << ans << endl;

  
}