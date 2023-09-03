#include<bits/stdc++.h>
using namespace std;

const int Mod = 1e9 + 7;
long long bigMod(long long a, long long b) // log(n)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % Mod;
        a = (a * a) % Mod;
        b >>= 1;
    }
    return ans;
}

long long inverseModulo(long long A, long long B) // log(n)
{
    long long inverse = ((A % Mod) * (bigMod(B, Mod - 2) % Mod)) % Mod;
    return (inverse + Mod) % Mod;
}

int main()
{
    int a = 10, b = 5, mul;

    mul = inverseModulo(a, b);
    cout << mul << endl; // 2

    return 0;
}
