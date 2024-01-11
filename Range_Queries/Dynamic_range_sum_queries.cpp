#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;

struct BIT{
    vector<int>bit;
    int n;
     BIT(int size){
        n=size+2;
       bit.resize(n);
       
     }
     void update(int indx,int val){
        while(indx<n){
            bit[indx]+=val;
            indx+=(indx & (-indx));
        }
     }
     int query(int indx){
        int sum=0;
         while(indx>0){
            sum+=bit[indx];
            indx-=(indx & (-indx));
         }
         return sum;
     }
     void build_bit(vector<int>&arr){
        for(int i=1;i<arr.size();i++){
           update(i,arr[i]);
        }
     }
};
void solve() {
   int n,q;
   cin>>n>>q;
   vector<int>arr(n+1);
   for(int i=1;i<=n;i++){
    cin>>arr[i];
   }
   BIT btree(n);
   btree.build_bit(arr);
   while(q--){
    int x;
    cin>>x;
    if(x==2){
       int a,b;
       cin>>a>>b;
       cout<<btree.query(b)-btree.query(a-1)<<endl;
    }
    else{
        int k,u;
        cin>>k>>u;
        int prev=arr[k];
        arr[k]=u;
        btree.update(k,u-prev);
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
