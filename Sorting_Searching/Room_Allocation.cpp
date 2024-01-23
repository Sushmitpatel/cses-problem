#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
bool static cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    for(int i=0;i<n;i++){
      cin>>v[i][0];
      cin>>v[i][1];
      v[i][2]=i;
    }
    sort(v.begin(),v.end());//we can sort the array in ascending as well as descending both will give correct ans
    multiset<pair<int,int>,greater<pair<int,int>>>ms;
    vector<int>room(n);
    int no=0;
    for(int i=0;i<n;i++){
        int ar=v[i][0],dept=v[i][1],indx=v[i][2];
        auto it=ms.lower_bound({ar,0});
        if(it==ms.end()){
           no++;
           ms.insert({dept,no});
           room[indx]=no;
        }
        else{
           int roomNo=it->second;
           room[indx]=roomNo;
           ms.erase(it);
           ms.insert({dept,roomNo});
        }
    }
    cout<<no<<endl;
    for(auto it:room){
        if(it){
            cout<<it<<" ";
        }
    }

   
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
