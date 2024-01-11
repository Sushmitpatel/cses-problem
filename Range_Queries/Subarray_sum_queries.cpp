
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
#define INT_MIN -1e16
const int mod=1e9+7;
struct vertex{
    int sum;
    int value;
    int prefix;
    int suffix;
};
struct SegT {
    vector<vertex>segTree;
      SegT(int n){
        segTree.resize(4*n+7);
      }
    void build_tree(vector<vertex> &arr, int node, int s, int e) {
        if (e==s) {
            segTree[node] = arr[s];
            return;
        }
        int mid = (s + e) >> 1;
        build_tree(arr, 2 * node, s, mid);
        build_tree(arr, 2 * node + 1, mid + 1, e);
        segTree[node].value= (segTree[2 * node].value + segTree[2 * node + 1].value);
        segTree[node].sum=max({segTree[2*node].sum,segTree[2*node+1].sum,segTree[2*node].suffix+segTree[2*node+1].prefix});
        segTree[node].prefix= max(segTree[2 * node].prefix , segTree[2 * node + 1].prefix+segTree[2*node].value);
        segTree[node].suffix= max(segTree[2 * node+1].suffix , segTree[2 * node].suffix+segTree[2*node+1].value);
    }

    vertex query(int node, int l, int h, int s, int e) {
       if(l>e||h<s){
        return {0ll,(long long)INT_MIN};
       }  
       if(l>=s&&h<=e){
        return segTree[node];
       }
        int mid = (l + h) >> 1;
        vertex left = query(2 * node, l, mid, s, e);
        vertex right = query(2 * node + 1, mid + 1, h, s, e);
        return {left.value+right.value,max(left.prefix,left.value+right.prefix)};
    }
    void update(int node, int indx, int val, int l, int h) {
        if (l == h) {
            segTree[node].value= val;
            segTree[node].prefix= val;
            segTree[node].suffix=val;
            segTree[node].sum=val;
            return;
        }
        int mid = (l + h) >> 1;
        if (indx <= mid) {
            update(2 * node, indx, val, l, mid);
        } else {
            update(2 * node + 1, indx, val, mid + 1, h);
        }
        segTree[node].value= (segTree[2 * node].value + segTree[2 * node + 1].value);
        segTree[node].sum=max({segTree[2*node].sum,segTree[2*node+1].sum,segTree[2*node].suffix+segTree[2*node+1].prefix});
        segTree[node].prefix= max(segTree[2 * node].prefix , segTree[2 * node + 1].prefix+segTree[2*node].value);
        segTree[node].suffix= max(segTree[2 * node+1].suffix , segTree[2 * node].suffix+segTree[2*node+1].value);
    }
};
void solve() {
    int n,q;
    cin>>n>>q;
    vector<vertex>arr(n+1);
    for(int i=1;i<=n;i++){
       int x;
       cin>>x;
       arr[i].value=x;
       arr[i].prefix=x;
       arr[i].suffix=x;
       arr[i].sum=x;
    }
    SegT st(n+2);
    st.build_tree(arr,1,1,n);
    while(q--){
      int a,b;
      cin>>a>>b;
        st.update(1,a,b,1,n);
         int ans=st.segTree[1].sum;
         cout<<max(0ll,ans)<<endl;
    }

   
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //cout<<endl;
    return 0;
}
