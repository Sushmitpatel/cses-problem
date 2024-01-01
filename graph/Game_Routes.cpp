#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
void solve() {
   int n,m;
   cin>>n>>m;
   vector<int>adj[n+1];
   vector<int>indeg(n+1);
   while(m--){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    indeg[v]++;
   }
 queue<int>q;
 for(int i=2;i<=n;i++){
    if(indeg[i]==0)
    q.push(i);
 }
 while(!q.empty()){
    int node=q.front();
    q.pop();
    if(node==1)break;
    for(auto it:adj[node]){
        --indeg[it];
        if(indeg[it]==0){
            q.push(it);
        }
    }
 }
 vector<int>route(n+1);
 q.push(1);
 route[1]=1;
 while(!q.empty()){
    int node=q.front();
    q.pop();
    for(auto it:adj[node]){
        --indeg[it];
        if(indeg[it]==0){
            q.push(it);
        }
        
        route[it]=(route[it]+route[node])%mod;
        //cout<<route[it]<<" ";
    }
 }
cout<<route[n];

   
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
