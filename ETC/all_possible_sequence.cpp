#include<bits/stdc++.h>
typedef long long  ll;
#define endl       '\n'
#define F          first
#define S          second
#define pb         push_back
#define ppb        pop_back
#define yes        cout<<"YES\n"
#define no         cout<<"NO\n"
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define error(x)   cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define coutall(v) for(auto &it: v) cout<<it<<' '; cout<<endl;
#define _ASRafi__  ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
using namespace std;

void solve()
{
    ll n = 6, t = 1e4;
    // cin >> n;
    set<vector<ll>> ans;
    while (t--)
    {
        vector<ll> v(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll x = (rand() % n) + 1; // 1-n values
            v[i] = x;

            // conditions
            sum += x;
        }
        // coutall(v);
        if (sum % n == 0) // Is the condition matching the question?
        {
            sort(all(v)); // If the order doesn't matter.
            ans.insert(v);
        }
    }
    cout << "<-----"<< n << "----->\n";
    for (auto i : ans)
    {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return;
}
int main()
{
    _ASRafi__;
    int tc=1;
    // cin>>tc;
    while(tc--) solve();
    return 0;
}