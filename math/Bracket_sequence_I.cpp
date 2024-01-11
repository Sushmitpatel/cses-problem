/* answer will be equal to CATALAN NUMBER= (1/(k+1))*(combination(2k,k))*/
// where k=n/2;

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
 int n;
 cin>>n;
 if(n&1){cout<<"0";return ;}
  int ans=((fact[n]*modularExponential(fact[n/2],mod-2)))%mod;
  ans=(ans*(modularExponential(fact[n/2],mod-2)))%mod;
  ans=(ans*(modularExponential(n/2+1,mod-2)))%mod;
  cout<<ans;
}

int32_t main() {
    fact.resize(1e7);
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=1e7;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
   solve();
    cout<<endl;
    
   
    return 0;
}
