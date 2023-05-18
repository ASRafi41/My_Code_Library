// Time Complexity: O(q * log(N)) 
#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
#define _ASRafi__  ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
using namespace std;

/* 1'base indexing */
const int N = 3e5 + 9;
ll bit1[N]; 
ll bit2[N];
ll n;

void update(ll i, ll x, ll *bit)	// O(logn)
{
	while (i < N)
	{
		bit[i] += x;
		i += (i & (-i));
	}
}

ll query(ll i, ll *bit)	//O(logn)
{
	ll sum = 0;
	while (i > 0)
	{
		sum += bit[i];
		i = (i & (i - 1));
	}
	return sum;
}

void rupdate(ll l, ll r, ll val)
{
	update(l, val, bit1);
	update(r + 1, -val, bit1);

	update(l, val * (l - 1), bit2);
	update(r + 1, -val * r, bit2);
}

ll rquery(ll l, ll r)
{
	ll sum1 = query(r, bit1) * r - query(r, bit2); // Sum of elements in [1, r]
    ll sum2 = query(l-1, bit1) * (l-1) - query(l-1, bit2); // Sum of elements in [1, l-1]
    return sum1 - sum2; // Sum of elements in [l,r] = Sum of elements in [1,r] - Sum of elements in [1, l-1]
}

void reset()
{
	for (int i = 0; i < N; i++)
		bit1[i] = bit2[i] = 0;
}

void solve()
{
    int q;
    cin >> n >> q;
    ll a[n + 10];
    for (int i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        a[i] = x;
        rupdate(i, i, x);
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll i;
            cin >> i;
            cout << a[i + 1] << endl;
            rupdate(i + 1, i + 1, -a[i + 1]);
            a[i + 1] = 0;
        }
        else if (type == 2)
        {
            ll i, v;
            cin >> i >> v;
            a[i + 1] = a[i + 1] + v;
            rupdate(i + 1, i + 1, v);
        }
        else
        {
            ll i, j;
            cin >> i >> j;
            cout << rquery(i + 1, j + 1) << endl;
        }
    }
	return;
}

int main()
{
	_ASRafi__;
	int tc = 1;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		reset();
		cout << "Case " << i << ":\n";
		solve();
	}
	return 0;
}
