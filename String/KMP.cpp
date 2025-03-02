#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

vector<int> computePrefix(const string &s) { // O(N)
    int n = s.size(), j = 0;
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

/*
The KMP algorithm (Knuth-Morris-Pratt) is a method 
for finding a pattern within a text efficiently.
*/

vector<int> kmpSearch(const string &text, const string &pattern) { // O(n + m)
    string s = pattern + "#" + text;
    vector<int> pi = computePrefix(s);
    vector<int> occurrences;
    int pLen = pattern.size();
    for (int i = pLen + 1; i < s.size(); i++) {
        if (pi[i] == pLen) {
            occurrences.push_back(i - 2 * pLen);
        }
    }
    return occurrences;
}

void solve() {
    string text = "abababcabab";
    string pattern = "abab";
    vector<int> positions = kmpSearch(text, pattern); 
    for(auto &i: positions) cout << i << " "; cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}