// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define INT_MAX 1e16
// const int mod=1e9+7;
// void solve() {
//    int n,m;
//    cin>>n>>m;
//    vector<pair<int,int>>adj[n+1];
//    vector<int>dis(n+1,INT_MAX);
//    vector<int>minf(n+1,0);
//    vector<int>maxf(n+1,0);
//    vector<int>ways(n+1,0);
//    priority_queue<
//    pair<int,int>,
//    vector<pair<int,int>>,
//    greater<pair<int,int>>
//    >pq;
//    while(m--){
//     int x,y,w;
//     cin>>x>>y>>w;
//      adj[x].push_back({y,w});
//    }
//    pq.push({0,1});
//    dis[1]=0;
//    ways[1]=1;
//    while(!pq.empty()){
//     auto it=pq.top();
//     pq.pop();
//     int par=it.second;
//     int cost=it.first;
//     if(dis[par]<cost)continue;
//     for(auto it:adj[par]){
//         int w=it.second;
//         int child=it.first;
//         if(dis[par]+w==dis[child]){
//            ways[child]=(ways[child]+ways[par])%mod;
//            minf[child]=min(minf[par]+1,minf[child]);
//            maxf[child]=max(maxf[par]+1,maxf[child]);
//         }
//         else if(dis[par]+w<dis[child]){
//             ways[child]=ways[par];
//             minf[child]=minf[par]+1;
//             maxf[child]=maxf[par]+1;
//             dis[child]=dis[par]+w;
//             pq.push({dis[child],child});
//         }
//     }
//    }
//    cout<<dis[n]<<" "<<ways[n]<<" "<<minf[n]<<" "<<maxf[n];
// }

// int32_t main() {
   
//     solve();
//     cout<<endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

struct Node {
    int dis;
    int ways;
    int min_f;
    int max_f;
    
    Node(int w) {
        dis = w;
        min_f = 1;
        ways = 1;
        max_f = 1;
    }
};

void solve() {
   int n,m;
   cin >> n >> m;
   vector<pair<int,int>> adj[n+1];
   vector<Node> nodes(n+1, INT_MAX);
   
   priority_queue<
   pair<int,int>,
   vector<pair<int,int>>,
   greater<pair<int,int>>
   > pq;
   
   while(m--) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
   }
   
   pq.push({0,1});
   nodes[1] = Node(0);
   
   while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int par = it.second;
        int cost = it.first;
        if(nodes[par].dis < cost) continue;
        for(auto it: adj[par]) {
            int w = it.second;
            int child = it.first;
            if(nodes[par].dis + w == nodes[child].dis) {
                nodes[child].ways = (nodes[child].ways + nodes[par].ways) % mod;
                nodes[child].min_f = min(nodes[par].min_f + 1, nodes[child].min_f);
                nodes[child].max_f = max(nodes[par].max_f + 1, nodes[child].max_f);
            }
            else if(nodes[par].dis + w < nodes[child].dis) {
                nodes[child].ways = nodes[par].ways;
                nodes[child].min_f = nodes[par].min_f + 1;
                nodes[child].max_f = nodes[par].max_f + 1;
                nodes[child].dis = nodes[par].dis + w;
                pq.push({nodes[child].dis, child});
            }
        }
   }
   
   cout << nodes[n].dis << " " << nodes[n].ways << " " << nodes[n].min_f-1 << " " << nodes[n].max_f-1;
}

int32_t main() {
    solve();
    cout << endl;
    return 0;
}

