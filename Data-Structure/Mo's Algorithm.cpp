// Time Complexity: O((N+Q) * sqrt(N))
#include <bits/stdc++.h>    
#define endl '\n'
using ll = long long;
using namespace std;

const int N = 1e6 + 3;
int a[N], rootN;

int block_get(int ind) {
    return ind / rootN;
}
int block_get_start(int block) {
    return (rootN * block);
}
int block_get_end(int block) {
    return min(N - 1, rootN * (block + 1) - 1);
}

struct Q {
    int l, r, idx;
};
Q q[N];

// bool comp(Q &q1, Q &q2) {
//     if (q1.l / rootN == q2.l / rootN) return q1.r > q2.r;
//     return q1.l / rootN < q2.l / rootN;
// }
bool comp(Q &p, Q &q) { // faster 
    if (p.l / rootN != q.l / rootN) return (p.l == q.l ? p.r <= q.r : p.l < q.l); // return p < q;
    return (p.l / rootN & 1) ? (p.r < q.r) : (p.r > q.r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int query; cin >> query;
    rootN = sqrtl(n) + 1;
    for (int i = 0; i < query; ++i) {
        int l, r; cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }

    sort(q, q + query, comp);
    int curr_l = 0, curr_r = -1, l, r;
    ll curr_ans = 0;
    vector<ll> ans(query);
    for (int i = 0; i < query; i++) {
        l = q[i].l, r = q[i].r;
        --l, --r;

        auto include = [&](int idx) -> void {
            curr_ans += a[idx];
        };
        while (curr_r < r) {
            ++curr_r;
            include(curr_r);
        }
        while (curr_l > l) {
            --curr_l;
            include(curr_l);
        }
        
        auto exclude = [&](int idx) -> void {
            curr_ans -= a[idx];
        };
        while (curr_l < l) {
            exclude(curr_l);
            ++curr_l;
        }
        while (curr_r > r) {
            exclude(curr_r);
            --curr_r;
        }

        auto getAns = [&]() -> ll {
            return curr_ans;
        };
        ans[q[i].idx] = getAns();
    }
    
    for (int i = 0; i < query; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
// Mo's + Square root decomposition => 
https://codeforces.com/contest/1000/submission/316444520
