#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// *s.find_by_order(k): K-th element in a set (counting from zero).
// s.order_of_key(k): Number of items strictly smaller than k. (same as lower_bound of k)
// less_equal<T> => for ordered_multiset or, ordered_multimap

int main()
{
    ordered_set<ll> s;
    s.insert(1);
    s.insert(2);
    cout << *s.find_by_order(0) << endl; // k th element
    cout << s.order_of_key(2) << endl;   // number of elements less than k

    ordered_map<int, ll> mp;
    mp.insert({1, 10});
    mp.insert({2, 20});
    cout << mp.find_by_order(0)->second << endl; // k th element
    cout << mp.order_of_key(2) << endl;          // number of first elements less than k
    
    return 0;
}
