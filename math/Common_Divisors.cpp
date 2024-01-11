#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>mp(1e6+3);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx=max(mx,arr[i]);
        mp[arr[i]]++;
    }
    int ans=1;
    for(int i=2;i<=mx;i++){
        int count=0;
        int j=i;
        while(j<=mx){
          count+=mp[j];
          j+=i;
        }
        if(count>=2)ans=max(i,ans);
    }
    cout<<ans;
   
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
