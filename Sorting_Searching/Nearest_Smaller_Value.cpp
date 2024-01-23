#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n;
   cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   vector<int>ans(n);
   // using stack
   
   stack<pair<int,int>>st;
   for(int i=0;i<n;i++){
     if(st.empty()){
        st.push({v[i],i+1});
     }
     else{
        while(!st.empty() && v[i]<=st.top().first){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top().second;
        }
        st.push({v[i],i+1});
     }
   }
   
  
   for(auto it:ans){
    cout<<it<<" ";
   }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
