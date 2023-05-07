//O(nlog(n))
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>divisor[N];
int main()
{
    for(int i=2; i<N; i++)
    {
        for(int j=i; j<N; j+=i)
        {
            divisor[j].push_back(i);
        }
    }
    int n;
    cin>>n;
    for(auto &it: divisor[n]) cout<<it<<" ";
    cout<<endl;
}
