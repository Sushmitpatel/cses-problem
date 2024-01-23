#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

// approach
/* simply we are building the bucket 
and assigning the value it bucket is not exist then build a bucket and increase the count 
and if bucket exists then update the condition to assign the box*/
void solve() {
   int n;
   cin>>n;
   vector<int>v(n);
   int ans=0;
   multiset<int>st;
for(int i=0;i<n;i++){
    cin>>v[i];
    auto it= st.upper_bound(v[i]);
    if(it==st.end())ans++;
    else{
        st.erase(it);
    }
    st.insert(v[i]);
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
