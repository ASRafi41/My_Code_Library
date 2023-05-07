#include <bits/stdc++.h>
using namespace std;
// min value problem
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // preprocessing
    int rootN = sqrtl(n) + 1;
    int block[rootN];
    for (int i = 0; i < rootN; ++i) block[i] = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        // block[i/rootN]+= a[i];   //sum
        block[i / rootN] = min(block[i / rootN], a[i]);
    }

    // answering the queries
    int q;
    cin >> q;
    while (q--) //=> O(q*sqrt(n))
    {
        int l, r, ans = INT_MAX, sum = 0;
        cin >> l >> r;
        for (int i = l; i <= r;) //=> O(sqrt(n))
        {
            if (i % rootN == 0 && i + rootN - 1 <= r)
            {
                // sum+=block(i/rootN);
                ans = min(ans, block[i / rootN]);
                i += rootN;
            }
            else
            {
                // sum+=a[i];
                ans = min(ans, a[i]);
                ++i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}