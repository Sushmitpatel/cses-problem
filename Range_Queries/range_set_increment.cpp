// range update sum problem
// lazy propagation based question
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
#define INT_MIN -1e16
const int mod=1e9+7;
struct vertex{
    int value=0;
    int increment=0;
    int setAll=0;
    bool setAllValid=false;
};
struct SegT {
    vector<vertex>segTree;
      SegT(int n){
        segTree.resize(4*n+7);
      }
      void propagate(int node,int l,int r){
        if(segTree[node].setAllValid){
            segTree[node].value=(r-l+1)*segTree[node].setAll;
        }
        segTree[node].value+=(r-l+1)*segTree[node].increment;
        if(l!=r){
            compose(node,2*node);
           compose(node,2*node+1);
           
        }
        segTree[node].increment=0;
        segTree[node].setAll=0;
        segTree[node].setAllValid=0;
      }
      void compose(int node,int child){
         if(segTree[node].setAllValid){
            segTree[child].setAll=segTree[node].setAll;
            segTree[child].setAllValid=1;
            segTree[child].increment=segTree[node].increment;
         }
         else{
            segTree[child].increment+=segTree[node].increment;
         }
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
    }

    int query(int node, int l, int h, int s, int e) {
        
       if(l>e||h<s){
        return 0ll;
       }  
        propagate(node,l,h);
       if(l>=s &&  h <=e){
        return segTree[node].value;
       }
        int mid = (l + h) >> 1;
        int left = query(2 * node, l, mid, s, e);
        int right = query(2 * node + 1, mid + 1, h, s, e);
       
        return left+right;
    }
    void inc_update(int node, int sindx,int eindx, int val, int l, int h) {
        propagate(node,l,h);// during update we will have to propagate while we are out of range, because of we need to update parent node that will have data(updated left child data + updated right child data);
        if(l>eindx||h<sindx)return;
        
        if (sindx<=l && eindx>=h) {
            segTree[node].increment+=val;
            propagate(node,l,h);
            return;
        }
        
        int mid = (l + h) >> 1;
            inc_update(2 * node, sindx,eindx, val, l, mid);
            inc_update(2 * node + 1, sindx,eindx, val, mid + 1, h);
            
        segTree[node].value= (segTree[2 * node].value + segTree[2 * node + 1].value);
    }
     void set_update(int node, int sindx,int eindx, int val, int l, int h) {
        propagate(node,l,h);
        if(l>eindx||h<sindx)return;
        
        if (sindx<=l && eindx>=h) {
            segTree[node].setAll=val;
            segTree[node].setAllValid=1;
            segTree[node].increment=0;
            propagate(node,l,h);
            return;
        }
       
        int mid = (l + h) >> 1;
            set_update(2 * node, sindx,eindx, val, l, mid);
            set_update(2 * node + 1, sindx,eindx, val, mid + 1, h);

        segTree[node].value= (segTree[2 * node].value + segTree[2 * node + 1].value);  
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
    }
    SegT st(n+2);
    st.build_tree(arr,1,1,n);
    
    while(q--){
      int x,a,b;
      cin>>x;
      cin>>a>>b;
      if(x==1){
        int val;
        cin>>val;
        st.inc_update(1,a,b,val,1,n);
        
      }
      else if(x==2){
        int val;
        cin>>val;
        st.set_update(1,a,b,val,1,n);
      }
      else{
         int ans=st.query(1,1,n,a,b);
        //  for(int i=1;i<4*n;i++){
        //     cout<<st.segTree[i].value<<" ";
        // }
        // cout<<endl;
         cout<<ans<<endl;
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
