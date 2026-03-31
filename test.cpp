#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int min_perm(int n) {
    string num = to_string(n);
    sort(num.begin(), num.end());
    if (num[0] == '0') {
        for (int i = 1; i < num.size(); i++) {
            if (num[i] != '0') {
                swap(num[0], num[i]);
                break;
            }
        }
    }
    return stoi(num);
}

int max_perm(int n) {
    string num = to_string(n);
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    return stoi(num);
}


int main() {
    int n;
    cin >> n;
    cout << min_perm(n) << " " << max_perm(n);
    return 0;
}