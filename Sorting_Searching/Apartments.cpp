#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n,m,k;
   cin>>n>>m>>k;
   vector<int>apt(m);
   vector<int>appl(n);
   for(int i=0;i<n;i++){
    cin>>appl[i];
   }
   for(int j=0;j<m;j++){
    cin>>apt[j];
   }
   /* using multiset */

   /*
   multiset<int>st;
   for(int j=0;j<m;j++){
    st.insert(apt[j]);
   }
   sort(appl.begin(),appl.end());
   int ans=0;
   for(int i=0;i<n;i++){
      auto it=st.lower_bound(appl[i]-k);
      if(it!=st.end()){
        if(*it<=appl[i]+k){
           ans++;
        st.erase(it);
        }
        
      }
   }
   cout<<ans;*/



   /* using two pointer technique */
  // sort the arrays in asscending order
   /* if appartment size is greater than (applicant required size +k) then increase the upper pointer 
   if appartment size is less than (applicant desired size -k )then increase the lower pointer 
   otherwise increase the count and increase the both pointer */
   sort(appl.begin(),appl.end());
   sort(apt.begin(),apt.end());
   int i=0,j=0;
   int ans=0;
   while(i<n&&j<m){
    if(apt[j]>=appl[i]-k){
        if(apt[j]<=appl[i]+k){
            ans++;
            i++,j++;
        }
        else{
           i++;
        }
    }
    else{
        j++;
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
