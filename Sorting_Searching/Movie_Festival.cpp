#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n;
   cin>>n;
   vector<pair<int,int>>v;
   for(int i=0;i<n;i++){
    int s,e;
    cin>>s>>e;
    v.push_back({e,s});
   }
   sort(v.begin(),v.end());// sort according to ending time
   int prev=-1;
   int ans=0;
   for(int i=0;i<n;i++){
      if(v[i].second>=prev){
        ans++;
        prev=v[i].first;
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
