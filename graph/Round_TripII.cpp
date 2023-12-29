#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
vector<int>vis;
vector<int>pathVis;
unordered_map<int,vector<int>>adj;
vector<int>par;
vector<int>ans;
bool dfs(int node,bool &isCycle){
    if(isCycle||ans.size()>=1)return true;
    vis[node]=1;
    pathVis[node]=1;
    for(auto it:adj[node]){
        par[it]=node;
        if(!vis[it]){
            if(dfs(it,isCycle))return true;
        }
        else{
            if(pathVis[it]){
                isCycle=true;
                int temp=it;
                do{
                    ans.push_back(temp);
                    temp=par[temp];
                }while(it!=temp);
                ans.push_back(it);
                reverse(ans.begin(),ans.end());
                return true;
            }
        }
    }
    pathVis[node]=false;
    return false;
}
void solve() {
   int n,m;
   cin>>n>>m;
  vis.resize(n+1);
  pathVis.resize(n+1);
  par.resize(n+1);
  while(m--){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
        bool isCycle=false;
        dfs(i,isCycle);
        if(isCycle){
            cout<<ans.size()<<endl;
            for(auto it:ans){
                cout<<it<<" ";
            }
            return;
        }
    }
  }
  cout<<"IMPOSSIBLE";
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
