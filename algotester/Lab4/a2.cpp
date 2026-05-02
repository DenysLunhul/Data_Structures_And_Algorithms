#include <iostream>
#include <vector>
#include <set>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> cells(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> cells[i][j];

    vector<vector<long long>> death_time(n + 1, vector<long long>(n + 1, -1));
    set<pair<int,int>> ill;
    set<pair<int,int>> dead;

    death_time[1][1] = cells[1][1];
    ill.insert({1, 1});

    while (!ill.empty()) {
        pair<int,int> p;
        long long min_t = 1000000000000000;
        for (auto cell : ill) {
            if (death_time[cell.first][cell.second] < min_t) {
                min_t = death_time[cell.first][cell.second];
                p = cell;
            }
        }
        ill.erase(p);
        if (min_t > m) continue;
        dead.insert(p);

        if (p.first-1 >= 1 && !dead.count({p.first-1, p.second}) && !ill.count({p.first-1, p.second})) {
            death_time[p.first-1][p.second] = min_t + cells[p.first-1][p.second];
            ill.insert({p.first-1, p.second});
        }
        if (p.first+1 <= n && !dead.count({p.first+1, p.second}) && !ill.count({p.first+1, p.second})) {
            death_time[p.first+1][p.second] = min_t + cells[p.first+1][p.second];
            ill.insert({p.first+1, p.second});
        }
        if (p.second-1 >= 1 && !dead.count({p.first, p.second-1}) && !ill.count({p.first, p.second-1})) {
            death_time[p.first][p.second-1] = min_t + cells[p.first][p.second-1];
            ill.insert({p.first, p.second-1});
        }
        if (p.second+1 <= n && !dead.count({p.first, p.second+1}) && !ill.count({p.first, p.second+1})) {
            death_time[p.first][p.second+1] = min_t + cells[p.first][p.second+1];
            ill.insert({p.first, p.second+1});
        }
    }

    cout << dead.size();
    return 0;
}