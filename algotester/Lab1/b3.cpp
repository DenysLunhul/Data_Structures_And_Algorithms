#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double calculate_distance(int x1, int y1, int x2, int y2) {
    return sqrt((pow((x1 - x2), 2)) + (pow((y1 - y2), 2)));
}

void bubble_sort(vector<double>& distances) {
    for (int i = 0; i < distances.size(); i++) {
        for (int j = 0; j < distances.size() - 1 - i; j++) {
            if (distances[j + 1] < distances[j]) {
                swap(distances[j + 1], distances[j]);
            }
        }
    }
}

int main() {
    long long x, y;
    cin >> x >> y;

    int n, k;
    cin >> n >> k;

    vector<double> distances;
    for (int i = 0; i < n; i++) {
        long long x2, y2;
        cin >> x2 >> y2;
        distances.push_back(calculate_distance(x, y, x2, y2));
    }
    bubble_sort(distances);
    cout << distances[k - 1];
    return 0;
}