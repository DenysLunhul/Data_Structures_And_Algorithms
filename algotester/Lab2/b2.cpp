#include <iostream>
#include <string>
#include <cmath>
using namespace std;


pair<long long, long long> calculate_shift(long long days, string& s) {
    long long total_dx = 0;
    long long total_dy = 0;
    long long n = s.length();
    long long full = days / n;
    long long remain = days % n;
    for (char c : s) {
        if (c == 'R'){total_dx += 1;}
        if (c == 'L'){total_dx -= 1;}
        if (c == 'U'){total_dy += 1;}
        if (c == 'D'){total_dy -= 1;}
    }
    total_dx *= full;
    total_dy *= full;
    for (int i = 0; i < remain; i++) {
        if (s[i] == 'R'){total_dx += 1;}
        if (s[i] == 'L'){total_dx -= 1;}
        if (s[i] == 'U'){total_dy += 1;}
        if (s[i] == 'D'){total_dy -= 1;}
    }
    return {total_dx, total_dy};
}


bool possible_to_reach(long long days, long long x1, long long y1, long long x2, long long y2, string& s) {
    pair<long long , long long> shift = calculate_shift(days, s);
    long long new_x = x1 + shift.first;
    long long new_y = y1 + shift.second;
    long long distance = abs(new_x - x2) + abs(new_y - y2);
    return distance <= days;
}

int main() {
    long long x1, y1, x2, y2, n;
    string s;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;

    long long left = 0;
    long long right = 1e15;
    if (!possible_to_reach(right, x1, y1, x2, y2, s)) {
        cout << -1;
        return 0;
    }

    while (left + 1 < right) {
        long long mid = left + (right - left) / 2;
        if (possible_to_reach(mid, x1, y1, x2, y2, s)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    if (possible_to_reach(left, x1, y1, x2, y2, s)) {
        cout << left;
    }
    else {
        cout << right;
    }
    return 0;
}