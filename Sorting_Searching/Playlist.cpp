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
   map<int,int>mp;
   int ans=0;
  /* 
    // using sliding window

  int i=0,j=0;
   
   while(i<n){
   mp[v[i]]++;
    if(mp.size()==(i-j+1)){
        ans=max(ans,i-j+1);
    }
    else{
        if(mp[v[j]]==1)mp.erase(v[j]);
        else{
            mp[v[j]]--;
        }
        j++;
        if(mp.size()==(i-j+1)){
        ans=max(ans,i-j+1);
          }
    }
    i++;
   }*/



   /*  gfg solution */
    for (int i = 0, j = 0; i < n; i++) { 
  
        // Update j based on previous 
        // occurrence of a[i] 
        j = max(mp[v[i]], j); 
  
        // Update ans to store maximum 
        // length of subarray 
        ans = max(ans, i - j + 1); 
  
        // Store the index of current 
        // occurrence of a[i] 
        mp[v[i]] = i + 1; 
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
