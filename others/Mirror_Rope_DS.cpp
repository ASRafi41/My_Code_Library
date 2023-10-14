#include <bits/stdc++.h>
using namespace std;

#include <ext/rope> //header with rope
using namespace __gnu_cxx; //namespace with rope and some additional stuff

// push_back(val)       => O(log n) time complexity. This operation adds an element to the end of the rope.
// substr(pos, sz)      => O(log n) time complexity. This operation creates a new rope that contains a substring of the original rope.
// erase(pos, sz)       => O(log n) time complexity. This operation removes a range of elements from the rope.
// insert(pos, rope)    => O(log n) time complexity [Worst Case: O(N)]. This operation inserts elements at a specified position in the rope.
// replace(l, sz, rope) => O(log n) time complexity. Replaces the l(1'st) elements beginning with the xth(2nd) element with the elements in r1(3rd).
// mutable_begin()  => O(1) time complexity. This operation returns an iterator to the beginning of the rope.
// mutable_end()    => O(1) time complexity. This operation returns an iterator to the end of the rope.
// concatenate(+)   => O(1) time complexity. Concatenate two ropes using the ‘+’ symbol.

void print(rope<int> &v)
{
    for(rope <int>::iterator it = v.mutable_begin(); it != v.mutable_end(); ++it) 
    {
        cout << *it << " ";
    }
    cout << endl;
}

void swapSubstrings(rope<int> &r, int l1, int r1, int l2, int r2)
{
    rope<int> sub1 = r.substr(l1, r1 - l1 + 1);
    rope<int> sub2 = r.substr(l2, r2 - l2 + 1);

    r.replace(l1, r1 - l1 + 1, sub2);
    r.replace(l2, r2 - l2 + 1, sub1);
}

void rangeReverseQuery()    // 0'base
{
    int n, q;   // maximum n <= 10^5
    cin >> n >> q;

    rope<int> v, rev; // {1, 2, 3, 4, 5,... }
    for(int i = 1; i <= n; i++) v.push_back(i); // initialization 0'base values 1 to n 

    for(rope <int>::iterator it = prev(v.mutable_end()); it != v.mutable_begin(); --it) 
    {
        rev.push_back(*it); // reversing the Rope
    }
    rev.push_back(*v.mutable_begin());

    v += rev; // concatenate two rope

    int l, r;
    while(q--)
    {
        cin >> l >> r;
        --l, --r; // 0'base

        // print(v);
        swapSubstrings(v, l, r, 2 * n - r - 1, 2 * n - l - 1);
        // print(v);
    }
    
    cout << "Final Array is: ";
    int cnt = 0;
    for(rope <int>::iterator it = v.mutable_begin(); it != v.mutable_end(); ++it) 
    {
        cout << *it << " ";
        if(++cnt == n) break;
    }
    cout << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    // Normal Use
    /* 
    rope <int> v; // use as usual STL container
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) v.push_back(i); //initialization values 1 to n

    int l, r;
    for(int i = 0; i < q; ++i) // querys
    {
        cin >> l >> r;
        --l, --r;
        rope <int> cur = v.substr(l, r - l + 1); // store the range string
        v.erase(l, r - l + 1);  // erasing the l to r portion. (first parameter = position, second parameter = size);
        v.insert(v.mutable_begin(), cur); // inserting in the front
    } 
    */

    rangeReverseQuery(); 

    return 0;
}

// Ref: https://codeforces.com/blog/entry/107434
// Ref: https://www.geeksforgeeks.org/stl-ropes-in-c/

// Problem: https://www.acmicpc.net/problem/14131
// Code: https://ideone.com/wSDiPA
