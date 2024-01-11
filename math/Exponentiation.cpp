#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
int f(int n,int m){
    
    if(m==0)return 1ll;
    if(n==0)return 0ll;
    int temp=f(n,m/2);
    if(m&1){
        return ((((temp%mod)*1ll*(temp%mod))%mod)*n)%mod;
    }
    else{
        return ((temp%mod)*1ll*(temp%mod))%mod;
    }
    return 0;
}
void solve() {
   int n,m;
   cin>>n>>m;
   cout<<f(n,m);
}

int32_t main() {
   int t;
   cin>>t;
   while(t--){
   solve();
    cout<<endl;
   }
    
    return 0;
}
