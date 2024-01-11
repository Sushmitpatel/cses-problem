/*
It's easy to find the sum of distances from a single node - just root the tree
at that node, do a DFS, and add the depths of each other node to the answer.
Unfortunately, $n$ can go up to $2 \cdot 10^5$, so we can't just do this for
each node.

If we have the answer for some node (let's say node 1), how can we quickly find
the answer for its neighbours?

The key observation is that if we reroot the tree at node 1's neighbour (let's
say node 2), then

The depths of all nodes in node 2's subtree decrease by 1.
The depths of all nodes outside of its subtree increase by 1.


This gives us a nice way to transition from node 1's answer to node 2's answer
using only $n$ and the size of node 2's subtree! Observe that the change in the
answer is exactly $n - 2(\text{node 2's subtree size})$.

We can use DFS to find both the answer for node 1 and the size of each node's
subtree when rooted at node 1, and then DFS again to compute all the answers.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
vector<int>ans(N);
vector<int>depth(N,1);
void dfs(int node,map<int,vector<int>>&adj,int par,int d){
   ans[1]+=d;
   for(auto it:adj[node]){
     if(it==par)continue;
     dfs(it,adj,node,d+1);
     depth[node]+=depth[it];
   }
}
void dfsAns(int node,map<int,vector<int>>&adj,int par,int n){
    for(auto it:adj[node]){
        if(par==it){
            continue;
        }
        ans[it]=ans[node]+n-2*depth[it];
        dfsAns(it,adj,node,n);
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
  dfs(1,adj,-1,0);
  dfsAns(1,adj,-1,n);
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
