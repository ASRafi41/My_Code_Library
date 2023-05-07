#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const ll N = 1e7+10;

void commonDivisors(ll n)
{
    ll c=0,i;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i==n/i) ++c;
            else c+=2;
        }
    }
    cout<<c;
}
int main()
{
    ll n,gcd=0;
    cin>>n;
    vector<ll>v(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        gcd=__gcd(gcd,v[i]);
    }
    commonDivisors(gcd);
    return 0;
}
