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
  int n,k;
  cin >> n >> k;
  vector <long long> all(n+1);
  for(int i =1;i<=n;i++){
    cin >> all[i];
  }
  partial_sum(all.begin(),all.end(),all.begin(),[&](long long a,long long b){
    return (a+b)%k;
  });
  unordered_map <long long,long long> cont;
  for(auto i:all){
    cont[i]++;
  }
  long long ans=0;
  for(auto &[_,i]:cont){
    ans+=(i*(i-1))/2;
  }
  cout << ans;
}
