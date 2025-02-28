#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 1e6 + 7;
const int Base1 = 137, Base2 = 277;
const int mod1 = 127657753, mod2 = 987654319;
 
pair<ll, ll> po[N];
void generatePower() {
    po[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        po[i].first = (po[i - 1].first * Base1) % mod1;
        po[i].second = (po[i - 1].second * Base2) % mod2;
    }
}

struct SegNode {
    pair<ll, ll> fhash;
    pair<ll, ll> rhash;
    int len;
};
 
struct SegmentTree {
    int n;
    string s;
    vector<SegNode> tree;
 
    void build(string &str) {
        s = str;
        n = s.size();
        if(po[0].first != 1) generatePower();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
 
    SegNode combine(const SegNode &L, const SegNode &R) {
        SegNode res;
        res.len = L.len + R.len;
        res.fhash.first = ((L.fhash.first * po[R.len].first) % mod1 + R.fhash.first) % mod1;
        res.fhash.second = ((L.fhash.second * po[R.len].second) % mod2 + R.fhash.second) % mod2;

        res.rhash.first = ((R.rhash.first * po[L.len].first) % mod1 + L.rhash.first) % mod1;
        res.rhash.second = ((R.rhash.second * po[L.len].second) % mod2 + L.rhash.second) % mod2;
        return res;
    }
 
    void build(int idx, int l, int r) {
        if(l == r) {
            tree[idx].len = 1;
            tree[idx].fhash = {s[l], s[l]};
            tree[idx].rhash = {s[l], s[l]};
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        tree[idx] = combine(tree[2 * idx], tree[2 * idx + 1]);
    }
 
    void update(int idx, int l, int r, int pos, char newChar) {
        if(l == r) {
            s[pos] = newChar;
            tree[idx].fhash = {newChar, newChar};
            tree[idx].rhash = {newChar, newChar};
            tree[idx].len = 1;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(2 * idx, l, mid, pos, newChar);
        else update(2 * idx + 1, mid + 1, r, pos, newChar);
        tree[idx] = combine(tree[2 * idx], tree[2 * idx + 1]);
    }
 
    SegNode query(int idx, int l, int r, int ql, int qr) {
        if(ql > r || qr < l) {
            SegNode ret;
            ret.len = 0;
            ret.fhash = {0, 0};
            ret.rhash = {0, 0};
            return ret;
        }
        if(ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) >> 1;
        SegNode leftNode = query(2 * idx, l, mid, ql, qr);
        SegNode rightNode = query(2 * idx + 1, mid + 1, r, ql, qr);
        return combine(leftNode, rightNode);
    }
    
    void update(int pos, char newChar) {
        update(1, 0, n - 1, pos, newChar);
    }

    // Returns forward hash of substring [l, r].
    pair<ll, ll> getPrefixRangeHash(int l, int r) {
        return query(1, 0, n - 1, l, r).fhash;
    }
 
    // Returns reverse hash of substring [l, r]
    pair<ll, ll> getSuffixRangeHash(int l, int r) {
        return query(1, 0, n - 1, l, r).rhash;
    }
} st;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    string s1;
    cin >> n >> m >> s1;
    st.build(s1); // <==
    short type;
    while(m--) {
        cin >> type;
        if(type == 1) {
            int pos; char ch;
            cin >> pos >> ch;
            st.update(pos - 1, ch);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            if(st.getPrefixRangeHash(l, r) == st.getSuffixRangeHash(l, r)) {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }
    return 0;
}
// link: https://cses.fi/problemset/task/2420
