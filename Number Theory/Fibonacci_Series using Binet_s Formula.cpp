// Fibonacci Series using Binet's Nth-term Formula
#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    double phi = (sqrt(5) + 1) / 2;
    return round(pow(phi, n) / sqrt(5));
}
int main()
{
    int n;
    cin>>n;
    cout << fib(n);
    return 0;
}
