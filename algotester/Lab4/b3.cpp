#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<set<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int center = 1;
    for (int i = 2; i <= n; i++)
        if (adj[i].size() > adj[center].size()) {
            center = i;
        }
    vector<tuple<int,int,int>> moves;

    bool changed = true;
    while (changed) {
        changed = false;
        vector<int> parent(n + 1, -1);
        vector<int> depth(n + 1, -1);
        vector<vector<int>> layers(n);
        queue<int> q;
        depth[center] = 0;
        q.push(center);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            layers[depth[v]].push_back(v);
            for (int u : adj[v]) {
                if (depth[u] == -1) {
                    depth[u] = depth[v] + 1;
                    parent[u] = v;
                    q.push(u);
                }
            }
        }


        if (!layers[2].empty()) {
            int z = layers[2][0];
            int y = parent[z];
            int x = center;
            adj[y].erase(z);
            adj[z].erase(y);
            adj[x].insert(z);
            adj[z].insert(x);
            moves.push_back({x, y, z});
            changed = true;
        }

    }

    cout << moves.size() << endl;
    for (auto [x, y, z] : moves)
        cout << x << " " << y << " " << z << endl;
    return 0;
}