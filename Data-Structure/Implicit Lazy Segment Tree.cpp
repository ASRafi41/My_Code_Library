#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

struct Node {
    ll value; // Holds the aggregated value for the node
    ll lazy; // Lazy propagation value
    
    Node *left, *right;
    Node() : value(0), lazy(0), left(nullptr), right(nullptr) {}
};

class ImplicitLazySegmentTree {
private:
    Node* root;
    int startRange, endRange; // Define the logical range of the segment st1
    function<ll(ll, ll)> combine; // Combiner function (e.g., sum, max, min)

    // Push lazy updates down to children
    void propagate(Node*& node, int l, int r) {
        if (!node || node->lazy == 0) return;

        node->value += node->lazy * (r - l + 1); // Apply the lazy value

        // Propagate to children if not a leaf
        if (l != r) {
            if (!node->left) node->left = new Node();
            if (!node->right) node->right = new Node();

            node->left->lazy += node->lazy;
            node->right->lazy += node->lazy;
        }

        node->lazy = 0; // Clear the lazy value for the current node
    }

    // Update range [q_l, q_r] by adding `val`
    void update(Node*& node, int l, int r, int q_l, int q_r, ll val) {
        if (!node) node = new Node();
        propagate(node, l, r);

        if (l > r || q_r < l || q_l > r) return; // No overlap

        if (q_l <= l && r <= q_r) { // Total overlap
            node->lazy += val;
            propagate(node, l, r);
            return;
        }

        // Partial overlap
        int mid = (l + r) >> 1;
        update(node->left, l, mid, q_l, q_r, val);
        update(node->right, mid + 1, r, q_l, q_r, val);

        node->value = combine(
            node->left ? node->left->value : 0,
            node->right ? node->right->value : 0
        );
    }

    // Query the range [q_l, q_r]
    ll query(Node* node, int l, int r, int q_l, int q_r) {
        if (!node || l > r || q_r < l || q_l > r) return 0; // No overlap

        propagate(node, l, r);

        if (q_l <= l && r <= q_r) return node->value; // Total overlap

        // Partial overlap
        int mid = (l + r) >> 1;
        ll leftResult = query(node->left, l, mid, q_l, q_r);
        ll rightResult = query(node->right, mid + 1, r, q_l, q_r);

        return combine(leftResult, rightResult);
    }

    // Cleanup allocated nodes
    void cleanup(Node*& node) {
        if (!node) return;

        cleanup(node->left);
        cleanup(node->right);
        delete node;
        node = nullptr;
    }

public:
    // Constructor
    ImplicitLazySegmentTree(int startRange, int endRange, function<ll(ll, ll)> combine)
        : startRange(startRange), endRange(endRange), combine(combine) {
        root = nullptr;
    }

    // Destructor
    ~ImplicitLazySegmentTree() {
        cleanup(root);
    }

    // Public update method
    void update(int q_l, int q_r, ll val) {
        update(root, startRange, endRange, q_l, q_r, val);
    }

    // Public query method
    ll query(int q_l, int q_r) {
        return query(root, startRange, endRange, q_l, q_r);
    }
};
// Example usage: Range sum segment st1 with range [-1e9, 1e9]
ImplicitLazySegmentTree st1(-1e9, 1e9, [](ll a, ll b) { return a + b; });

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    // Perform updates
    st1.update(1, 3, 10);    // Add 10 to range [1, 3]
    st1.update(2, 5, 5);     // Add 5 to range [2, 5]
    st1.update(-213, -10, 7); // Add 7 to range [-213, -10]

    // Perform queries
    cout << "Sum of range [-100, 123]: " << st1.query(-100, 123) << "\n"; 
    cout << "Sum of range [2, 4]: " << st1.query(2, 4) << "\n"; 
    cout << "Sum of range [1, 5]: " << st1.query(1, 5) << "\n"; 

    return 0;
}
