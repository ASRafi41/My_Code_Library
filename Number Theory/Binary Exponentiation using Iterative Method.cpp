// Time Complexity -> O(log(b));    //best method
#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;
long long BinExpIter(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a;
            //ans=(ans*a)%M;
        }
        a=a*a;
        //a=(a*a)%M;
        b>>=1;
    }
    return ans;
}
int main()
{
    long long a,b,ans;
    cin>>a>>b;
    ans=BinExpIter(a,b);
    cout<<ans;
}
