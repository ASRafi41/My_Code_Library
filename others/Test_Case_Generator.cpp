#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// mt19937_64 (long long)
auto my_rand(long long l,long long r)   // random value generator [l, r]
{
    return uniform_int_distribution<long long>(l,r)(rng);
}

int lowerVal, upperVal;
int randomize() // function to generate random numbers in range [lowerval - upperVal] 
{
    return my_rand(lowerVal, upperVal);
}

int main()
{
    srand(time(NULL)); // for different values each time we run the code

    int n = my_rand(1, 20);
    // cin>>n;

    vector<int> vec(n);

    lowerVal = 1, upperVal = 100;
    generate(vec.begin(), vec.end(), randomize);

    // displaying the content of vector
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    return 0;
}
