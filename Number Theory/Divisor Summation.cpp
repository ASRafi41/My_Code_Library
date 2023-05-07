// => O(sqrt(n));
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7+10;
//const double pi=2*acos(0.0); //or, pi=3.14159265358979323846;

ll solve()
{
    ll n,sum=0,i,c=0;
    cin>>n;
    for(i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            sum+=i;//++c;
            if(i!=n/i) sum+=n/i;//,++c;
        }
    }
    //cout<<"Count= "<<c<<" Sum= "<<endl;
    return sum;
}
int main()
{
    int tc,x=1;
    cin>>tc;
    while(tc--)
    {
        //printf("Case %d: ",x);
        //++x;
        //solve();
        cout<<solve()<<endl;        /// ASRafi.solve();
    }
    return 0;
}
