/* using segment tree it is giving tle because of query time complexity can go to O(n)*/

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define INT_MAX 1e16
// const int mod=1e9+7;
// struct vertex{
//     int value;
//     int mx;
//     int mn;
//     int emp=0;
// };
// struct SegT {
//     vector<vertex>segTree;
//       SegT(int n){
//         segTree.resize(4*n+7);
//       }
//     void build_tree(vector<vertex> &arr, int node, int s, int e) {
//         if (e==s) {
//             segTree[node] = arr[s];
//             return;
//         }
//         int mid = (s + e) >> 1;
//         build_tree(arr, 2 * node, s, mid);
//         build_tree(arr, 2 * node + 1, mid + 1, e);
//         segTree[node].mx= max(segTree[2 * node].mx , segTree[2 * node + 1].mx);
//         segTree[node].mn= min(segTree[2 * node].mn , segTree[2 * node + 1].mn);
//         segTree[node].emp=segTree[2*node].emp+segTree[2*node+1].emp;
//     }

//     int query(int node, int l, int h, int s, int e) {
//         int minSal=segTree[node].mn;
//         int maxSal=segTree[node].mx;
//         int empCount=segTree[node].emp;
//         if (maxSal<s||minSal>e){
//             return 0;
//         }
//         if (s<=minSal && maxSal<=e){
//            return empCount;
//         }
            
//         int mid = (l + h) >> 1;
//         int left = query(2 * node, l, mid, s, e);
//         int right = query(2 * node + 1, mid + 1, h, s, e);
//         return left+right;
//     }
//     void update(int node, int indx, int val, int l, int h) {
//         if (l == h) {
//             segTree[node].value= val;
//             segTree[node].mn= val;
//             segTree[node].mx= val;
//             return;
//         }
//         int mid = (l + h) >> 1;
//         if (indx <= mid) {
//             update(2 * node, indx, val, l, mid);
//         } else {
//             update(2 * node + 1, indx, val, mid + 1, h);
//         }
//         segTree[node].mx = max(segTree[2 * node].mx , segTree[2 * node + 1].mx);
//         segTree[node].mn = min(segTree[2 * node].mn , segTree[2 * node + 1].mn);
//     }
// };
// void solve() {
//  int n,q;
//  scanf("%lld %lld", &n, &q);
//  vector<vertex>arr(n+1);
//  for(int i=1;i<=n;i++){
//     int x;
//     scanf("%lld", &x);
//     arr[i].value=x;
//     arr[i].mx=x;
//     arr[i].mn=x;
//     arr[i].emp=1;
    
//  }  
//  SegT st(n+2);
//  st.build_tree(arr,1,1,n);
//  while(q--){
//    char x;
//    scanf(" %c", &x);
//    if(x=='?'){
//     int a,b;
//     scanf("%lld %lld", &a, &b);
//     printf("%lld\n", st.query(1,1,n,a,b));
//    }
//    else{
//     int a,b;
//     scanf("%lld %lld", &a, &b);
//     st.update(1,a,b,1,n);
//    }
//  }
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     solve();
//     return 0;
// }




/*--------------------------    using ordered_set        --------------------*/
// #include <bits/stdc++.h>
// using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
// #define INT_MAX 1e16
// const int mod=1e9+7;

// void solve() {
//    int n,q;
//    cin>>n>>q;
//    ordered_set<pair<int,int>>os;
//    vector<int>arr(n+1);
//    for(int i=1;i<n+1;i++){
//     cin>>arr[i];
//     os.insert({arr[i],i});
//    }
//    while(q--){
//     char c;
//     cin>>c;
//     int a,b;
//     cin>>a>>b;
//     if(c=='!'){
//    os.erase({arr[a],a});
//    arr[a]=b;
//    os.insert({arr[a],a});
//     }
//     else{
//       cout<<os.order_of_key({b,mod})-os.order_of_key({a-1,mod})<<endl;
//     }
//    }
// }
