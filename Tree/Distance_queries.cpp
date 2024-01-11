
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
const int MX=20;
vector<vector<int>>dp;
vector<int>depth(N);
vector<int>par(N);

// dfs for calculating the depth of all node and parent of node
void dfs(int node,vector<vector<int>>&adj,int p){
    for(auto it:adj[node]){
        if(it==p)continue;
        depth[it]=depth[node]+1;
         par[it]=node;
        dfs(it,adj,node);
    }
}
// function to find lh(variable name) th ancesstor
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
 vector<vector<int>>adj(n+2);
 dp.resize(MX,vector<int>(N));
 for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
 }
 dfs(1,adj,-1);
 for(int i=1;i<=n;i++){
    dp[1][i]=par[i];
 }
 // dp for pre calculation of ancesstor this dp will contaion 2^i th ancesstor where i is 0,1,2,3,---log2(n)
 for(int i=2;i<MX;i++){
    for(int j=1;j<=n;j++){
        dp[i][j]=dp[i-1][dp[i-1][j]];//find 2^i th ancesstor of jth node
    }
 }

 while(q--){
    int x,y;
    cin>>x>>y;
    int ta=x,tb=y;
    // step1:- bring both node at same level
    if(depth[x]<depth[y])swap(x,y);
    int depthDiff=depth[x]-depth[y];
     x=jump(x,depthDiff);
    int ans=0;
    if(x==y){
        //**** minimum distance between two node if tree is rooted at 1(one) 
        //  distance[node1-->node2]=depth[node1]+depth[node2]-2*depth[LCA(node1,node2)]
        cout<<depth[ta]+depth[tb]-2*depth[x]<<endl;
       continue;
    }
    //step2:- lift the both node if 2^i th ancesstor is not same of both node;
    for(int i=MX-1;i>0;i--){
        if(dp[i][x]!=dp[i][y]){
            x=dp[i][x];
            y=dp[i][y];
            
        }
    }
    x=dp[1][x];
    cout<<depth[ta]+depth[tb]-2*depth[x]<<endl;

 }


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //cout<<endl;
    return 0;
}
