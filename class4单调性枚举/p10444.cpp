#include <bits/stdc++.h>
using namespace std;
//1 1 4 5 1 4
//1 1 1 4 4 5
//如果要分成两个序列，那么最大值最小值大概率在两个序列的开头和末尾
//[1,max] [min,5]
//按题目要求有 max - 1 = 5 - min
//所以max + min = 5 + 1;
//所以就是在找序列中两个数的和等于最大值和最小值的和

int main(){
  int t,id;
  cin >> t>>id;
  while(t--){
    int n;
    cin >> n;
    vector <int> a(n);
    for(auto &i:a) cin >> i;
    ranges::sort(a);
    int target = a[0] + a[n-1];
    int i = 1,j = n-2;
    for(; i<j ;){
      if(a[i] + a[j] < target){
        i++;
      }else if(a[i] + a[j] > target ){
        j--;
      }else{
        cout << "Yes" << endl;
        break;
      }
    }
    if(i>=j){
      cout << "No" << endl;
    }
  }
}