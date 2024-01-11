/*This is a standard problem of finding derangements in a sequence.
The recursive formula is D(n)=(D(n−1)+D(n−2))(n−1)*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
    int n;
    cin>>n;
    vector<int>ans(n+1);
    ans[0]=1;
    ans[1]=0;
    for(int i=2;i<=n;i++){
        ans[i]=((ans[i-1]+ans[i-2])*(i-1))%mod;
    }
    cout<<ans[n];
}

int32_t main() {
   
    solve();
    cout<<endl;
    return 0;
}
