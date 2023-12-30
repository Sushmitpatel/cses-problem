#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
  int n,m;
  cin>>n>>m;
   vector<pair<int,int>>adj[n+1];
    vector<int>vis(n+1);
   vector<int>dis(n+1,INT_MAX);
  while(m--){
   
    int  x,y,z;
    cin>>x>>y>>z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
  } 
  priority_queue<
  pair<int,int>,
  vector<pair<int,int>>,
  greater<pair<int,int>>
  >pq;
  pq.push({0,1});
  int ans=0;
  while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    int par=it.second;
    int cost=it.first;
    if(vis[par])continue;
    vis[par]=1;
    ans+=cost;
   
    for(auto child:adj[par]){
        int node=child.first;
        int w=child.second;
        if(vis[node]==0){
            pq.push({w,node});
        }
    }
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
        cout<<"IMPOSSIBLE";
        return;
    }
  }
  cout<<ans;
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
