#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ticket(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ticket[i][j];
        }
    }
    int minimal_maximum_of_col = 0;
    for (int i = 0; i < m; i++) {
        int col_max = 0;
        for (int j = 0; j < n; j++) {
            if (ticket[j][i] > col_max) {
                col_max = ticket[j][i];
            }
        }
        if (i == 0) {
            minimal_maximum_of_col = col_max;
        }
        if (col_max < minimal_maximum_of_col) {
            minimal_maximum_of_col = col_max;
        }
        col_max = 0;
    }
    cout << minimal_maximum_of_col;
    return 0;
}