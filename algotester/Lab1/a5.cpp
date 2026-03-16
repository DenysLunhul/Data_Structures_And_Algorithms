#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cin >> text;
    int counter = 0;
    for (int i = 0; i < text.length() - 1; i++) {
        if (text[i] == text[i + 1]) {
            counter++;
        }
    }
    cout << counter;
    return 0;
}
