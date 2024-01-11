#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
unordered_map<int,vector<int>>adj;
vector<int>low;
vector<int>disc;
vector<int>vis;
vector<int>pathVis;
stack<int>st;
vector<vector<int>>ans;
void dfs(int node,int &tm){
    disc[node]=tm;
    low[node]=tm;
    tm++;
    st.push(node);
    vis[node]=1;
    pathVis[node]=1;
    for(auto child:adj[node]){
        if(!vis[child]){
            dfs(child,tm);
            low[node]=min(low[child],low[node]);
        }
        else{
            if(pathVis[child]){
                low[node]=min(low[node],disc[child]);
            }
        }
    }
    int w=0;
   // cout<<node<<" "<<disc[node]<<" "<<low[node]<<endl;
    if(disc[node]==low[node]){
        // cout<<node<<" ";
        vector<int>temp;
        while(st.top()!=node){
          w=st.top();
          temp.push_back(w);
          st.pop();
          pathVis[w]=false;
        }
        w=st.top();
        st.pop();
        pathVis[w]=false;
        temp.push_back(w);
        ans.push_back(temp);
    }
    
}
void solve() {
    int tm=0;
   int n,m;
   cin>>n>>m;
   low.resize(n+1);
   disc.resize(n+1);
   vis.resize(n+1);
   pathVis.resize(n+1);
   while(m--){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
   }
   int count=0;
   for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i,tm);
        
    }
   }
   int size=ans.size();
   cout<<size<<endl;
   vector<int>kingdom(n+1);
   for(int i=0;i<size;i++){
     for(auto it:ans[i]){
        kingdom[it]=i+1;
     }
   }
   for(int i=1;i<=n;i++){
    cout<<kingdom[i]<<" ";
   }
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}

