#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> pi(string s) {
    vector<int> res(s.size(), 0);
    for (int i = 1; i < s.size(); i++) {
        int j = res[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = res[j - 1];
        }
        if (s[j] == s[i]) {
            res[i] = j + 1;
        }
    }
    return res;
}


vector<int> subst(const string& s, const string& t) {
    vector<int> res;
    vector<int>p = pi(t + "#" + s);
    for (int i = 0; i < s.size(); i++) {
        if (p[i + 1 + t.size()] == t.size()) {
            res.push_back(i);
        }
    }
    return res;
}


int main() {
    string s, t;
    cin >> s >> t;
    vector<int> occurrences = subst(s, t);
    for (int pos : occurrences) {
        cout << pos << " ";
    }
    if (occurrences.empty()) cout << "No matches found";
    return 0;
}