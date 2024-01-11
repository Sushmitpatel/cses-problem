#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
vector<int>fact;
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
   int n,m;
   cin>>n>>m;
   int ans=(((fact[n]*modularExponential(fact[m],mod-2))%mod)*modularExponential(fact[n-m],mod-2))%mod;
  cout<<ans;
}

int32_t main() {
    fact.resize(1e6+7);
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=1e6;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    int t;
    cin>>t;
    while(t--){
   solve();
    cout<<endl;
    }
   
    return 0;
}
