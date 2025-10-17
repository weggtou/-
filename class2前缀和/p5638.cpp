#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >>k;
  long long a;
  vector<long long> all;
  vector<long long> all2(n);
  long long he = 0;
  for(int i =0;i<n-1;i++){
    scanf("%lld",&a);
    he+=a;
    all.push_back(a);
    if(i)all2[i]=all2[i-1];
    all2[i]+=all[i];
    if(i+1>k)all2[i]-=all[i-k];
  }
  long long max=0;
  for(int i = k-1;i<n;i++){
    if(all2[i]>=max){
        max = all2[i];
      }
  }
  cout << he-max;
}