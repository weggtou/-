#include <iostream>
using namespace std;


int main(){
  int t;
  cin >> t;
  int mon [13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

  auto isrun = [](int y){
    return (y%4==0&&y%100!=0)||y%400==0;
  };
  auto totime = [&](int y,int mo,int d,int h,int mi,int s){
    long long ss=0;
    for(int year = 1970;year<y;year++){
      ss+=(365+isrun(year))*3600*24;
    }
    for(int m = 1;m<mo;m++){
      ss+=(mon[m]+(m==2&&isrun(y)))*3600*24;
    }
    ss+=(d-1)*24*3600;
    ss+=h*3600+mi*60+s;
    return ss;
  };
  auto todate = [&](int t){
    int s1 = t%60;
    int mi1 = (t/60)%60;
    int h1 = (t/3600)%24;
    int d1 = t/(24*3600);
    int y1 = 1970,m1=1;
    for(;;y1++){
      int days = 365+(isrun(y1));
      if(d1>=days){
        d1-=days;
      }else{
        break;
      }
    }
    for(;;m1++){
      int days = mon[m1]+(m1==2&&isrun(y1));
      if(d1>=days){
        d1-=days;
      }else{
        break;
      }
    }
    d1++;
    if(d1==mon[m1]+(m1==2&&isrun(y1))+1){
      m1++;
      d1=1;
      if(m1==13){
        m1=1;
        y1++;
      }
    }
    printf("%d-%02d-%02d %02d:%02d:%02d\n",y1,m1,d1,h1,mi1,s1);
  };
  while(t--){
    int year,mou,day,hour,min,sec;
    int x;
    scanf("%d-%d-%d",&year,&mou,&day);
    scanf("%d:%d:%d",&hour,&min,&sec);
    scanf("%d",&x);
    x*=60;
    int time = totime(year,mou,day,hour,min,sec);
    time = time/x*x;
    todate(time);
  }
  

}