#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1e9 + 7;

int main() {
    string s1;
    cin >> s1;
    ll ans = 0;
    for(auto &c: s1) {
        ans = (ans * 10) + (c - '0'); // add back
        ans %= mod; // mod
    }
    cout << ans << endl;
    return 0;
}