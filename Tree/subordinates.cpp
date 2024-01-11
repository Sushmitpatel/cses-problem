/*
  // using dfs while returning from a node then increase the number of child 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
vector<int>ans(N,1);
void dfs(int node,map<int,vector<int>>&adj){
    for(auto it:adj[node]){
        dfs(it,adj);
        ans[node]+=ans[it]; 
    }
}
void solve() {
 int n;
 cin>>n;
 map<int,vector<int>>adj;
 for(int i=2;i<=n;i++){
    int x;
    cin>>x;
    adj[x].push_back(i);
 }
 dfs(1,adj);
 for(int i=1;i<=n;i++){
    cout<<ans[i]-1<<" ";
 }
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
*/

/* based on start and end time*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
vector<int>stime(N);
vector<int>etime(N);
void dfs(int node,map<int,vector<int>>&adj,int &time){
    stime[node]=time++;
    for(auto it:adj[node]){
        dfs(it,adj,time);
    }
    etime[node]=time++;
}
void solve() {
   int n;
 cin>>n;
 map<int,vector<int>>adj;
 for(int i=2;i<=n;i++){
    int x;
    cin>>x;
    adj[x].push_back(i);
 }
 int time=1;
 dfs(1,adj,time);
 for(int i=1;i<=n;i++){
   cout<<(etime[i]-stime[i])/2<<" ";
 }
   
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
