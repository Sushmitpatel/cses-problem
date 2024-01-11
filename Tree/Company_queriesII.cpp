

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
const int MX=20;
vector<vector<int>>dp;
vector<int>depth(N);
void dfs(int node,map<int,vector<int>>&adj){
    for(auto it:adj[node]){
        depth[it]=depth[node]+1;
        dfs(it,adj);
    }
}
int jump(int node,int lh){
    for(int i=MX-1;i>=0;i--){
        if((lh>>i)&1){
            node=dp[i+1][node];
        }
    }
    return node;
}
void solve() {
 int n,q;
 cin>>n>>q;
 map<int,vector<int>>adj;
 dp.resize(MX,vector<int>(N));
 for(int i=1;i<n;i++){
    int x;
    cin>>x;
    dp[1][i+1]=x;
    adj[x].push_back(i+1);
 }
 dfs(1,adj);
 for(int i=2;i<MX;i++){
    for(int j=1;j<=n;j++){
        dp[i][j]=dp[i-1][dp[i-1][j]];
    }
 }

 while(q--){
    int x,y;
    cin>>x>>y;
    // step1:- bring both node at same level
    if(depth[x]<depth[y])swap(x,y);
    int depthDiff=depth[x]-depth[y];
     x=jump(x,depthDiff);
    int ans=0;
    if(x==y){
        cout<<x<<endl;
       continue;
    }
    //step2:- lift the both node if 2^i th ancesstor is not same of both node;
    for(int i=MX-1;i>0;i--){
        if(dp[i][x]!=dp[i][y]){
            x=dp[i][x];
            y=dp[i][y];
            
        }
    }
    cout<<dp[1][x]<<endl;

 }


}

int32_t main() {
   
    solve();
    //cout<<endl;
    return 0;
}
