#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
int f(int n,int m){
    if(n==1)return 1;
    if(m<=(n+1)/2){
        if(n>=2*m)return 2*m;
        else
        return (2*m)%n;
    }
    int temp=f(n/2,m-(n+1)/2);
    if(n&1)return 2*temp+1;
    return 2*temp-1;
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
