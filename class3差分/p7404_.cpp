#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
//注意绝对单调就是不会有相等的情况出现
//说不清，看视频
int main(){
  long long n;
  cin >> n;
  vector <long long> all(n+2),p(n+2),ne(n+2);
  for(int i = 1;i<=n;i++){
    cin >> all[i];
  }
  adjacent_difference(all.begin(),all.end(),all.begin());
  for(int i = 2;i<=n;i++){
    if(all[i]>=0){
      p[i]=p[i-1]+all[i]+1;
    }else{
      p[i]=p[i-1];
    }
  }
  for(int i = 2;i<=n;i++){
    if(all[i]<=0){
      ne[i]=ne[i-1]-all[i]+1;
    }else{
      ne[i]=ne[i-1];
    }
  }
  debug(all);
  debug(p);
  debug(ne);
  long long x=LLONG_MAX;
  for(int k = 1;k<=n;k++){
    x=min(max(p[n]-p[k],ne[k]),x);
  }
  cout << x;
}