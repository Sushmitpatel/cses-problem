#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
vector<int>ans(1e6+1,1);
void solve() {
  int n=1e6+1;
for(int i=2;i<n;i++){
    int j=i;
    while(j<n){
        ans[j]++;
        j+=i;
    }
}
  
}

int32_t main() {
    solve();
   int t;
   cin>>t;
   while(t--){
  int n;
  cin>>n;
  cout<<ans[n];
    cout<<endl;
   }
    
    return 0;
}
