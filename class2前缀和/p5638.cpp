#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
  int n,k;
  cin >> n >>k;
  long long a;
  vector<long long> all;
  long long he = 0;
  for(int i =0;i<n-1;i++){
    scanf("%ld",&a);
    he+=a;
    all.push_back(a);
  }
  long long max=0;
  for(int i = 0;i+k-1<n-1;i++){
    long long sum =0;
    for(int j = 0;j<k;j++){
      sum+=all[i+j];
    }
    if(sum>=max){
        max = sum;
      }
  }
  cout << he-max;
}