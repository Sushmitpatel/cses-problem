#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
vector<int>flag(N);
void dfs(int node,map<int,vector<int>>&adj,int par){
    for(auto it:adj[node]){
        if(it==par)continue;
        dfs(it,adj,node);
        flag[node]|=!flag[it];
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
   int ans=0;
   for(int i=1;i<=n;i++){
    // cout<<flag[i]<<" ";
    ans+=flag[i];
   }
  cout<<ans;
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
/*
  alternate solution based on dp approach
  url=  https://usaco.guide/gold/dp-trees


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "") {  // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0);
	cin.tie(0);  // see Fast Input & Output
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin);  // see Input & Output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vi adj[200005];
int dp[200005][2];

void dfs(int v, int p) {
	for (int to : adj[v]) {
		if (to != p) {
			dfs(to, v);
			dp[v][0] += max(dp[to][0], dp[to][1]);
		}
	}
	for (int to : adj[v]) {
		if (to != p) {
			dp[v][1] = max(dp[v][1], dp[to][0] + 1 + dp[v][0] -
			                             max(dp[to][0], dp[to][1]));
		}
	}
}

int main() {
	setIO();
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}
	dfs(0, -1);
	cout << max(dp[0][0], dp[0][1]) << '\n';
}
*/