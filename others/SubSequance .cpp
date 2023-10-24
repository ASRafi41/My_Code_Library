#include<bits/stdc++.h>
typedef long long   ll;
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define yes         cout<<"YES\n"
#define no          cout<<"NO\n"
#define all(x)      x.begin(),x.end()
#define allr(x)     x.rbegin(),x.rend()
#define error1(x)   cerr<<#x<<" = "<<(x)<<endl
#define error2(a,b) cerr<<"("<<#a<<", "<<#b<<") = ("<<(a)<<", "<<(b)<<")\n";
#define coutall(v)  for(auto &it: v) cout<<it<<" "; cout<<endl;
#define _ASRafi__   ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> allSubSets;
    int n = nums.size();
    for (int mask = 0; mask < (1 << n); mask++) // for 2^n possible solution
    {
        vector<int> subset;
        for (int j = 0; j < n; j++) // for nums array
        {
            if (mask & (1 << j))
            {
                subset.push_back(nums[j]);
            }
        }
        allSubSets.push_back(subset);
    }
    return allSubSets;
}

int32_t main()
{
    // _ASRafi__;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> allSubSets = subsets(v);
    for(auto &i: allSubSets)
    {
        for(auto &j: i) cout << j << " "; cout << endl;
    }
    return 0;
}
