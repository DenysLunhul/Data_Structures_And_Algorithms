#include <iostream>
#include <vector>
using namespace std;
#define INF 100000000

void update(vector<int>& tree, int index, int val, int n) {
    index += n;
    tree[index] = val;
    while (index > 1) {
        index /= 2;
        tree[index] = max(tree[index*2], tree[index*2 + 1]);
    }
}

int Max(const vector<int>& tree, int n, int l, int r) {
    l += n; r += n;
    if (l == r){return tree[l];}
    int res = max(tree[l], tree[r]);
    while (l + 1 < r) {
        if (l % 2 == 0){res = max(res, tree[l + 1]);}
        if (r % 2 == 1){res = max(res, tree[r - 1]);}
        l /= 2;
        r /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> tree(n * 2, -INF);
    for (int i = 0; i < n; i++) {
        cin >> tree[i + n];
    }
    for (int i = n - 1; i >= 1; i--) {
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
    int l, r;
    cin >> l >> r;
    cout << Max(tree, n, l, r) << "\n";
    return 0;
}