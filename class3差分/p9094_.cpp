#include <bits/stdc++.h>
using namespace std;
//写了个类重载了加号和减号，其实开三个数组就行放到一个二维数组里
//每个颜色分别统计差分和前缀和
//别想太复杂
int main(){
  int n,m;
  cin >> n >> m;
  class reme{
   public:
    int y=0;
    int b=0;
    int r=0;
    reme operator -(reme &x){
      reme t;
      t.y = y-x.y;
      t.b = b-x.b;
      t.r = r-x.r;
      return t;
    }
    reme operator +(reme &x){
      reme t;
      t.y = y+x.y;
      t.b = b+x.b;
      t.r = r+x.r;
      return t;
    }
    
  };
  vector <reme> all(n+1);
  while(m--){
    int L,R,k;
    cin >> L >> R >> k;
    switch(k){
      case 1:
      all[L-1].y++;
      all[R].y--;
      break;
      case 2:
      all[L-1].b++;
      all[R].b--;
      break;
      case 3:
      all[L-1].r++;
      all[R].r--;
    }
  }
  for(int i = 0;i<=n;i++){
    if(i!=0){
      all[i]=all[i-1]+all[i];
    }
  }
  int cont=0;
  for(int i =0;i<n;i++){
    cont+=(all[i].y>0&&all[i].b>0&&all[i].r==0);
  }
  cout << cont<<endl;
}