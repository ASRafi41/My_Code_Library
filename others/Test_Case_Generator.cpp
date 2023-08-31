#include<bits/stdc++.h>
typedef long long  ll;
#define endl       '\n'
#define F          first
#define S          second
#define pb         push_back
#define ppb        pop_back
#define yes        cout<<"YES\n"
#define no         cout<<"NO\n"
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define error(x)   cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define coutall(v) for(auto &it: v) cout<<it<<' '; cout<<endl;
#define _ASRafi__  ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
using namespace std;

int lowerval, upperVal;
int randomize() // function to generate random numbers in range [lowerval - upperVal] 
{
    return (rand() % (upperVal - lowerval + 1)) + lowerval;
}

int main()
{
    srand(time(NULL)); // for different values each time we run the code

    int n = 10;
    // cin>>n;

    vector<int> vec(n);

    lowerval = 1, upperVal = 100;
    generate(vec.begin(), vec.end(), randomize);

    // displaying the content of vector
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    return 0;
}
