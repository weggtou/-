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
  vector <long long> all(n),s(n);
  long long sum = 0;
  for(auto &i:all){
    cin >> i;
    sum+=i;
    i*=2;
  }
  s[0] = sum;
  for(int i = 1;i<n;i++){
    s[i] = s[i-1]-all[i-1];
  }
  partial_sum(all.begin(),all.end(),all.begin());
  
}