#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
const int N=2*1e5+7;
struct SegT {
    vector<int>segTree;
      SegT(int n){
        segTree.resize(4*n+7);
      }
    void build_tree(vector<int> &arr, int node, int s, int e) {
        if (e==s) {
            segTree[node] = arr[s];
            return;
        }
        int mid = (s + e) >> 1;
        build_tree(arr, 2 * node, s, mid);
        build_tree(arr, 2 * node + 1, mid + 1, e);
        segTree[node] = (segTree[2 * node]^segTree[2 * node + 1]);
    }

    int query(int node, int l, int h, int s, int e) {
        if (l > e || h < s)
            return 0;
        if (l >= s && h <= e)
            return segTree[node];
        int mid = (l + h) >> 1;
        int left = query(2 * node, l, mid, s, e);
        int right = query(2 * node + 1, mid + 1, h, s, e);
        return (left^right);
    }

    void update(int node, int indx, int val, int l, int h) {
        if (l == h) {
            segTree[node] = val;
            return;
        }
        int mid = (l + h) >> 1;
        if (indx <= mid) {
            update(2 * node, indx, val, l, mid);
        } else {
            update(2 * node + 1, indx, val, mid + 1, h);
        }
        segTree[node] = (segTree[2 * node]^segTree[2 * node + 1]);
    }
};
void solve() {
   int n,q;
   cin>>n>>q;
   vector<int>arr(n+1);
   for(int i=1;i<=n;i++){
    cin>>arr[i];
   }
   SegT st(n);
   st.build_tree(arr,1,1,n);
   while(q--){
    
        int a,b;
        cin>>a>>b;
        cout<<st.query(1,1,n,a,b)<<endl;
    
   }

   
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //cout<<endl;
    return 0;
}
