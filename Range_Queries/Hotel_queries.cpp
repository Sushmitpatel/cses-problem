// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define INT_MAX 1e16
// const int mod=1e9+7;
// struct SegT {
//     vector<int>segTree;
//       SegT(int n){
//         segTree.resize(4*n+7);
//       }
//     void build_tree(vector<int> &arr, int node, int s, int e) {
//         if (e==s) {
//             segTree[node] = arr[s];
//             return;
//         }
//         int mid = (s + e) >> 1;
//         build_tree(arr, 2 * node, s, mid);
//         build_tree(arr, 2 * node + 1, mid + 1, e);
//         segTree[node] = max(segTree[2 * node] , segTree[2 * node + 1]);
//     }

//     int query(int node, int l, int h, int s, int e) {
//         if (l > e || h < s)
//             return 0;
//         if (l >= s && h <= e)
//             return segTree[node];
//         int mid = (l + h) >> 1;
//         int left = query(2 * node, l, mid, s, e);
//         int right = query(2 * node + 1, mid + 1, h, s, e);
//         return max(left , right);
//     }
//      int getIndx(int node,int val,int l,int h){
//         if(segTree[node]<val)return 0;
//         if(l==h){
//             return l;
//         }
//         int mid=(l+h)>>1;
//         if(segTree[2*node]>=val){
//             return getIndx(2*node,val,l,mid);
//         }
//         else if(segTree[2*node+1]>=val){
//             return getIndx(2*node+1,val,mid+1,h);
//         }
        
//             return 0;
        
//      }
//     void update(int node, int indx, int val, int l, int h) {
//         if (l == h) {
//             segTree[node] += val;
//             return;
//         }
//         int mid = (l + h) >> 1;
//         if (indx <= mid) {
//             update(2 * node, indx, val, l, mid);
//         } else {
//             update(2 * node + 1, indx, val, mid + 1, h);
//         }
//         segTree[node] = max(segTree[2 * node] , segTree[2 * node + 1]);
//     }
// };
// void solve() {
//  int n,q;
//  cin>>n>>q;
//  vector<int>arr(n+1);
//  for(int i=1;i<=n;i++){
//     cin>>arr[i];
//  }  
//  SegT st(n+2);
//  st.build_tree(arr,1,1,n);
//  while(q--){
//    int x;
//    cin>>x;
//    int ans=st.getIndx(1,x,1,n);
//    if(ans>0){
//     cout<<ans<<" ";
//     st.update(1,ans,-x,1,n);
//    }
//    else{
//     cout<<ans<<" ";
//    }
//  }
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     solve();
//     cout<<endl;
//     return 0;
// }

