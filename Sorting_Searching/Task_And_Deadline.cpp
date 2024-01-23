#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
int n;
cin>>n;
vector<int>v(n);
int ans=0;
for(int i=0;i<n;i++){
    cin>>v[i];
    int x;
    cin>>x;
    ans+=x;
}
// logic is very simple 
// let (a1,x1),(a2,x2),(a3,x3) are pairs 
// then ans=(a1-x1)+(a2-x1-x2)+(a3-x1-x2-x3)=(a1+a2+a3)-(3*x1+2*x2+x3)
// so we need to minimize the second portion 
sort(v.begin(),v.end());

for(int i=0;i<n;i++){
    ans-=((n-i)*v[i]);
}
cout<<ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
