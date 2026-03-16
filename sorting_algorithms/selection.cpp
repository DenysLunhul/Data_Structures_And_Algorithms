#include <vector>
using namespace std;


void selection_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min = i;
        for (int j = i; j < arr.size(); j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}


int main() {
    return 0;
}