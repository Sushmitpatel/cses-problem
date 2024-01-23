#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
bool static cmpAsc(vector<int>&a,vector<int>&b){
    if(a[0]!=b[0]){
        return a[0]<b[0];
    }
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    return false;
    
}
bool static cmpDesc(vector<int>&a,vector<int>&b){
    if(a[0]!=b[0]){
        return a[0]>b[0];
    }
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return false;
    
}
void solve() {
   int n;
   cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    ordered_set<pair<int,int>>st;
    
    vector<int>contains(n);// it will contains one if ith segment contains atleast one other segment
    vector<int>member(n);// it will contains one if ith segment can be included inside other segment
    for(int i=0;i<n;i++){
        cin>>v[i][0];
        cin>>v[i][1];
        v[i][2]=i;
    }

    sort(v.begin(),v.end(),cmpAsc);// sort all segment in asending order and if first element is same then sort them in descending order so that (1,13) come before (1,9)
    
    for(int i=0;i<n;i++){
       st.insert({v[i][1],-1*i});
       
        member[v[i][2]]=st.size()-st.order_of_key({v[i][1],-i*1})-1;
      
    }
    



    /*i am sorting the v two times but this question can be solved the array by sorting only once 
    how:- we can start traversing in reverse order(n to 1) instead of traversing in forward direction (1 to n);
    */



    sort(v.begin(),v.end(),cmpDesc);// sort all segment in descending order and if first element is same then sort them in ascending order so that (1,13) come after (1,9)

    st.clear();
    for(int i=0;i<n;i++){
        st.insert({v[i][1],1*i});
        contains[v[i][2]]=st.order_of_key({v[i][1],i*1});// it will give index of v[i][1] number in the tree indexing will be zero based
     
    }
    for(auto it:contains){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:member){
        cout<<it<<" ";
    }
    //cout<<endl;
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}