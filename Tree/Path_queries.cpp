#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX 1e16
const int mod = 1e9 + 7;
const int N = 1e6 + 7;

map<int, int> mp;
vector<int> arr(N);
vector<int> intime(N);
vector<int> entime(N);
vector<int> segTree(4*N);
struct SegT {
    void build_tree(vector<int> &arr, int node, int s, int e) {
        if (e==s) {
            segTree[node] = arr[s];
            return;
        }
        int mid = (s + e) >> 1;
        build_tree(arr, 2 * node, s, mid);
        build_tree(arr, 2 * node + 1, mid + 1, e);
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }

    int query(int node, int l, int h, int s, int e) {
        if (l > e || h < s)
            return 0;
        if (l >= s && h <= e)
            return segTree[node];
        int mid = (l + h) >> 1;
        int left = query(2 * node, l, mid, s, e);
        int right = query(2 * node + 1, mid + 1, h, s, e);
        return left + right;
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
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
};

int tim = 1;

void dfs(int node, vector<vector<int>> &adj, int par) {
    intime[node] = tim;
    arr[tim++] = mp[node];
    for (auto it : adj[node]) {
        if (it == par)
            continue;
        dfs(it, adj, node);
    }
    entime[node] = tim;
    arr[tim++] = -mp[node];
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(N);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[i] = x;
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, adj, -1);

    SegT sg;
    sg.build_tree(arr, 1, 1, 2 * n +1);
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int node, y;
            cin >> node >> y;
            int left = intime[node];
            int right = entime[node];
            int prev = arr[left];
            arr[left]=y;
            arr[right]=-y;
            //cout<<left<<" "<<right<<endl;
            sg.update(1, left, y, 1, 2 * n + 1);
            sg.update(1, right, -(y), 1, 2 * n + 1);
        } else {
            int node;
            cin >> node;
            int left = intime[1];
            int right = intime[node];
            cout << sg.query(1, 1, 2 * n + 1, left, right) << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
