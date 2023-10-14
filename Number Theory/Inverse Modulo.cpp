#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
long long bigmod(long long a, long long b) // log(n)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

long long inverseModulo(long long A, long long B) // log(n)
{
    long long inverse = ((A % mod) * (bigmod(B, mod - 2) % mod)) % mod;
    return (inverse + mod) % mod;
}

int main()
{
    int a = 10, b = 5, mul;

    mul = inverseModulo(a, b);
    cout << mul << endl; // 2

    return 0;
}
