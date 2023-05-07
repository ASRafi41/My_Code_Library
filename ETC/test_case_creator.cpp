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
    ll t=1e2, n=6;
    //cin >> n;
    set<vector<ll>>s;
    while(t--)
    {
        vector<ll>v;
        ll sum=0;
        for(int i=0; i<n; i++)
        {
            ll x;
            do
            {
                x=(rand()%n)+1;
            } while(find(all(v),x)!=v.end());

            sum+=x;
            sum%=n;
            v.pb(x);
        }
        //coutall(v);
        if(n==v.size())
        {
           s.insert(v);
        }
    }
    for(auto i: s)
    {
        cout<<"=> ";
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }
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