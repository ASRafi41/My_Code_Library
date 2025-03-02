#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

/*
This function computes an array z where each z[i] represents the length of the 
longest substring starting at i which matches the prefix of the entire string. 

............i............
______      _______
            z(i)
*/

vector<int> computeZ(const string &s) { // O(n)
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void solve() {
    string s = "abcaab";
    vector<int> Z = computeZ(s);
    for(auto &i: Z) cout << i << " "; cout << endl;
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
