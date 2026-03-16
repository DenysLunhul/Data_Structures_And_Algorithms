#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;
    int j = left - 1;
    while (i < right) {
        if (arr[i] < pivot) {
            j++;
            if (arr[i] != arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
        i++;
    }
    swap(arr[j + 1], arr[right]);
    return j;
}

void quick_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int split = partition(arr, left, right);
        quick_sort(arr, left, split - 1);
        quick_sort(arr, split + 1, right);
    }
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 9, 6, 7, 8, 2};
    quick_sort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}