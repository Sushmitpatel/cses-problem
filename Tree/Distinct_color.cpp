#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
map<int,int>mp;
vector<int>ans(N);
void dfs(int node,vector<vector<int>>&adj,int par,unordered_set<int>st){
    for(auto it:adj[node]){
        if(par==it)continue;
        dfs(it,adj,node,st);
         st.insert(mp[it]);
    }
}
void solve() {
  int n;
  cin>>n;
  vector<vector<int>>adj(N);
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    mp[i]+=x;
  }
  
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  unordered_set<int>st;
  dfs(1,adj,-1,st);
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
