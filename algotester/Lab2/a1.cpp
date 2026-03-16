#include <iostream>
#include <vector>
using namespace std;

struct boy {
    long long time;
    long long interval;
    long long stop;
};

long long count_balloons(const vector<boy>& boys, const long long time) {
    long long total_balloons = 0;
    for (boy b: boys) {
        long long cycle_time = b.interval*b.time + b.stop;
        long long cycles = time / cycle_time;
        long long balloons = cycles * b.interval;
        long long remaining = time % cycle_time;
        if (remaining / b.time < b.interval) {
            balloons += remaining/b.time;
        }
        else {
            balloons += b.interval;
        }
        total_balloons += balloons;
    }
    return total_balloons;
}

int main() {
    long long m, n;
    cin >> m >> n;
    vector<boy> boys;
    for (int i = 0; i < n; i++) {
        long long time, interval, stop;
        cin >> time >> interval >> stop;
        boys.push_back({time, interval, stop});
    }

    long long right = 1e18;
    long long left = 0;
    while (right - left > 1) {
        long long total_balloons = 0;
        const long long mid = (right + left) / 2;
        total_balloons = count_balloons(boys, mid);
        if (total_balloons >= m) {right = mid;}
        else left = mid;
    }
    cout << right;
    return 0;
}
