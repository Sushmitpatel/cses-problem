#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
int modularExponential(int base,int exponent){
    if(exponent==0)return 1;
    int temp=modularExponential(base,exponent/2);
    if(exponent&1){
        return ((((temp%mod)*(temp%mod))%mod)*(base%mod))%mod;
    }
    else{
        return ((temp%mod)*(temp%mod))%mod;
    }
    return -1;
}
void solve() {
   int n;
   cin>>n;
   int ans=0;
   int j;
   for(int i=1;i<=n;i=j){
      int q=n/i;
      j=n/q+1;
      int no=j-i;
      int sum=((((no%mod)*((2*i+(no-1))%mod))%mod)*modularExponential(2,mod-2))%mod;
      ans=(ans+((q%mod)*(sum))%mod)%mod;
   }
  cout<<ans;
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
