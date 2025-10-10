#include <iostream>
#include <bits/debugger.h>
#include <vector>
using namespace std;

#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) {return *this;}
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif
bool judge(vector <int>&now,vector<int>&a){
  size_t idx = 0;
  for(auto &i:a){
    if(i==now[idx]){
      if(++idx==now.size()){
        return true;
      }
    }
  }
  return false;
}
int main(){
  vector <int> a;
  int x;
  while(cin >> x){
    a.push_back(x);
  }
  int cont = 0;
  int mon [13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  for(int i = 1;i<=12;i++){
    for(int g=1;g<=mon[i];g++){
      vector<int> now{2,0,2,3,i/10,i%10,g/10,g%10};
      cont+=judge(now,a);
    }
  }
  cout << cont;
}