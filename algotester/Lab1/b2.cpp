#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string text;
    cin >> text;
    string word = "TOILET";
    int ptr = 0;
    int temp = ptr;
    for (int i = 0; i < text.length(); i++) {
        if (word[ptr] == text[i]) {
            ptr++;
            if (ptr == 6) {
                n--;
                ptr = 0;
            }
        }
        else {
            ptr = 0;
            if (temp != ptr) {
                i--;
            }
        }
        temp = ptr;
    }
    if (n <= 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}