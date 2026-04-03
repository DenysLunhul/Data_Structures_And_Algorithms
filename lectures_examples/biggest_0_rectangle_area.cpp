#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> B(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) {
                B[i][j] = 0;
            }
            else {
                B[i][j] = 1;
                if (i > 0) {
                    B[i][j] += B[i - 1][j];
                }
            }
        }
    }


    //0(n ^ 3)
    int res = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int x2 = 0; x2 < n; x2++) {
            int cnt = 0;
            for (int y = 0; y < n; y++) {
                if (B[x2][y] >= x2 - x1 + 1) cnt++;
                else {
                    res = max(res, cnt * (x2 - x1 + 1));
                    cnt = 0;
                }
            }
            res = max(res, cnt * (x2 - x1 + 1));
        }
    }


    //O(n ^ 2)
    res = 0;
    for (int x = 0; x < n; x++) {
        stack<pair<int, int>> s;

        for (int y = 0; y < n; y++) {
            int index = y;
            while (!s.empty() and s.top().first >= B[x][y]) {
                res = max(res, s.top().first * (y - s.top().second));
                index = s.top().second;
                s.pop();
            }
            s.push({B[x][y], index});
        }
        while (!s.empty()) {
            res = max(res, s.top().first * (n - s.top().second));
            s.pop();
        }
    }

    cout << res;
    return 0;
}