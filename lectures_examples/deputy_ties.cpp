#include <iostream>
#include <vector>
using namespace std;


bool possible_to_divide(int x, const vector<double>& lengths, const double& mid) {
    int counter = 0;
    for (double length : lengths) {
        counter += (int)(length / mid);
    }
    return counter >= x;
}


int main() {
    int ties, n;
    cin >> ties >> n;
    vector<double> lengths(ties, 0);
    double max = 0;
    for (int i = 0 ; i < ties; i++) {
        cin >> lengths[i];
        if (lengths[i] > max) max = lengths[i];
    }
    double left = 0;
    double right = max + 1;
    while (right - left > 1e-4) {
        double mid = (left + right) / 2;
        if (possible_to_divide(n, lengths, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left;
    return 0;
}