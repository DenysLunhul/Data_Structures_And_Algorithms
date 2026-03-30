#include <iostream>
#include <vector>
#include <set>
using namespace std;

int bfs(vector<vector<bool>>& graph, set<long long> passed, long long target) {
    int res = 0;
    int n = graph[0].size();
    for (long long i : passed) {
        for (long long j = 1; j <= n; j++) {
            if (!passed.count(j) and graph[i][j] and i != j) {
                passed.insert(j);
                if (j == target) {
                    passed.erase(j);
                    res ++;
                }
            }
        }
    }
    if (res != 0) {
        return res;
    }
    else {
        if (passed.size() == n) {
            return 0;
        }
        return bfs(graph, passed, target);
    }
}

int main() {
    long long n, m;
    long long a, b;
    cin >> n >> m >> a >> b;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    for (long long i = 0; i < m; i++) {
        long long s, f;
        cin >> s >> f;
        graph[s][f] = true;
        graph[f][s] = true;
    }
    cout << bfs(graph, {a}, b);
    return 0;
}