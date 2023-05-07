#include<bits/stdc++.h>
typedef long long       ll;
#define endl            '\n'
#define F               first
#define S               second
#define pb              push_back
#define ppb             pop_back
#define pll             pair<ll,ll>
#define yes             cout<<"YES\n"
#define no              cout<<"NO\n"
#define all(x)          x.begin(),x.end()
#define allr(x)         x.rbegin(),x.rend()
#define CheckBit(x,k)   (x & (1LL << k))
#define SetBit(x,k)     (x |= (1LL << k))
#define ClearBit(x,k)   (x &= ~(1LL << k))
#define MSB(mask)       63-__builtin_clzll(mask) 
#define LSB(mask)       __builtin_ctzll(mask)  
#define error(x)        cerr << #x << " = " << (x) <<endl
#define Error(a,b)      cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define coutall(v)      for(auto &it: v)cout<<it<<' ';cout<<endl;
#define _ASRafi__       ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
using namespace std;

// const int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1}; // king's move(0 to 3 index=> Side Moves)
// const int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; // king's move(4 to 7 index=> Diagonal Moves)
// const int kx[] = {-2, -2, -1, -1, +1, +1, +2, +2}; // knight's move
// const int ky[] = {-1, +1, -2, +2, -2, +2, -1, +1}; // knight's move
// const long double pi = 2 * acos(0.0);
// const ll N = 1e7 + 10, mod = 1e9 + 7;

void solve()
{
    ll n, m, k1, c = 0, ans = 0;
    string s1, s2;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        v[i] = x;
        
    }
    
    return;
}
int main()
{
    _ASRafi__;
    /* #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif */
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
