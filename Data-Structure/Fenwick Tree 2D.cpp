// problem link: https://codeforces.com/contest/2055/problem/C
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

class FenwickTree2D {
private:
    vector<vector<ll>> tree;
    int rows, cols;

public:
    FenwickTree2D(int rows, int cols) : rows(rows), cols(cols) {
        tree.resize(rows + 1, vector<ll>(cols + 1, 0));
    }

    void update(int x, int y, ll value) {
        for (ll i = x + 1; i <= rows; i += i & -i) {
            for (ll j = y + 1; j <= cols; j += j & -j) {
                tree[i][j] += value;
            }
        }
    }

    ll query(int x, int y) {
        ll sum = 0;
        for (ll i = x + 1; i > 0; i -= i & -i) {
            for (ll j = y + 1; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    ll rangeQuery(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }

    ll sumRow(int row) {
        return rangeQuery(row, 0, row, cols - 1);
    }

    ll sumCol(int col) {
        return rangeQuery(0, col, rows - 1, col);
    }
};

void solve() {
    int n, m;
    string s1;
    cin >> n >> m >> s1;
    vector<vector<ll>> g(n, vector<ll> (m));
    FenwickTree2D ft(n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            ft.update(i, j, g[i][j]);
        }
    }
    int r = 0, c = 0, i = 0;
    while(true) {
        if(s1[i] == 'D') {
            g[r][c] = 0 - ft.sumRow(r);
            ft.update(r, c, g[r][c]);
            ++r;
        }
        else {
            g[r][c] = 0 - ft.sumCol(c);
            ft.update(r, c, g[r][c]);
            ++c;
        }
        ++i;

        if(i == s1.size()) {
            g[r][c] = 0 - ft.sumCol(c);
            ft.update(r, c, g[r][c]);
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ft.rangeQuery(i, j, i, j) << " \n"[j + 1 == m];
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
