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
#define coutall(v) for(auto &it: v) {cout<<it<<' ';} cout<<endl;
#define _ASRafi__  ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
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
        // coutall(v);
        set<ll> st;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            sum %= n;
            st.insert(sum);
        }
        if (st.size() == n)
        {
            for (auto i : v) cout << i << " ";
            cout << endl;
        }
    } while (next_permutation(all(v)));
    
    return;
}
int main()
{
    _ASRafi__;
    int tc=1;
    cin>>tc;
    while(tc--) solve();
    return 0;
}
