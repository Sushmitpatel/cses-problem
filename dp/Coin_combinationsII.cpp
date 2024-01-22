#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=1e6+7;
void solve() {
   int n,m;
   cin>>n>>m;
   vector<int>coins;

   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    coins.push_back(x);
   }
   // dp[i][j]:- it will give me information that how many ways are possible to make j sum using c1,c2 up to ci coins
   // dp[i][j]=dp[i-1][j]+ dp[i][j-ci]

     /*without space optimization*/
 
  /*int dp[n+1][m+1]={0};
  for(int i=0;i<=m;i++){
    dp[0][i]=!(i%coins[0]);// always use parenthesis while using logic operation like !(Not) and >>,<< ^ etc;
    // here we are storing 1 in dp if we can generate the sum(i) using only first coin
  }
  for(int i=1;i<n;i++){
    for(int sum=0;sum<=m;sum++){
        if(sum==0){dp[i][sum]=1;continue;}
        int op1=0,op2=0;
        if(sum>=coins[i])op1=dp[i][sum-coins[i]];
        op2=dp[i-1][sum];
        dp[i][sum]=(op1+op2)%mod;
    }
  }*/

  /* using space optimization (acceptable)*/
   vector<int>curr(m+1);
   vector<int>prev(m+1);
   for(int i=0;i<=m;i++){
    prev[i]=!(i%coins[0]);// always use parenthesis while using logic operation like !(Not) and >>,<< ^ etc;
    // here we are storing 1 in dp if we can generate the sum(i) using only first coin
  }
  for(int i=1;i<n;i++){
    for(int sum=0;sum<=m;sum++){
        if(sum==0){curr[sum]=1;continue;}
        int op1=0,op2=0;
        if(sum>=coins[i])op1=curr[sum-coins[i]];
        op2=prev[sum];
        curr[sum]=(op1+op2)%mod;
    }
    prev=curr;
  }


  cout<<prev[m];
  
}

int32_t main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
