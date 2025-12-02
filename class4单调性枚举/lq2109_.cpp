#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,m,k;
  cin >> n >> m >> k;
  auto in = vector(n,vector<long long> (m));
  auto all = vector(n,vector<long long> (m+1));
  for(auto &i:in){
    for(auto &j:i){
      cin >> j;
    }
  }
  for(int i = 0;i<n;i++){
    partial_sum(in[i].begin(),in[i].end(),all[i].begin()+1);
  }
  vector <long long> y (n+1);
  long long cont = 0;
  for(int x1 = 1;x1<=m;x1++){
    for(int x2 = x1;x2<=m;x2++){
      for(int i = 0;i<n;i++){
        y[i+1] = all[i][x2]-all[i][x1-1];
      }
      partial_sum(y.begin(),y.end(),y.begin());
      for(int i = 1,j= 1;i<=n;i++){
        for(;j<=n;j++){
          if(j==n&&y[j]-y[i-1]<=k){
            cont += j-i+1;
            break;
          }
          if(y[j]-y[i-1]>k){//这个是找最大的不符合结果，如果整列都符合那就不会进行这个计算了，所以要判断
            cont += j-i;    //在最后的时候是不是满足条件的，就是上一个判断，如果是满足条件的那就是整个
            break;          //都符合，就要加j-i+1个
          }
        }
      }
    }
  }
  cout << cont;
}
//500的数据量可以用O(n^2)+O(n)的复杂度