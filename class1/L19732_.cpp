#include <iostream>
#include <math.h>
using namespace std;
int main(){
  int tt;
  for(int t=1;;t++){
    if(15*t%(343720*2)==0&&17*t%(233333*2)==0){
      tt = t;
      break;
    }
  }
  cout.precision(2);
  cout << fixed;

  cout << hypot(15*tt,17*tt);
}