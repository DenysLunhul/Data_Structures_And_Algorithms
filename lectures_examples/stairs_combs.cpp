#include <iostream>
using namespace std;

int count(int* arr, const int n) {
    if (n == 0) {return 1;}
    if (n == 1) {return 1;}
    if (n == 2) {return 2;}

    if (arr[n] != 0) {
        return arr[n];
    }
    arr[n] = count(arr, n - 3) + count(arr, n - 2) + count(arr, n - 1);
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0 ; i <= n; i++) {
        arr[i] = 0;
    }
    cout << count(arr, n);
    return 0;
}