#include <iostream>
#include <vector>
using namespace std;


long long bfs(int v, int b, vector<vector<int>>& graph, vector<int>& mem, int n) {
    if (v == b) {
        return 1;
    }
    if (mem[v] != -1) {
        return mem[v];
    }

    long long res = 0;
    for (int i: graph[v]) {
        res += bfs(i, b, graph, mem, n);
    }
    res %= 1234567891;
    mem[v] = res;
    return res;
}


int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    vector<int> mem(n + 1, -1);
    cout << bfs(a, b, graph, mem, n);
    return 0;
}