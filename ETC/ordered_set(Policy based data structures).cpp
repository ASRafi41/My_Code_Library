#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// *s.find_by_order(k): K-th element in a set (counting from zero).
// s.order_of_key(k): Number of items strictly smaller than k. (same as lower_bound of k)

int main()
{
    ll q, v;
    ordered_set<ll> s;

    cin >> q;
    while(q--)
    {
        char ch;
        cin >> ch >> v;

        if (ch == 'I') s.insert(v);
        else if (ch == 'D') s.erase(v);
        else if (ch == 'C') //return the number of elements of S smaller than x
        {
            cout << s.order_of_key(v) << "\n";
        }
        else if (ch == 'K')
        {
            if (v > s.size()) cout << "invalid\n";
            else cout << *s.find_by_order(v - 1) << "\n";
        }
    }
    return 0;
}
