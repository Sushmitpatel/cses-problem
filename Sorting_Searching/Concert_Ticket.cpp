#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
/* we can make custom comparator function*/
struct customComparator{
    bool operator()(int a,int b)const{
        return a>b;
    }
};
int getAns(vector<int>&v,int val,int &size){
    int indx=-1;
    int l=0;
    int h=size;
    while(l<=h){
      int mid=(h+l)>>1;
      if(v[mid]<=val){
        indx=mid;
        l=mid+1;
      }
      else{
        h=mid-1;
      }
    }
    int ans=-1;
    if(indx!=-1){
        ans=v[indx];
        size--;
        v.erase(v.begin()+indx);// this operation is taking O(n)time so it will giving tle
    }
    return ans;
}
void solve() {
   int n,m;
   cin>>n>>m;
   multiset<int,customComparator>st;
   vector<int>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
    st.insert(v[i]);
   }
   // using binary search (it is giving tle due to erase operation on vector)
   /* 
   sort(v.begin(),v.end());
   int size=n-1;
   while(m--){
    int num;
    cin>>num;

    cout<<getAns(v,num,size)<<endl;
   }
   */
   

   //  ********* using multiset(it will store value in decreasing order due to (greater<int>))********;
   while(m--){
    int num;
    cin>>num;
    auto it=st.lower_bound(num);// O(log n) time complexity
    if(it!=st.end()){
        cout<<*it<<endl;
        st.erase(it);
    }
    else{
        cout<<-1<<endl;
    }
   }


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //cout<<endl;
    return 0;
}

