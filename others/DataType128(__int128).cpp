#include <bits/stdc++.h>
using namespace std;

//--------------__int128---------------------
// INT128_MAX = 2^127 - 1 = 10^38

__int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
string __int128toString(__int128 num)
{
    auto tenPow18 = 1000000000000000000;
    string str;
    do
    {
        long long digits = num % tenPow18;
        auto digitsStr = to_string(digits);
        auto leading0s = (digits != num) ? string(18 - digitsStr.length(), '0') : "";
        str = leading0s + digitsStr + str;
        num = (num - digits) / tenPow18;
    } while (num != 0);
    return str;
}
bool cmp(__int128 x, __int128 y) { return x > y; }

//----------------------X---------------------------

void solve()
{
    string s1, s2;

    __int128 a = read();
    print(a);
    cout<<endl;

    s1 = __int128toString(a);
    cout<<s1<<endl;
    return;
}
int32_t main()
{
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    return 0;
}
