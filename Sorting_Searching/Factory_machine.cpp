#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
bool isPossible(int time,vector<int>&v,int m ){
    int count=0;
    for(auto it:v){
   count+=(time/it);
    }
    return count>=m;
}
void solve() {
  int n,m;cin>>n>>m;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  } 
  // binary search on result
  int mx=*max_element(v.begin(),v.end());
  int l=0,h=(m/n+1)*mx;// find max and min time that may possible to be ans
  int ans=0;
  while(l<=h){
    int mid=(l+h)>>1;
    if(isPossible(mid,v,m)){// if present time(mid) is greater than or equal the required minimum time than isPossible will return true so update the ans ; 
     ans=mid;
     h=mid-1;
    }
    else{
        l=mid+1;
    }
  }
  cout<<ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
