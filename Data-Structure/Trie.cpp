#include <bits/stdc++.h>
using namespace std;

struct Trie {
    static const int rangeSize = 26; // for lower_case letter ('a' <= 'z')
    static const char startingChar = 'a'; // for lower_case letter ('a' <= 'z')

    struct node {
        node *next[rangeSize]; 
        bool completedWord;
        int cnt;
        node() {
            completedWord = false;
            cnt = 0;
            for (int i = 0; i < rangeSize; i++)
                next[i] = nullptr;
        }
    } *root;

    Trie() {
        root = new node();
    }

    void Insert(const string &s) {
        node *cur = root;
        for (char ch : s) {
            int x = ch - startingChar;
            if (cur->next[x] == nullptr) {
                cur->next[x] = new node();
            }
            cur = cur->next[x];
            cur->cnt += 1;
        }
        cur->completedWord = true;
    }

    void Delete(const string &s) {
        node *cur = root;
        for (char ch : s) {
            int x = ch - startingChar;
            // if (cur->next[x] == nullptr) {
            //     cur->next[x] = new node();
            // }
            cur = cur->next[x];
            cur->cnt -= 1;
        }
        if(cur->cnt == 0) cur->completedWord = false;
    }

    bool Search(const string &s) {
        node *cur = root;
        for (char ch : s) {
            int x = ch - startingChar;
            if (cur->next[x] == nullptr) {
                return false;
            }
            cur = cur->next[x];
        }
        return cur->completedWord;
    }

    int prefixCount(const string &s) {
        node *cur = root;
        for (char ch : s) {
            int x = ch - startingChar;
            if (cur->next[x] == nullptr) {
                return 0;
            }
            cur = cur->next[x];
        }
        return cur->cnt;
    }

    void reset(node* cur) {
        for(int i = 0; i < rangeSize; i++)
            if(cur->next[i])
                reset(cur->next[i]);
        delete cur;
    }

    void clear() {
        reset(root);
        root = new node();
    }

    ~Trie() { // Destructor 
        reset(root);
    }
} trie;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        trie.clear(); // <===
        int n, q;
        cin >> n;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            trie.Insert(s);
        }
        cin >> q;
        while (q--) {
            cin >> s;
            if (trie.Search(s)) cout << "Found\n";
            else cout << "Not Found\n";
        }
    }
    return 0;
}
