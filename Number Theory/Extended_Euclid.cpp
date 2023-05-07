#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll extended_euclid(ll a, ll b, ll &x, ll &y)    //=> O(log(min(a, b))) 
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extended_euclid(b, a % b, x1, y1);
    x = y1, y = x1 - y1 * (a / b);
    return gcd;
}
ll inverse(ll a, ll m)
{
    ll x, y;
    ll g = extended_euclid(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}
int32_t main()
{
    // (a*x) + (b*y) = gcd(a, b);
    ll a, b, x, y, gcd;
    cin>>a>>b; //55, 80
    gcd = extended_euclid(a, b, x, y);
    cout<<x<<" "<<y<<" "<<gcd<<endl;
    return 0;
}