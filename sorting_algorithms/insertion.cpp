#include <vector>
using namespace std;


void insertion_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int value = arr[i];
        int insert_pos = i;
        for (int j = 0 ; j < i; j++) {
            if (arr[j] > value) {
                insert_pos = j;
                break;
            }
        }
        for (int k = i; k > insert_pos; k--) {
            arr[k] = arr[k - 1];
        }
        arr[insert_pos] = value;
    }
}


int main() {
    return 0;
}