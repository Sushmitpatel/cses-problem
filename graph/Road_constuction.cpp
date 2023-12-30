#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
/*-----------disjointset----------------*/
class disjointset{
  public:
  vector<int>size;
  vector<int>par;
  vector<int>rank;
  public:
  disjointset(long long  n){
    size.resize(n+1);
    par.resize(n+1);
    rank.resize(n+1);
    for(int i=1;i<=n;i++){
      par[i]=i;
      size[i]=1;
    }
    for(int i=1;i<=n;i++){
      par[i]=i;
      rank[i]=0;
    }
  }
  int find_par(int a){
    if(par[a]==a){
      return a;
    }
    else{
      return par[a]=find_par(par[a]);
    }
  } 
  void Union_by_size(int a,int b){
    int par_a=find_par(a);
    int par_b=find_par(b);
    if(par_a==par_b)return;
    if(size[par_a]>=size[par_b]){
      par[par_b]=par_a;
      size[par_a]+=size[par_b];
    }
    else{
      par[par_a]=par_b;
      size[par_b]+=size[par_a];
    }
  }
  void Union_by_rank(int a,int b){
    int par_a=find_par(a);
    int par_b=find_par(b);
    if(par_a==par_b)return;
    if(rank[par_a]>=rank[par_b]){
      par[par_b]=par_a;
      rank[par_a]+=rank[par_b];
    }
    else{
      par[par_a]=par_b;
      rank[par_b]+=rank[par_a];
    }
  }
};


void solve() {
   int n,m;
   cin>>n>>m;
   disjointset dsu(n+1);
   int component=n;
   int maxs=1;
   while(m--){
    int x,y;
    cin>>x>>y;
    if(dsu.find_par(x)!=dsu.find_par(y)){
        component--;
        int size1=dsu.size[dsu.find_par(x)];
        int size2=dsu.size[dsu.find_par(y)];
        maxs=max(maxs,size1+size2);
        dsu.Union_by_size(x,y);
        cout<<component<<" "<<maxs<<endl;

    }
    else{
        cout<<component<<" "<<maxs<<endl;
    }
   }
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
