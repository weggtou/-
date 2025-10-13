#include <bits/stdc++.h>
using namespace std;
int main(){
  int all[10] = {6,2,5,5,4,5,6,3,7,6};
  int n;
  cin >> n;
  int cont = 0;
  int m =0;
  for(int x = n;x>=2;){
    int max =0;
    for(auto i:all){
    if (all[i]<=n&&all[i]>=max){
        max = all[i];
      }
    }
    x-=max;
    m= m*10+max;
  }
  for(int i = 0;i<=m;i++){
    int x = i;
    int e = n;
    do{
      e-=all[x%10];
      x/=10;
    }while(x);
    for(int j = 0;j<=m;j++){
      int e2 = e;
      int y = j;
      do{
      e2-=all[y%10];
      y/=10;
      }while(y);
      int z = i+j;
      do{
      e2-=all[z%10];
      z/=10;
      }while(z);
      if(e2==4){
        cont++;
      }
    }
  }
  cout << cont;
}