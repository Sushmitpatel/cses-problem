#include<bits/stdc++.h>
using namespace std;
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
    
}
bool static cmpDesc(vector<int>&a,vector<int>&b){
    if(a[0]!=b[0]){
        return a[0]>b[0];
    }
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    
}
void solve() {
   int n;
   cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    multiset<int>rhs;
    vector<int>contains(n);// it will contains one if ith segment contains atleast one other segment
    vector<int>member(n);// it will contains one if ith segment can be included inside other segment
    for(int i=0;i<n;i++){
        cin>>v[i][0];
        cin>>v[i][1];
        v[i][2]=i;
    }

    sort(v.begin(),v.end(),cmpAsc);// sort all segment in asending order and if first element is same then sort them in descending order so that (1,13) come before (1,9)
    rhs.insert(v[0][1]);
    for(int i=1;i<n;i++){
      auto it=rhs.lower_bound(v[i][1]);
      if(it!=rhs.end()){
        member[v[i][2]]=1;
      }
      rhs.insert(v[i][1]);
    }
    multiset<int,greater<int>>Rrhs;



    /*i am sorting the v two times but this question can be solved the array by sorting only once 
    how:- we can start traversing in reverse order(n to 1) instead of traversing in forward direction (1 to n);
    */



    sort(v.begin(),v.end(),cmpDesc);// sort all segment in descending order and if first element is same then sort them in ascending order so that (1,13) come after (1,9)

    Rrhs.insert(v[0][1]);
    for(int i=1;i<n;i++){
      auto it=Rrhs.lower_bound(v[i][1]);
      if(it!=Rrhs.end()){
        contains[v[i][2]]=1;
      }
      Rrhs.insert(v[i][1]);
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
