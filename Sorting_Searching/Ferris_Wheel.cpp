#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n,m;
   cin>>n>>m;
   vector<int>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   /* two pointer technique:- sort the array in asscending order 
   then take two pointer at front and back and check 
   if arr[i]+arr[j]>limit then decrease the back pointer (j) otherwise
    decrease the ans and increase the front pointer and decreaset the back pointer */
   sort(v.begin(),v.end());
   int i=0,j=n-1;
   int ans=n;
   while(i<j){
     if(v[i]+v[j]>m){
        j--;
     }
     else{
        ans--;
        i++;
        j--;
     }
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
