#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n;
   cin>>n;
   vector<double>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   sort(v.begin(),v.end());
   double desti=v[n/2];
   if(!(n&1))desti=(desti+v[n/2-1])/2;
   double ans=0;
   for(auto it:v){
    ans+=abs(it-desti);
   }
  cout<<(long long)ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
