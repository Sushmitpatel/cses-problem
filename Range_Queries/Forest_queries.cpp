#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n,q;
   cin>>n>>q;
   vector<vector<int>>mat(n+1,vector<int>(n+1));
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        char x;
        cin>>x;
        if(x=='*')mat[i][j]=1;
    }
   }
   /* take prefix sum of each row */
   for(int i=0;i<=n;i++){
    for(int j=1;j<=n;j++){
     mat[i][j]+=mat[i][j-1];
    }
   }
   /* take prefix sum of each column */
   for(int i=1;i<=n;i++){
     for(int j=0;j<=n;j++){
        mat[i][j]+=mat[i-1][j];//********* now each cell value representing the how many trees are present in rectangle from (1,1) to (i,j)*********;
     }
   }
   while(q--){
     int a,b,c,d;
     cin>>a>>b>>c>>d;
     int ans=mat[c][d]-mat[a-1][d]-mat[c][b-1]+mat[a-1][b-1];
     cout<<ans<<endl;
   }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //cout<<endl;
    return 0;
}
