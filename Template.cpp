#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long     ll;
//typedef __int128_t    lll;
typedef long double   ld; // %Lf
#define endl          '\n'
#define F             first
#define S             second
#define pb            push_back
#define ppb           pop_back
#define pll           pair<ll, ll>
#define yes           cout<<"YES\n"
#define no            cout<<"NO\n"
#define all(x)        x.begin(),x.end()
#define allr(x)       x.rbegin(),x.rend()
#define CheckBit(x,k) (x & (1LL << k))
#define SetBit(x,k)   (x |= (1LL << k))
#define ClearBit(x,k) (x &= ~(1LL << k))
#define MSB(mask)     63-__builtin_clzll(mask) 
#define LSB(mask)     __builtin_ctzll(mask)  
#define error1(x)     cerr << #x << " = " << (x) <<endl
#define error2(a,b)   cerr<<"("<<#a<<", "<<#b<<") = ("<<(a)<<", "<<(b)<<")\n";
#define coutall(v)    for(auto &it: v) cout<<it<<" "; cout<<endl;
#define UNIQUE(x)     sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define _ASRafi__     ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
using namespace __gnu_pbds;

template <typename T, typename U> T ceil(T x, U y) {return (x > 0 ? (x + y - 1) / y : x / y);}
template <typename T, typename U> T floor(T x, U y) {return (x > 0 ? x / y : (x - y + 1) / y);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // mt19937_64 (long long)
auto my_rand(long long l,long long r)   // random value generator [l, r]
{
    return uniform_int_distribution<long long>(l,r)(rng);
}

// const int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1}; // king's move(0 to 3 index=> Side Moves)
// const int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; // king's move(4 to 7 index=> Diagonal Moves)
// const int kx[] = {-2, -2, -1, -1, +1, +1, +2, +2}; // knight's move
// const int ky[] = {-1, +1, -2, +2, -2, +2, -1, +1}; // knight's move

// const long double pi = 2 * acos(0.0);
// const ll N = 1e5 + 10, mod = 1e9 + 7;

void solve()
{
    ll n, m, k, c = 0, ans = 0;
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
int32_t main()
{
    _ASRafi__;
    #ifndef ONLINE_JUDGE
        // auto st = clock(); // Current Time
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        // freopen("error.txt", "w", stderr);
    #endif
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
    // cerr << "Time = " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "\n";
    return 0;
}
