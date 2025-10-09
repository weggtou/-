#include <iostream>
#include <vector>
using namespace std;
int main(){
  cout << 4430091<<endl;
  return 0;
  int cont = 0;
  for(int i =1;i<=100000000;i++){
    if([](int x){
      vector <int> a;
      for(;x;x/=10){
        int w = x%10;
        a.push_back(w);
      }
      if((a.size())&1!=0){
        return false;
      }else{
        int f=0,b =0;
        for(int g =0;g<a.size();g++){
          if(g<=a.size()/2-1){
            f+=a[g];
          }else{
            b+=a[g];
          }
        }
        if(f==b){
          return true;
        }else{
          return false;
        }
      }
    }(i)){
      cont++;
    }
  }
  cout << cont;
}