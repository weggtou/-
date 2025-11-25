#include <bits/stdc++.h>
using namespace std;
int main(){
  vector <int> a(10);
  a={1,2,3,4,5};
  int i;
  for(i =0;i<5;i++){
    int x = a[i];
    cout << x;
    if(i==3){
      break;
    }
  }
  cout << i;
  
}