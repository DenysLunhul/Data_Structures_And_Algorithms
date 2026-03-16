 #include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    int B[n];
    for (int i = 0 ; i < n; i++) {
        cin >> A[i];
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        B[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] and B[j] + 1 > B[i]) {
                B[i] = B[j] + 1;
            }
        }
        if (B[i] > result) {
            result = B[i];
        }
    }
    cout << result;
    return 0;
}