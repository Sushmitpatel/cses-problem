#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=5007;

// memoization
/*
vector<vector<int>>dp(N+3,vector<int>(N+3,-1));
int f(int i,int j,string &s1,string &s2){
    if(i==0||j==0){
        return max(i,j);
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX,op4=INT_MAX;
    if(s1[i-1]==s2[j-1]){
         op1=f(i-1,j-1,s1,s2);
    }
    else{
        op4=1+f(i-1,j-1,s1,s2);//replace
         op3=1+f(i-1,j,s1,s2);// delete
         op2=1+f(i,j-1,s1,s2);//add
         
    }
    return dp[i][j]=min({op1,op2,op3,op4});

}
*/
void solve() {
  string s1,s2;
  cin>>s1>>s2; 
  //cout<<f(s1.length(),s2.length(),s1,s2);

  // tabulation

  /*
  dp state:- dp[i][j]
  dp[i][j]=edit distance for changing s1[0,1....i] to s2[0,1,....j]
  recurrence relation dp[i][j]={first if s[i]==s[j] = dp[i-1][j-1]     second:-
  1+min(dp[i-1][j-1](replace),dp[i-1][j](delete),dp[i][j-1](add));
  }
    */
 int n1=s1.length();
 int n2=s2.length();
   vector<vector<int>>dp(N,vector<int>(N,INT_MAX));
   for(int i=0;i<=n2;i++){
     dp[0][i]=i;
   }
   for(int i=0;i<=n1;i++){
      dp[i][0]=i;
   }
   for(int i=1;i<=n1;i++){
     for(int j=1;j<=n2;j++){
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=dp[i-1][j-1];
        }
        else{
            dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
        }
     }
   }
   cout<<dp[n1][n2];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
