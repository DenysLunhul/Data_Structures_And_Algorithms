#include <iostream>
#include <vector>
#define NUM 1000000007
using namespace std;

long long trace_combinations(int current_points, int cubes_left, int target_points, vector<vector<int>>& mem, vector<vector<bool>>& visited) {
    if (visited[cubes_left][current_points]) {
        return mem[cubes_left][current_points];
    }
    if (current_points == target_points and cubes_left == 0) {
        return 1;
    }
    if (cubes_left * 6 + current_points < target_points) {return 0;}
    if (cubes_left * 1 + current_points > target_points) {return 0;}
    if (cubes_left == 0) {return 0;}

    long long result = 0;
    for (int i = 1; i <= 6; i++) {
        result += trace_combinations(i + current_points, cubes_left - 1, target_points,mem, visited);
    }
    visited[cubes_left][current_points] = true;
    mem[cubes_left][current_points] = result % NUM;
    return mem[cubes_left][current_points];
}

int main() {
    int cubes, points;
    cin >> cubes >> points;

    vector<vector<int>> mem(cubes + 1, vector<int>(points+1, 0));
    vector<vector<bool>> visited(cubes + 1, vector<bool>(points+1, false));
    long long res = trace_combinations(0, cubes, points, mem, visited);
    cout << res;
    return 0;
}