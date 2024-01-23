#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;

void solve() {
   int n,m;
   cin>>n>>m;
   set<int>s;// storing the position where traffic lights are present
   multiset<int>ms;// for storing the length of all segments
   ms.insert(n);
   s.insert(0);
   s.insert(n);
   for(int i=0;i<m;i++){
      int x;
      cin>>x;
      s.insert(x);
      auto it=s.find(x);// insert new traffic light
      int nxt=*next(it);// find the  next traffic light position to new inserted light 
      int prv=*prev(it);// find previous traffic light position to new inserted light
      ms.erase(ms.find(nxt-prv));// while new traffic light is inserting then erase the previous segment that will not present in future
      ms.insert(nxt-x);//insert new created segments
      ms.insert(x-prv);//insert new created segments
      cout<<*ms.rbegin()<<" ";
   }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
