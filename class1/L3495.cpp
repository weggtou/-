#include <bits/stdc++.h>
using namespace std;
int main(){
  int year = 2000;
  int mounth = 1;
  int day = 1;
  int cont = 0;
  map <int,int> mou {
    {1,31},
    {2,29},
    {3,31},
    {4,30},
    {5,31},
    {6,30},
    {7,31},
    {8,31},
    {9,30},
    {10,31},
    {11,30},
    {12,31}};

  for(;year<2000000;){
      cont+=[](int y,int m,int d){
      return y%m==0&&y%d==0;
    }(year,mounth,day);

    if(day==mou[mounth]){
      day=1;
      if(mounth==12){
        year++;
        mounth=1;
        if((year%4==0&&year%100!=0)||(year%400==0)){
          mou[2]=29;
        }else{
          mou[2]=28;
        }
      }else{
        mounth++;
      }
    }else{
      day++;
    }

  }
  cout << ++cont;
}