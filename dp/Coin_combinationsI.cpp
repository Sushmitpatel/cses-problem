#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=1e6+7;
vector<int>dp(N,-1);
int f(int n,int amount,vector<int>&coins ){
        //if(amount<0)return 0;
        if(amount==0)return 1;
    int ans=0;
    if(dp[amount]!=-1)return dp[amount];
    for(int j=coins.size()-1;j>=0;j--){
        if(amount>=coins[j]){
            ans=(ans+f(j,amount-coins[j],coins))%mod;
        }
    }
    return dp[amount]=ans;
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
//     cout<<ans;

/* tabulation*/

//dp[i]=for all coins dp[i-c1]+dp[i-c2]+------dp[i-cn];
// dp[i] has information of number of ways to make sum equall to i;
 dp[0]=1;
    for(int am=1;am<=m;am++){
        for(int i=0;i<n;i++){
        if(am-coins[i]>=0){
            dp[am]=(dp[am]+dp[am-coins[i]])%mod;
        }
        
    }
}

cout<<dp[m];

}

int32_t main() {
    //  ios::sync_with_stdio(false);
    //  cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
