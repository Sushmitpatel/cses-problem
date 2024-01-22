#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=1e6+7;
vector<int>dp(N,0);
// memoization
// state of dp will be dp[x] means number of dice combination for sub problem (x);
int f(int n){
   if(n<=0){
    if(n==0)return 1;
    return 0;
   }
   if(dp[n]!=-1)return dp[n];
   int ans=0;
   for(int i=1;i<=6;i++){
     ans=(ans+f(n-i))%mod;
   }
   return dp[n]=ans;
}
void solve() {
   int n;
   cin>>n;
   dp[0]=1;
   //tabulation
   for(int i=1;i<=n;i++){
      for(int j=1;j<=6;j++){
        if(i-j>=0){
            dp[i]=(dp[i]+dp[i-j])%mod;
        }
      }
   }
   cout<<dp[n];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
