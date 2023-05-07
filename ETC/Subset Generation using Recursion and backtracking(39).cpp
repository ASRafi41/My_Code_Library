#include<bits/stdc++.h>
using namespace std;
const double pi=2*acos(0.0); //or, pi=3.141592653589793238463;
vector<vector<int>> subsets;
//vector<int> nums;
void generate(vector<int>&ss,int i,vector<int>&nums)
{
    if(i==nums.size())
    {
        subsets.push_back(ss);
    }
    //ith element not in ss(subset)
    generate(ss,i+1,nums);
    //ith element in ss
    ss.push_back(nums[i]);
    generate(ss,i+1,nums);
    ss.pop_back();
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int> empty;
    generate(empty,0,nums);
    for(auto &ss: subsets)
    {
        for(auto &ele: ss)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}


