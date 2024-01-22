#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=1e6+7;

/*       memoization       */
/*vector<int>dp(N,-1);
int f(int n){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1)return dp[n];
    int ans=INT_MAX;
    int num=n;
   
    while(num>0){
         int digit=num%10;
         num=num/10;
         if(digit==0)continue;
         
         if(n>=digit){
           ans=min(ans,1+f(n-digit));
        }
       
    }
    return dp[n]=ans;
}*/
void solve() {
 int n;
 cin>>n;
 //cout<<f(n); 

 // dp[i] will be my dp state that have information of minimum number of operation to make it (i) zero;
 // dp[i]=min(dp[i],1+dp[i-digits of i])
 vector<int>dp(N,INT_MAX);
 dp[0]=0;
 for(int i=1;i<=n;i++){
    int num=i;
      while(num>0){
        int digit=num%10;
        num/=10;
        if(digit==0)continue;
        if(i>=digit){
            dp[i]=min(dp[i],1+dp[i-digit]);
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
