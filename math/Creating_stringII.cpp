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
  string s;
  cin>>s;
  int n=s.length();
  int arr[26]={0};
  for(int i=0;i<s.length();i++){
    arr[s[i]-'a']++;
  }
  int ans=fact[n];
  for(int i=0;i<26;i++){
    if(arr[i]==0||arr[i]==1)continue;
  ans=((ans*modularExponential(fact[arr[i]],mod-2)))%mod;
  }
    
  cout<<ans;
}

int32_t main() {
    fact.resize(1e6+7);
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=1e6;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    
   solve();
    cout<<endl;
    
   
    return 0;
}
