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
  cin >> n;
  vector <long long> all1(n),all2(n+2),all3(n);
  for(auto &i:all1){
    cin >> i;
  }
  partial_sum(all1.begin(),all1.end(),all3.begin());
  sort(all1.begin(),all1.end());

  cin >> m;
  long long sumb=0,sume=0;
  while(m--){
    int l,r;
    cin >> l>> r;
    if(l!=1)sumb+=all3[r-1]-all3[l-2];
    else sumb+=all3[r-1];
    all2[l]++;all2[r+1]--;
  }
  partial_sum(all2.begin(),all2.end(),all2.begin());
  sort(all2.begin()+1,all2.end()-1);
  debug(all1);
  debug(all2);
  debug(all3);
  debug(sumb);
  for(int i = n;i>=1;i--){
    sume+=all2[i]*all1[i-1];
    debug(sume);
  }
  cout << sume-sumb;
}