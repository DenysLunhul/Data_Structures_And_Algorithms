#include <bits/stdc++.h>
using namespace std;


int getIdx(const vector<string>& names, const string &s) {
    for (int i = 0; i < names.size(); i++)
        if (names[i] == s) return i;
    return -1;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s1, s2;
    cin >> s1 >> s2;
    vector<string> names(n, "");
    vector<long long> x(n, 0);
    vector<long long> y(n, 0);


    for (int i = 0; i < n; i++)
        cin >> names[i] >> x[i] >> y[i];

    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        edges[i] = {getIdx(names, u), getIdx(names, v)};
    }

    int src = getIdx(names, s1);
    int dst = getIdx(names, s2);

    set<int> visited;
    visited.insert(src);

    bool changed = true;
    while (changed) {
        changed = false;
        for (auto e: edges) {
            if (visited.count(e.first) && !visited.count(e.second)) {
                visited.insert(e.second);
                changed = true;
            }
            if (visited.count(e.second) && !visited.count(e.first)) {
                visited.insert(e.first);
                changed = true;
            }
        }
    }
    int days = 0;
    while (!visited.count(dst)) {
        bool found = false;
        vector<int> toAdd;
        for (int i = 0; i < n; i++) {
            if (visited.count(i)) continue;
            for (int j : visited) {
                long long dx = x[i] - x[j];
                long long dy = y[i] - y[j];
                if (dx*dx + dy*dy <= (long long)k*k) {
                    toAdd.push_back(i);
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << "NO";
            return 0;
        }
        for (int i : toAdd) visited.insert(i);
        changed = true;
        while (changed) {
            changed = false;
            for (auto e: edges) {
                if (visited.count(e.first) && !visited.count(e.second)) {
                    visited.insert(e.second);
                    changed = true;
                }
                if (visited.count(e.second) && !visited.count(e.first)) {
                    visited.insert(e.first);
                    changed = true;
                }
            }
        }
        days++;
    }
    cout << "YES" << endl << days;
    return 0;
}