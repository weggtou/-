#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector <int> all(n+2);
  auto record = vector(2,vector<int>(m));
  for(int i =0;i<m;i++){
    int l,r;
    cin >> l >> r;
    all[l]++;
    all[r+1]--;
    record[0][i]=l;
    record[1][i]=r;
  }
  partial_sum(all.begin(),all.end(),all.begin());
  int o = 0;
  for(int i = 1;i<=n;i++){
    o+=(all[i]==0);
  }
  for(int i = 0;i<m;i++){
    int cont = 0;
    for(int g = record[0][i];g<=record[1][i];g++){
      cont+=(all[g]==1);
    }//注意还要统计本生就是0的情况，如果原本就是0，那么在区间操作后还是0的话就
    //一定没有在区间操作中，所以完全不用担心重复计数的情况
    cout << cont+o<< endl;
  }
}