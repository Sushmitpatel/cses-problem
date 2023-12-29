#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16

void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
   priority_queue<
  pair<int,int>,
  vector<pair<int,int>>,
  greater<pair<int,int>>
  >pq;
  vector<vector<int>>dis(n+1,vector<int>(k,INT_MAX));
  vector<pair<int,int>>adj[n+1];
  while(m--){
    int x,y,w;
    cin>>x>>y>>w;
    adj[x].push_back({y,w});
  }
  dis[1][0]=0;
  pq.push({0,1});
  while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    int node=it.second;
    int w=it.first;
    if(w>dis[node][k-1])continue;
    for(auto child:adj[node]){
      if(dis[child.first][k-1]>w+child.second){
          dis[child.first][k-1]=w+child.second;
          pq.push({dis[child.first][k-1],child.first});
          sort(dis[child.first].begin(),dis[child.first].end());
      }
    }
  }
  for(auto it:dis[n]){
    cout<<it<<" ";
  }
 

 
}
  int32_t main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    // {
      solve();
      cout<<endl;
    //   cout << endl;
    // }
    return 0;
  }