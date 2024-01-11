#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
const int row=20;
vector<vector<int>>dp;
vector<int>par(N);
void solve() {
   dp.resize(row,vector<int>(N));
   int n,q;
   cin>>n>>q;
   
   for(int i=1;i<n;i++){
    int  x;
    cin>>x;
    par[i+1]=x;
    dp[1][i+1]=x;
   }
   for(int i=2;i<row;i++){
      for(int j=1;j<=n;j++){
          dp[i][j]=dp[i-1][dp[i-1][j]];// if we need to find 2^kth ancesstor then first we will find 2^k-1 ancesstor(assume it is "A") then now we need to  find the 2^k-1 th ancesstor of node "A"; 
      }
   }
//    for(int i=0;i<log2(n)+2;i++){
//     for(int j=1;j<=n;j++){
//        cout<<dp[i][j]<<" ";
//     }
//     cout<<endl;
//    }

  while(q--){
    int x,k;
    cin>>x>>k;
    int sb=log2(k);
    int y=x;
    for(int i=sb;i>=0;i--){
        if((k>>i)&1){
         y=dp[i+1][y];
        }
    }
    if(!y){
        cout<<"-1"<<endl;
    }
    else{
        cout<<y<<endl;
    }
  }

}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
