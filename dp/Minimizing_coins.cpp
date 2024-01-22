#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=1e6+7;
vector<int>dp(N,INT_MAX);
int f(int n,int amount,vector<int>&coins ){
    if(n<0)return 0;
    if(n==0){
        if(amount==0)return 0;
         if(amount%coins[0]==0){
            return amount/coins[0];
        }
        return INT_MAX;
    }
    
    if(dp[amount]!=-1)return dp[amount];
    int take=INT_MAX;
    if(amount>=coins[n]){
        take=1+f(n,amount-coins[n],coins);
    }
    int notTake=f(n-1,amount,coins);
    return dp[amount]=min(take,notTake);
}
void solve() {
   int n,m;
   cin>>n>>m;
   vector<int>coins;

   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    coins.push_back(x);
   }

   /* for memoization technique */
//    int ans=f(n-1,m,coins);
//    if(INT_MAX==ans){
//     cout<<"-1";
//    }
//    else{
//     cout<<ans;
//    }

/* tabulation*/
for(int i=0;i<=N;i++){
  if(i%coins[0]==0){
    dp[i]=i/coins[0];
  }
}
for(int i=1;i<n;i++){
    for(int am=1;am<=m;am++){
        if(am-coins[i]>=0){
            dp[am]=min(dp[am],dp[am-coins[i]]+1);
        }
        
    }
}
if(dp[m]==INT_MAX){cout<<-1;return;}
cout<<dp[m];

}

int32_t main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
