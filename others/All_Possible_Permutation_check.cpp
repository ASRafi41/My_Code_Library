#include<bits/stdc++.h>
using ll = long long;
#define all(x) x.begin(),x.end()
#define coutall(v) for(auto &it: v) cout<<it<<' '; cout<<endl;
using namespace std;

void solve()
{
    ll n = 6, sum = 0;
    cin >> n;
    
    vector<ll> v(n);
    iota(all(v), 1);
    // coutall(v);

    do
    {
        coutall(v);
    } while (next_permutation(all(v)));
    
    return;
}
int main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}
