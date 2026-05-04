#include <bits/stdc++.h>
using namespace std;

vector<int> tin, tout;
int timer = 0;


void dfs(int v, vector<vector<int>>& graph) {
    tin[v] = timer + 1;
    timer++;
    for (int u : graph[v]) {
        dfs(u, graph);
    }
    tout[v] = timer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (int i = 2; i < n + 1; i++) {
        int temp;
        cin >> temp;
        graph[temp].push_back(i);
    }

    vector<vector<int>> color(n + 1);
    for (int i = 1; i < n + 1; i++) {
        int c;
        cin >> c;
        color[c].push_back(i);
    }

    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);

    dfs(1, graph);

    for (int c = 1; c <= n; c++) {
        if (color[c].size() < 2) continue;

        sort(color[c].begin(), color[c].end(), [](int a, int b) {return tin[a] < tin[b];});

        for (int i = 0; i < color[c].size() - 1; i++) {
            int u = color[c][i];
            int v = color[c][i + 1];

            if (!(tin[u] <= tin[v] && tout[u] >= tout[v])) {
                cout << "yes" << endl;
                cout << u << " " << v << endl;
                return 0;
            }
        }
    }
    cout << "no";
    return 0;
}