#include <iostream>
#include <vector>
#include <set>
using namespace std;


int longest_subsequence(int n, vector<long long>& seq) {
    int result = 0;
    set<int> S;
    for (int i = 0; i < n; i++) {
        if (!S.count(seq[i])) {
            S.insert(seq[i]);
        }
        else {
            S.clear();
            result++;
        }
    }
    return result*2;
}


int main() {
    int n;
    cin >> n;
    vector<long long> seq(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    cout << longest_subsequence(n, seq);
    return 0;
}
