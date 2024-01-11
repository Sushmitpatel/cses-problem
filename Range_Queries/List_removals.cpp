#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod=1e9+7;
struct vertex{
    int value;
    int index;
    int sum=0;
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
        segTree[node].sum = (segTree[2 * node].sum + segTree[2 * node + 1].sum);
    }

    int query(int node, int l, int h, int s, int e) {
        if (l > e || h < s)
            return 0;
        if (l >= s && h <= e)
            return segTree[node].value;
        int mid = (l + h) >> 1;
        int left = query(2 * node, l, mid, s, e);
        int right = query(2 * node + 1, mid + 1, h, s, e);
        return max(left , right);
    }
     vertex getVertex(int node,int val,int l,int h){
        if(l==h){
            return segTree[node];
        }
        int mid=(l+h)>>1;
        if(segTree[2*node].sum>=val){
            return getVertex(2*node,val,l,mid);
        }
        else{
            int temp=segTree[2*node].sum;
            return getVertex(2*node+1,val-temp,mid+1,h);
        }
           
        
     }
    void update(int node, int indx, int val, int l, int h) {
        if (l == h) {
            segTree[node].sum += val;
            return;
        }
        int mid = (l + h) >> 1;
        if (indx <= mid) {
            update(2 * node, indx, val, l, mid);
        } else {
            update(2 * node + 1, indx, val, mid + 1, h);
        }
        segTree[node].sum = (segTree[2 * node].sum + segTree[2 * node + 1].sum);
    }
};
void solve() {
 int n;
 cin>>n;
 vector<vertex>arr(n+1);
 for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    arr[i].value=x;
    arr[i].index=i;
    arr[i].sum=1;
 }  
 SegT st(n+2);
 st.build_tree(arr,1,1,n);
 int q=n;
 while(q--){
   int x;
   cin>>x;
   vertex ans=st.getVertex(1,x,1,n);
    cout<<ans.value<<" ";
    st.update(1,ans.index,-1,1,n);
 }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}
