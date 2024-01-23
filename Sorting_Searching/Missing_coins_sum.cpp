#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  } 
  sort(v.begin(),v.end());
  int lsum=1;
  for(int i=0;i<n&&lsum>=v[i];i++){
    lsum+=v[i];
  }
  cout<<lsum;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
