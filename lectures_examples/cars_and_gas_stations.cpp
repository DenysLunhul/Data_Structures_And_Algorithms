#include  <iostream>
#include <vector>
using namespace std;

struct PriorityQueue {
    vector<int> v;

    void push(int a) {
        v.push_back(a);
    }

    int top_pop() {
        int index = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > v[index]) {
                swap(i, index);
            }
        }
        int res = v[index];
        swap(v[index], v.back());
        v.pop_back();
        return res;
    }

    bool empty() {
        return v.empty();
    }
};

int main() {
    int N, A, D;
    cin >> N >> A >> D;
    int B[N];
    int X[N];
    for (int i = 0; i < N; i++) {
        cin >> B[i] >> X[i];
    }

    PriorityQueue pq;
    int C = 0;
    int res = 0;
    int gs = 0;

    while (C + A < D) {
        C+=A;
        while (gs < N and X[gs] <= C) {
            pq.push(B[gs++]);
        }
        if (pq.empty()) {
            res = -1;
            break;
        }
        A = pq.top_pop();
    }
    cout << res;
    return 0;
}