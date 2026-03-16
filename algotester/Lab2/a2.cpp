#include <iostream>
using namespace std;

int main() {
    long long left = 1;
    long long right = 1e9;
    while (true) {
        long long mid = left + (right - left) / 2;
        cout << mid << endl;
        cout.flush();
        char answer;
        cin >> answer;
        if (answer == '=') {
            return 0;
        }
        if (answer == '<') {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
}
