// C++ implementation to find nCr
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Function to find the nCr     =>O(r*log(n))
ll nCr(ll n, ll r)
{
    ll p= 1, k=1, m;
    if(n-r<r)r=n-r;
    if(r!=0)
    {
        while(r)
        {
            p*=n, k*=r;
            m=__gcd(p, k);
            p/=m, k/=m;
            n--, r--;
        }
    }
    else p=1;
    return p;
}
int main()
{
    long long n,r;
    cin>>n>>r;
    nCr(n, r);
}
