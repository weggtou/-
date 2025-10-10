#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    string A;
    cin >> A;
    string B;
    cin >> B;
    int c;
    cin >> c;
    int year = stoi(A.substr(0,4));
    int mounth = stoi(A.substr(5,2));
    int day = stoi(A.substr(8,2));
    int hour = stoi(B.substr(0,2));
    int minit = stoi(B.substr(3,2));
    int second = stoi(B.substr(6,2));
    int mon [13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int all[5];
    auto judge = [&](){for(int y = 1970;;y++){
      if((y%4==0&&y%100!=0)||y%400==0){
        mon[2]=29;
      }else{
        mon[2]=28;
      }
      for(int m = 1;m<=12;m++){        
        for(int d = 1;d<=mon[m];d++){
          for(int h = 0;h<=24;h++){
            for(int mn = 0;mn<=60;mn+=c){
              if(y>year||(y==year&&m>mounth)||(y==year&&m==mounth&&d>day)||(y==year&&m==mounth&&d==day&&h>hour)||(y==year&&m==mounth&&d==day&&h==hour&&mn>minit)){
                return;
              }
              all[0] = y;all[1]=m;all[2]=d;all[3]=h;all[4]=mn;
            }
          }
        }
      }
    }
   };
    judge();
    cout << all[0]<<'-'<<all[1]/10<<all[1]%10<<'-'<<all[2]/10<<all[2]%10<<' '<<all[3]/10<<all[3]%10<<':'<<all[4]/10<<all[4]%10<<':'<<"00"<<endl;
    
  }
}