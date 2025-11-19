#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector <long long> a(n+1);
  for(int i = 1;i<=n;i++){
    cin >> a[i];
  }
  long long z=0,f=0;
  for(int i = n;i>0;i--){
    a[i]-=a[i-1];
    if(i!=1&&a[i]>0){
      z+=a[i];
    }else if(i!=1&&a[i]<0){
      f+=a[i];
    }
  }
  //目的是让差分后的结果，除了第一个值其他的都变为0
  //最快的方法就是负数的地方加一，正数的地方减一，相互对应，
  //因为，如果不一一对应，那么剩下的正数或者负数肯定要再浪费 一次次数来靠近0；
  //而最后剩下的一定都是正数或者都是负数，而有两种选择，是选择从头开始变，或则变到结尾
  //在加上差分求和的值只与最后的结果有关，中间过程怎么样无所谓，所以只有几次从前，几次向后的差别
  //没有顺序的差别，所以所有的情况就是从0个向前到n个向前共n+1个情况
  cout << max(abs(f),z) << endl;
  cout << abs(abs(f)-z)+1 << endl;
}