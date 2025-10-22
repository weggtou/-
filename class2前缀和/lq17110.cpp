#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int size = 1e6+1;
  vector <int> all(size*2);
  while(n--){
    int li,ri;
    cin >> li >> ri;
    all[li+ri]++;
  }
  partial_sum(all.begin(),all.end(),all.begin());
  while(m--){
    int l,r;
    cin >> l >> r;
    cout << all[r*2]-all[l*2-1] << endl;
  }
}