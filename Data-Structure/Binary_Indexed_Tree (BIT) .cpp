// Time Complexity: O(q * log(N)) 
#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

/* 1'base indexing */
const int N = 3e5 + 9;
ll bit1[N]; 
ll bit2[N];
int n;

void update(int i, int x, ll *bit)	// O(logn)
{
	while (i <= n)
	{
		bit[i] += x;
		i = i + (i & (-i));
	}
}

ll sum(int i, ll *bit)	//O(logn)
{
	ll ans = 0;
	while (i != 0 && i > 0)
	{
		ans += bit[i];
		i = (i & (i - 1));
	}
	return ans;
}

void rupdate(int l, int r, int val)
{
	update(l, val, bit1);
	update(r + 1, -val, bit1);

	update(l, val * (l - 1), bit2);
	update(r + 1, -val * r, bit2);
}

ll rsum(int l, int r)
{
	ll sum1 = sum(r, bit1) * r - sum(r, bit2); // Sum of elements in [1, r]
    ll sum2 = sum(l-1, bit1) * (l-1) - sum(l-1, bit2); // Sum of elements in [1, l-1]
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
    int a[n + 10];
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        a[i] = x;
        rupdate(i, i, x);
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i;
            cin >> i;
            cout << a[i + 1] << endl;
            rupdate(i + 1, i + 1, -a[i + 1]);
            a[i + 1] = 0;
        }
        else if (type == 2)
        {
            int i, v;
            cin >> i >> v;
            a[i + 1] = a[i + 1] + v;
            rupdate(i + 1, i + 1, v);
        }
        else
        {
            int i, j;
            cin >> i >> j;
            cout << rsum(i + 1, j + 1) << endl;
        }
    }
	return;
}

int main()
{
	int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        reset();
        cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}
