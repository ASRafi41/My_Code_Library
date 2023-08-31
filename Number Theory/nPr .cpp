// CPP program to calculate nPr => O(N)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fact(ll n)
{
    if(n <= 1) return 1;
    return n * fact(n - 1);
}
ll nPr(ll n, ll r)
{
    return fact(n) / fact(n - r);
}
int main()
{
    ll n, r;
    cin>>n>>r;
    cout<<nPr(n, r);
}


