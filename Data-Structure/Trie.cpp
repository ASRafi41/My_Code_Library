#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *next[26];
    bool completedWord;
    node()
    {
        completedWord = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} *root;

void trieInsert(string s)
{
    node *cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int x = s[i] - 'a';
        if (cur->next[x] == NULL)
        {
            cur->next[x] = new node();
        }
        cur = cur->next[x];
    }
    cur->completedWord = true;
}
bool trieSearch(string s)
{
    node *cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int x = s[i] - 'a';
        if (cur->next[x] == NULL)
        {
            return false;
        }
        cur = cur->next[x];
    }
    return cur->completedWord;
}
void reset(node* cur)   //Delete the tree after every test case for memory efficiency
{
    for(int i=0; i<26; i++)
        if(cur->next[i]) 
            reset(cur->next[i]);
    delete(cur);
}
int main()
{
    int tc=1;
    cin>>tc;
    while (tc--)
    {
        root = new node();
        int n, q;
        cin >> n >> q;
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            trieInsert(s);
        }
        while (q--)
        {
            cin >> s;
            if (trieSearch(s))
                cout << "Found\n";
            else
                cout << "Not Found\n";
        }
        reset(root);
    }
    return 0;
}
