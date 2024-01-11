#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

const int N=2*1e5+7;

vector<int>depthFT(N);
vector<int>depthST(N);
void dfs(int node,map<int,vector<int>>&adj,int par,vector<int>&depth){
    for(auto it:adj[node]){
        if(it==par)continue;
         depth[it]=1+depth[node];
        dfs(it,adj,node,depth);
       
    }
}
void solve() {
     

  int n;
  cin>>n;
  vector<int>depth(N);
  map<int,vector<int>>adj;
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  } 
  dfs(1,adj,-1,depth);
  int rad=0;
  int terminalNode1=0;
  for(int i=1;i<=n;i++){
    if(depth[i]>rad){
        terminalNode1=i;
        rad=depth[i];
    }
  }
 depth.assign(N, 0);
  dfs(terminalNode1,adj,-1,depth);
  rad=0;
   int terminalNode2=0;
  for(int i=1;i<=n;i++){
    if(depth[i]>rad){
        terminalNode2=i;
        rad=depth[i];
    }
  }
  dfs(terminalNode1,adj,-1,depthFT);
  dfs(terminalNode2,adj,-1,depthST);
  for(int i=1;i<=n;i++){
  cout<<max(depthFT[i],depthST[i])<<" ";
  }
  
}

int32_t main() {
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout<<endl;
    return 0;
}
