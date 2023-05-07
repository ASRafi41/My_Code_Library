#include <bits/stdc++.h>    => O(x*log(N*10^d))
using namespace std;

double eps=1e-6;    // eps=1e-d; =>with d decimal accuracy
double BinExpPow(double n, int x)
{
    double l = 0, r = n, m = (l + r) / 2;
    while (r - l > eps)
    {
        if (pow(m, x) > n) r = m;
        else l = m;
        m = (l + r) / 2;
    }
    return m;
}

int main()
{
    double n; int x;
    cin >> n >> x;
    cout << fixed << setprecision(10) << BinExpPow(n, x) << endl;
    return 0;
}