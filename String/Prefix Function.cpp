#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

/* 
Prefix Function: This function computes an array where each element pi[i] is the 
length of the longest proper prefix of the substring s[0...i] that is also a suffix of this substring.

=> proper prefix: A prefix that is not the entire substring.

.........i.....
____  ____
      phi(i)
*/

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


void solve() {
    string s1 = "ababca";
    // cin >> s1;
    vector<int> p = computePrefix(s1);
    for(auto &i: p) cout << i << " "; cout << endl;
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