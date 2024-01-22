#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n,m;
   cin>>n>>m;
   vector<int>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   vector<vector<int>>dp(n,vector<int>(m+3));

   // dp[i][x] will be the dp state that have information of how many ways are possible to generate required array till ith index having number as x;
   // dp[i][x]=dp[i-1][x]+dp[i-1][x+1]+dp[i-1][x-1];
    if(v[0])dp[0][v[0]]=1;
    else{
        for(int i=1;i<=m;i++){
            dp[0][i]=1;
        }
    }
    for(int i=1;i<n;i++){
        for(int x=1;x<=m;x++){
            if(v[i]==0||v[i]==x){
                dp[i][x]=(dp[i-1][x]+dp[i-1][x-1]+dp[i-1][x+1])%mod;
            }
            else{
                dp[i][x]=0;
            }
        }
    }
    
    int ans=0;
    for(int i=1;i<=m;i++){
        ans=(ans+dp[n-1][i])%mod;
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
