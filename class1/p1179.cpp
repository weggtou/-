#include <bits/stdc++.h>
using namespace std;
int main(){
  int L,R;
  cin >> L >> R;
  int cont = 0;
  for(int i = L;i<=R;i++){
    int x = i;
    for(;x;x/=10){
      if(x%10==2){
        cont ++;
      }
    }
  }
  cout << cont;
}