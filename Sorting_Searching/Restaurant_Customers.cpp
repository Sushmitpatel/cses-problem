#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n;
   cin>>n;
   map<int,int>mp;
   while(n--){
    int s,e;
    cin>>s>>e;
    mp[s]++;
    mp[e+1]--;
   }
   int ans=0;
   int sum=0;
   for(auto it:mp){
    sum+=it.second;
    ans=max(ans,sum);
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
