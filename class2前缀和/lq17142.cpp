#include <iostream>
#include <vector>
using namespace std;

int main(){
  //3n-2+all[n-3]
  vector <long long> e{0,1,3,6,10};
  vector <long long> all{0,1,4,10,20};
  int i =5;
  for(;;i++){
    all[i] = i*3-3+all[i-3];
    e[i] = e[i-1]+all[i];
    if(e[i]>=20230601)break;
  }
  cout << i-1;
}