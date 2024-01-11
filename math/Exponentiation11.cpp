#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16

int f(int n,int m,int mod){
    
    if(m==0)return 1ll;
    if(n==0)return 0ll;
    int temp=f(n,m/2,mod);
    if(m&1){
        return ((((temp%mod)*1ll*(temp%mod))%mod)*n)%mod;
    }
    else{
        return ((temp%mod)*1ll*(temp%mod))%mod;
    }
    return 0;
}
void solve() {
    const int modd=1e9+7;
   int n,m,c;
   cin>>n>>m>>c;
   int temp=f(m,c,1e9+6);
   cout<<f(n,temp,modd);
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
