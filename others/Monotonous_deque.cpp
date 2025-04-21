// problem link: https://cses.fi/boi24/task/3221
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

struct Monotonous_deque {
    deque<int> dq;

    void add(int x) {
        while(!dq.empty() && dq.back() > x) {
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void remove(int x) {
        if(!dq.empty() && dq.front() == x) {
            dq.pop_front();
        }
    }

    int get_min() {
        return dq.empty() ? 0 : dq.front();
    }
} mq;

const int N = 1e7 + 3;
int v[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k, x, a, b, c, xorr = 0;
    cin >> n >> k >> x >> a >> b >> c;
    for(int i = 0; i < n; i++) {
        v[i] = x;
        mq.add(x);
        if(i >= k - 1) {
            xorr ^= mq.get_min();
            mq.remove(v[i - k + 1]);
        }
        x = (1LL * a * x + b) % c;
    }
    cout << xorr << endl;
    return 0;
}
