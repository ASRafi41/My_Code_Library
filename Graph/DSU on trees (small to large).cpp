// Problem link: https://codeforces.com/problemset/problem/600/E
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> clr(n + 1);
    for(int i = 1; i <= n; i++) cin >> clr[i];
    vector<vector<int>> g(n + 1);
    for(int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> bigChild(n + 1);
    auto dfs1 = [&](auto&& self, int u, int p) -> int {
        int uSz = 0, vSz;
        for(auto &v: g[u]) {
            if(v == p) continue;
            vSz = self(self, v, u);
            if(uSz < 1 + vSz) {
                uSz = 1 + vSz;
                bigChild[u] = v;
            }
        }
        return uSz;
    };
    dfs1(dfs1, 1, 0);
    
    // for(int i = 1; i <= n; i++) cout << i << " = " << bigChild[i] << endl;

    vector<ll> ans(n + 1);
    vector<int> mxClrCnt(n + 1);
    map<int, int> mp[n + 1];
    function<void(int, int)> dfs2 = [&](int u, int p) -> void {
        for(auto &v: g[u]) {
            if(v == p) continue;
            dfs2(v, u);
        }

        // Calculate the Ans
        auto& bc = bigChild[u];
        swap(mp[u], mp[bc]);
        int curMxCnt = mxClrCnt[bc];
        ll curAns = ans[bc];
        auto& curMp = mp[u];
        
        // Cur Node
        curMp[clr[u]]++;
        if(curMp[clr[u]] > curMxCnt) {
            curMxCnt = curMp[clr[u]];
            curAns = clr[u];
        }
        else if(curMp[clr[u]] == curMxCnt) {
            curAns += clr[u];
        }

        // Child Node
        for(auto &v: g[u]) {
            if(v == p or bc == v) continue;
            for(auto &[clr1, cnt1]: mp[v]) {
                curMp[clr1] += cnt1;
                if(curMp[clr1] > curMxCnt) {
                    curMxCnt = curMp[clr1];
                    curAns = clr1;
                }
                else if(curMp[clr1] == curMxCnt) {
                    curAns += clr1;
                }
            }
        }
        
        mxClrCnt[u] = curMxCnt;
        ans[u] = curAns;
        return;
    };
    dfs2(1, 0);

    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    return 0;
}
