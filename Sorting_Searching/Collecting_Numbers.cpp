#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
  int n;
  cin>>n;
  vector<pair<int,int>>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i].first;
    v[i].second=i;
  } 
  sort(v.begin(),v.end());
  int ans=1;
  
  for(int i=1;i<n;i++){
     if(v[i-1].second>v[i].second){
         ans++;
     }
  }
  cout<<ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
