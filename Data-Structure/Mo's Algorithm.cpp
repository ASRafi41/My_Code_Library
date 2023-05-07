#include <bits/stdc++.h>    //=> O((N+Q)*sqrt(N))
using namespace std;
#define ll long long
const int N = 1e5 + 10;
int rootN;

struct Q
{
    int l, r, idx;
};
Q q[N];
bool comp(Q q1, Q q2)
{
    if (q1.l / rootN == q2.l / rootN) return q1.r > q2.r;
    return q1.l / rootN < q2.l / rootN;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int query;
    cin >> query;
    rootN = sqrtl(n) + 1;
    for (int i = 0; i < query; ++i)
    {
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    sort(q, q + query, comp);
    int curr_l = 0, curr_r = -1, l, r;
    ll curr_ans = 0;
    vector<ll> ans(query);
    for (int i = 0; i < query; i++)
    {
        l = q[i].l, r = q[i].r;
        --l, --r;
        while (curr_r < r)
        {
            curr_r++;
            curr_ans += a[curr_r];
        }
        while (curr_l > l)
        {
            curr_l--;
            curr_ans += a[curr_l];
        }
        while (curr_l < l)
        {
            curr_l++;
            curr_ans -= a[curr_l];
        }
        while (curr_r > r)
        {
            curr_r--;
            curr_ans -= a[curr_r];
        }
        ans[q[i].idx] = curr_ans;
    }
    for (int i = 0; i < query; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}