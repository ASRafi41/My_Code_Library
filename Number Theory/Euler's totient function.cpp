#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;

/// Find the co-prime between(1 to i);
/// Time Complexity: O(NloglogN)

const int N = 1e6 +7;
int coprimeCnt[N];
ll coprimeSum[N];

void generatePhi()
{
    for (int i = 0; i < N; ++i) coprimeCnt[i] = i;
    for (int i = 2; i < N; i++)
    {
        if (coprimeCnt[i] == i)
        {
            for (int j = i; j < N; j += i)
                coprimeCnt[j] -= coprimeCnt[j] / i;
        }
    }

    // Sum of all coprime values (Ex: 10 => 1 + 3 + 7 + 9 = 20)
    coprimeSum[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        coprimeSum[i] = (1LL * i * coprimeCnt[i]) >> 1;
        // cout << i << " => " << coprimeCnt[i] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    generatePhi(); // <=== build

    // Sum of Co-prime
    int i = 10; 
    cout << coprimeSum[i] << endl;

    return 0;
}
