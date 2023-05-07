//=> O(log(n));
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
vector<int> spf(N);  // SPF : smallest prime factor

void sieve()        ///=> O(n log(log(n)))
{
    for(int i=1; i<N; i++)
    {
        spf[i]=i;
    }
    for(int i=2; i*i<N; i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i; j<N; j+=i)
            {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}
int main()
{
    sieve();
    int n;
    cin>>n;
    while(n!=1)
    {
        cout<<spf[n]<<" ";
        n/=spf[n];
    }
}
