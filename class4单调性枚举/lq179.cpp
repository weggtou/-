#include <bits/stdc++.h>
using namespace std;
int main(){
  using ll = long long;
  int n,d,k;
  cin >> n >> d >> k;
  vector <pair<ll,ll>> all(n);
  for(auto &[t,i]:all){
    cin >> t >> i;
  }
  sort(all.begin(),all.end());
  set <int> ans;
  vector <ll> id(1e5+1);
  for(int l=0,r=0;l<n;){
    while(r<n&&all[r].first-all[l].first<d){
      id[all[r].second]++;
      if(id[all[r].second]>=k) ans.insert(all[r].second);
      r++;
    }
    id[all[l++].second]--;
  }
  for(auto i:ans){
    cout << i << endl;
  }
}