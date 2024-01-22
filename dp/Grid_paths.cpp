#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n;
   cin>>n;
   vector<vector<char>>mat(n,vector<char>(n));
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>mat[i][j];
    }
   }
   vector<vector<int>>dp(n,vector<int>(n));
   if(mat[0][0]=='.')dp[0][0]=1;
   for(int i=1;i<n;i++){
    if(mat[0][i]=='*'){
        continue;
    }
    dp[0][i]=dp[0][i-1];
   }
   for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
        if(mat[i][j]=='*')continue;
        int op1=0,op2=0;
        if(i-1>=0){
           op1=dp[i-1][j];
        }
        if(j-1>=0){
            op2=dp[i][j-1];
        }
        dp[i][j]=(op1+op2)%mod;
    }
   }
   cout<<dp[n-1][n-1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
