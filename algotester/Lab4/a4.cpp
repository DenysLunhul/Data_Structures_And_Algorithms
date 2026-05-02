#include <bits/stdc++.h>
using namespace std;

int n, m, timer_val = 0;
vector<string> grid;
vector<vector<vector<pair<pair<int, int>, int>>>> adj;
vector<vector<int>> tin, low, par_edge;
vector<vector<pair<int, int>>> par;
vector<bool> is_bridge;

void dfs(int r, int c, int edge_id = -1) {
    tin[r][c] = low[r][c] = ++timer_val;

    for (auto& edge : adj[r][c]) {
        int nr = edge.first.first;
        int nc = edge.first.second;
        int id = edge.second;

        if (id == edge_id) continue;
        if (tin[nr][nc] != 0) {
            low[r][c] = min(low[r][c], tin[nr][nc]);
        } else {
            par[nr][nc] = {r, c};
            par_edge[nr][nc] = id;
            dfs(nr, nc, id);
            low[r][c] = min(low[r][c], low[nr][nc]);
            if (low[nr][nc] > tin[r][c]) {
                is_bridge[id] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    if (grid[0][0] == 'X' || grid[n - 1][m - 1] == 'X') {
        cout << "ZERO";
        return 0;
    }

    adj.assign(n, vector<vector<pair<pair<int, int>, int>>>(m));
    tin.assign(n, vector<int>(m, 0));
    low.assign(n, vector<int>(m, 0));
    par.assign(n, vector<pair<int, int>>(m, {-1, -1}));
    par_edge.assign(n, vector<int>(m, -1));

    int E_count = 0;
    int dr[] = {1, 0};
    int dc[] = {0, 1};

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 'X') continue;
            for (int d = 0; d < 2; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < n && nc < m && grid[nr][nc] == '.') {
                    adj[r][c].push_back({{nr, nc}, E_count});
                    adj[nr][nc].push_back({{r , c}, E_count});
                    E_count++;
                }
            }
        }
    }

    is_bridge.assign(E_count, false);
    dfs(0, 0);

    if (tin[n - 1][m - 1] == 0) {
        cout << "ZERO";
        return 0;
    }

    pair<int, int> curr = {n - 1, m - 1};
    while (curr.first != 0 || curr.second != 0) {
        int r = curr.first;
        int c = curr.second;
        if (!is_bridge[par_edge[r][c]]) {
            cout << "MANY";
            return 0;
        }
        curr = par[r][c];
    }
    cout << "ONE";
    return 0;
}