#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> s(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s[i][j] = arr[i][j];
            if (i > 0) {
                s[i][j] += s[i - 1][j];
            }
            if (j > 0) {
                s[i][j] += s[i][j - 1];
            }
            if (i > 0 and j > 0) {
                s[i][j] -= s[i - 1][j - 1];
            }
        }
    }

    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;

    int summa = s[x2][y2];
    if (x1 > 0) {
        summa -= s[x1 - 1][y2];
    }
    if (y1 > 0) {
        summa -= s[x2][y1 - 1];
    }
    if (x1 > 0 and y1 > 0) {
        summa += s[x1 - 1][y1 - 1];
    }
    cout << summa;
    return 0;
}