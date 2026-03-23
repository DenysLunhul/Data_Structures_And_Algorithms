#include <iostream>
#include <vector>
using namespace std;

void update(vector<int>& tree, int index, int val, int n) {
    index += n;
    tree[index] = val;
    while (index > 1) {
        index /= 2;
        tree[index] = tree[index * 2] + tree[index * 2 + 1];
    }
}

int Sum(const vector<int>& tree, int n, int l, int r) {
    l += n; r += n;
    if (l == r){return tree[l];}
    int res = max(tree[l], tree[r]);
    while (l + 1 < r) {
        if (l % 2 == 0){res += tree[l + 1];}
        if (r % 2 == 1){res += tree[r - 1];}
        l /= 2;
        r /= 2;
    }
    return res;
}

int find(const vector<int>& tree, int s, int index, int n) {
    if (index >= n) {
        int res = index - n;
        if (tree[index] <= s){res++;}
        return res;
    }
    if (tree[index*2] >= s) {
        return find(tree, s, index * 2, n);
    }
    return find(tree,  s - tree[index*2], index*2 + 1, n);
}

int main() {
    int n;
    cin >> n;
    vector<int> tree(n * 2, 0);
    for (int i = 0; i < n; i++) {
        cin >> tree[i + n];
    }
    for (int i = n - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    int l, r;
    cin >> l >> r;
    cout << find(tree, 15, 0, n) << "\n";
    return 0;
}
