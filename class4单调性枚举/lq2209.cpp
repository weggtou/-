#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,g;
  cin >> n >> g;
  vector <int> a(n);
  vector <int> can(n);
  for(int i = 0;i<n;i++){
    cin >> a[i];
    if(a[i]%g!=0){
      can[i]=1;
    }
  }

  int sum = can[0];
  long long ans = 0;
  for(int l = 0,r = 0;l<n;){
    while(r<n-1&&sum < 2){
      sum += can[++r];
    }
    if(sum >= 2){
      ans += r-l-1;
    }else{
      ans += r-l;
    }
    sum -= can[l++];
  }
  cout << ans << endl;
}
//刚开始的思路是找到最大的不和法区间，求他里面包含的所有结果，但是
//这个方法肯定会有重复
//如1到4是最大不合法，那么就加了12 23 ,接下来如果2到5是最大不合法
//那么23 34就多算了一个 23
//所以只需要加12 123就行，这样就不会重复了
//之后就是末尾区间的处理，如果按之前那种算法的话，末尾区间直接结束的话
//会少很多个，所以for循环结束的条件不能是r<n,应该是l<r;这样如果是
//12345的话  345是到末尾的区间，但是这个区间合法，那么l就会一直向前
//45 5,这样就不会少了。