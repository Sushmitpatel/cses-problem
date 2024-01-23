#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e16
#define RINF -1e16
const int mod=1e9+7;

void solve() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  } 
  int ans=RINF;
  int sum=0;
  // Kanadane algorithms 
  for(int i=0;i<n;i++){
    sum+=v[i];
    ans=max(ans,sum);
    if(sum<0){
        sum=0;
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
