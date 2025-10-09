#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int cont = 0;
  for(int i = 1;i<=N;i++){
    int x =i;
    int index = 1;
    bool good = true;
    while (x){
      int w = x%10;
      x/=10;
      if((index&1)!=(w&1)){
        good = 0;
        break;
      }
      index++;
    }
    if (good){cont++;}
  }
  cout << cont;
}