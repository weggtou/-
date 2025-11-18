#include <bits/stdc++.h>
using namespace std;
int main(){
  auto all = vector(13,vector<int>(13));
  for(int i = 0;i<4;i++){
    for(int j = 7-i;j<=6+i;j++){
      all[6-i][j]=(4-i)*(4-i);
      all[6+i][j]=(4-i)*(4-i);
      all[j][6-i] = (4-i)*(4-i);
      all[j][6+i] = (4-i)*(4-i);
    }
  }
  for(auto i :all){
    for(auto j : i){
      cout << j << ' ';
    }
    cout << endl;
  }
  cout << endl;
  for(int i = 12;i>=0;i--){
    for(int j = 12;j>=0;j--){
      if(i)all[i][j] = all[i][j] - all[i-1][j];
    }
    adjacent_difference(all[i].begin(),all[i].end(),all[i].begin());

  }
  for(auto i :all){
    for(auto j : i){
      cout << j << ' ';
    }
    cout << endl;
  }
  for(int i = 12;i>=0;i--){
    if(i)all[i][i] = all[i][i] - all[i-1][i-1];
  }
  for(int i = 12;i>=1;i--){
    if(i!=1)all[i][13-i] = all[i][13-i] - all[i-1][13-i+1];
  }
  cout << endl;
  for(auto i :all){
    for(auto j : i){
      printf("%2d ",j);
    }
    cout << endl;
  }
  for(int i = 12;i>=0;i--){
    if(i)all[i][i] = all[i][i] - all[i-1][i-1];
  }
  for(int i = 12;i>=1;i--){
    if(i!=1)all[i][13-i] = all[i][13-i] - all[i-1][13-i+1];
  }
  cout << endl;
  for(auto i :all){
    for(auto j : i){
      printf("%2d ",j);
    }
    cout << endl;
  }
  for(int i = 12;i>=0;i--){
    if(i)all[i][i] = all[i][i] - all[i-1][i-1];
  }
  for(int i = 12;i>=1;i--){
    if(i!=1)all[i][13-i] = all[i][13-i] - all[i-1][13-i+1];
  }
  cout << endl;
  for(auto i :all){
    for(auto j : i){
      printf("%2d ",j);
    }
    cout << endl;
  }
  
}