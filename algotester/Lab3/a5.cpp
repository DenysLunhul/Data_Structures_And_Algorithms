#include <iostream>
#include <vector>
using namespace std;

int trace_jumps(vector<int>& a, vector<int>& b, vector<int>& mem, int n) {
    int res = 0;
    int ind = 0;
    for (int i = 1; i <= n; i++) {
        mem[i] = 1 + max(mem[i - a[i]], mem[i - b[i]]);
        if (mem[i] >= res) {
            res = mem[i];
            ind = i;
        }
    }
    return ind;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    vector<int> mem(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    cout << trace_jumps(a, b, mem, n);
    return 0;
}