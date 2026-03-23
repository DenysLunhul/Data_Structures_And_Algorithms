#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int right, int mid) {
    vector<int> merged;
    int final_place = left;
    int ptr1 = left;
    int ptr2 = mid + 1;

    while(ptr1 <= mid and ptr2 <= right) {
        if (arr[ptr1] < arr[ptr2]) {
            merged.push_back(arr[ptr1]);
            ptr1++;
        }
        else {
            merged.push_back(arr[ptr2]);
            ptr2++;
        }
    }

    while (ptr1 <= mid) {
        merged.push_back(arr[ptr1]);
        ptr1++;
    }

    while (ptr2 <= right) {
        merged.push_back(arr[ptr2]);
        ptr2++;
    }

    for (int i = 0; i < merged.size(); i++) {
        arr[final_place + i] = merged[i];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, right, mid);
    }
}

int main() {
    return 0;
}