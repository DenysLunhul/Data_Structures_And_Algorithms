#include <iostream>
#include <string>
#include <vector>
#define MAX 101
using namespace std;


int guess_password(vector<string>& words, string& password, int ptr, vector<int>& memo) {
    if (ptr == password.length()) {
        return 0;
    }
    if (memo[ptr] != -1) {
        return memo[ptr];
    }
    int minimal = MAX;
    for (int i = 0; i < words.size(); i++) {
        int len_word = words[i].length();
        if (password.substr(ptr, len_word) == words[i]) {
            int temp = guess_password(words, password, ptr + len_word, memo);
            if (temp != MAX) {
                minimal = min(minimal, temp + 1);
            }
        }
    }
    memo[ptr] = minimal;
    return minimal;
}

int main() {
    string password;
    cin >> password;

    int n;
    cin >> n;

    vector<string> words(n, "");
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    int ptr = 0;
    vector<int> memo(password.length(), -1);
    int temp = guess_password(words, password, ptr, memo);
    if (temp != MAX) {
        cout << temp;
    }
    else {
        cout << -1;
    }
    return 0;
}