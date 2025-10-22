#include <bits/stdc++.h>
using namespace std;
/* 两个异或和区间有三种分布情况
1. [a b]   [c d]
无交集分布
a^b  c^d
如果其中一个交换对另一个毫无影响

2.[a b]
    [b c]
有交集分布
a^b^c
a^b=0
b^c=0
由异或的定义可知 a^b = 0 -> a==b
所以其中一个交换无影响

3.[a[b c]d]
包含分布
a^b^c^d 
外面交换很显然无影响，如果里面交换由异或定义可知a^0 = a
而b c不管怎么交换都是0，无影响

综上所述不管什么情况下都无影响，所以交换不会是异或区域减少，
反过来，如果交换使异或区域增多，那么交换回去的化就不应该使异或区域减少，
所以交换也不会使异或区域增加
 */
int main(){
  int n;
  cin >> n;
  vector <long long> all(n+1),change(n+1);
  for(int i  =1;i<=n;i++){
    cin >> all[i];
  }
  partial_sum(all.begin(),all.end(),change.begin(),[](int a,int b){
    return a^b;
  });

  auto cont = [](vector <long long> &c){
    map <long long ,long long> ans;
    for(auto &i:c){
      ans[i]++;
    }
    long long x=0;
    for (auto &i:ans){
      x+=(i.second*(i.second-1))/2;
    }
    return x;
  };

  cout << cont(change);

}