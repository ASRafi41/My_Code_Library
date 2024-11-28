#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

struct Node {
    ll value; // Modify as per requirement (e.g., sum, max, min)

    Node* left;      // Pointer to left child
    Node* right;     // Pointer to right child
    Node() : value(0), left(nullptr), right(nullptr) {} // Initialize as required
};

class ImplicitSegmentTree {
    Node* root;
    int startRange, endRange; // Define the range of the segment st1
    function<ll(ll, ll)> combine; // Combiner function

    // Update value at a specific position
    void update(Node*& node, int l, int r, int pos, ll val) {
        if (!node) node = new Node();
        if (l == r) {
            node->value += val; // Modify update logic as needed
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(node->left, l, mid, pos, val);
        } 
        else {
            update(node->right, mid + 1, r, pos, val);
        }
        node->value = combine(node->left ? node->left->value : 0, node->right ? node->right->value : 0);
    }

    // Query the range [ql, qr]
    ll query(Node* node, int l, int r, int ql, int qr) {
        if (!node || l > qr || r < ql) return 0; // Modify base case (e.g., INF for min, -INF for max)
        if (l >= ql && r <= qr) return node->value;
        int mid = l + (r - l) / 2;
        ll leftResult = query(node->left, l, mid, ql, qr);
        ll rightResult = query(node->right, mid + 1, r, ql, qr);
        return combine(leftResult, rightResult);
    }

public:
    // Constructor
    ImplicitSegmentTree(int startRange, int endRange, function<ll(ll, ll)> combine)
        : startRange(startRange), endRange(endRange), combine(combine) { root = nullptr; }

    // Public update method
    void update(int pos, ll val) {
        update(root, startRange, endRange, pos, val);
    }

    // Public query method
    ll query(int ql, int qr) {
        return query(root, startRange, endRange, ql, qr);
    }
};
// Example usage: Sum Segment Tree with range [-1e9, 1e9]
ImplicitSegmentTree st1(-1e9, 1e9, [](ll a, ll b) { return a + b; }); // <=====

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    // Perform updates
    st1.update(5, 10);   // Add 10 at position 5
    st1.update(100, 20); // Add 20 at position 100
    st1.update(-50, 15); // Add 15 at position -50

    // Perform queries
    cout << "Query [0, 10]: " << st1.query(0, 10) << "\n";      // Query the sum in range [0, 10]
    cout << "Query [-20, 10]: " << st1.query(-50, 10) << "\n";    // Query the sum in range -20, 10]
    cout << "Query [-100, 100]: " << st1.query(-100, 100) << "\n"; // Query the sum in range [-100, 100]

    return 0;
}
