#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cats(n, 0);
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> cats[i];
        total_sum += cats[i];
    }
    if (total_sum % 2 != 0) {
        return 0;
    }
    
}
