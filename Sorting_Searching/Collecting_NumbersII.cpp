#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>>v(n);
  vector<int>posNum(n+1);
  for(int i=0;i<n;i++){
    cin>>v[i].first;
    v[i].second=i;
    posNum[i]=v[i].first;
  } 
  sort(v.begin(),v.end());
  int ans=1;
  
  for(int i=1;i<n;i++){
     if(v[i-1].second>v[i].second){
         ans++;
     }
  }
  while(m--){
    int pos1,pos2;
    cin>>pos1>>pos2;
    pos1--,pos2--;
    int num1=posNum[pos1];
    int num2=posNum[pos2];
  }
 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
