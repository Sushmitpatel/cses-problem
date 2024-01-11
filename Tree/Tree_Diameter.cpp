#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
vector<int>depth(N);
void dfs(int node,map<int,vector<int>>&adj,int par){
    for(auto it:adj[node]){
        if(it==par)continue;
         depth[it]=1+depth[node];
        dfs(it,adj,node);
       
    }
}
void solve() {
  int n;
  cin>>n;
  map<int,vector<int>>adj;
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  } 
  dfs(1,adj,-1);
  int rad=0;
  int terminalNode=0;
  for(int i=1;i<=n;i++){
    if(depth[i]>rad){
        terminalNode=i;
        rad=depth[i];
    }
  }
 depth.assign(N, 0);
  dfs(terminalNode,adj,-1);
  cout<<*max_element(depth.begin(),depth.begin()+n+3);
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
