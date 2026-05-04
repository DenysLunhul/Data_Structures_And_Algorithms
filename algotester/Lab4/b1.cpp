#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void dfs(int u, int p, int d, const vector<vector<int>>& adj, vector<ll>& sz, vector<ll>& depth, ll& total_depth) {
    depth[u] = d;
    total_depth += d;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1, adj, sz, depth, total_depth);
            sz[u] += sz[v];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<ll> sz(n + 1, 0);
    vector<ll> depth(n + 1, 0);
    ll total_depth = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0, adj, sz, depth, total_depth);
    ll min_total_depth = total_depth;
    for (int u = 2; u <= n; ++u) {
        ll current_change = sz[u] * (1 - depth[u]);
        min_total_depth = min(min_total_depth, total_depth + current_change);
    }
    cout << min_total_depth << endl;
    return 0;
}
