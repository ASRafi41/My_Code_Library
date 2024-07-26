#include<bits/stdc++.h>
typedef long long   ll;
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define yes         cout<<"YES\n"
#define no          cout<<"NO\n"
#define all(x)      x.begin(),x.end()
#define allr(x)     x.rbegin(),x.rend()
#define error1(x)   cerr<<#x<<" = "<<(x)<<endl
#define error2(a,b) cerr<<"("<<#a<<", "<<#b<<") = ("<<(a)<<", "<<(b)<<")\n";
#define coutall(v)  for(auto &it: v) cout<<it<<" "; cout<<endl;
#define _ASRafi__   ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

ll maximumSubArraySum(vector<ll> &v) {
    ll sum = 0, ans = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v[i];
        if(sum < 0) sum = 0;
        ans = max(ans, sum);
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        v[i] = x;
    }
    ll mxSum = maximumSubArraySum(v);
    cout << mxSum << endl;
    return;
}

int32_t main()
{
    _ASRafi__;
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}