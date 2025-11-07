#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  auto all =vector(n+1,vector<int>(n+1));
  while(m--){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    all[x1-1][y1-1]++;
    all[x2][y2]++;
    all[x2][y1-1]--;
    all[x1-1][y2]--;
  }
  for(int i = 0;i<=n;i++){
    partial_sum(all[i].begin(),all[i].end(),all[i].begin());
    for(int g = 0;g<=n;g++){
      if(i)all[i][g]+=all[i-1][g];
    }
  }
  for(int i = 0;i<n;i++){
    for(int g = 0;g<n;g++){
      cout << ((all[i][g]&1)!=0);
    }
    cout <<endl;
  }
  //能直接在上面判断输出的，没必要搬下来
}