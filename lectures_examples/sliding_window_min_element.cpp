#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }


    deque<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() and q.back().first >= A[i]) {
            q.pop_back();
        }
        q.push_back({A[i], i});
        if (q.front().second == i - m){q.pop_front();}
        if (i >= m -1) {
            cout << q.front().first << endl;
        }
    }
    return 0;
}