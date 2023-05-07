#include<bits/stdc++.h>
using namespace std;
//{1,1,1,1,1}, {1,1,1,1,2}, {1,1,1,1,3}, and so on, up to {5,5,5,5,5}.
void generate_combinations(int n, int k, vector<int>& combination, int start) {
    if (k == 0) {
        // Output the current combination
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i] << " ";
        }
        cout << endl;
        return;
    }
    // Try all integers from start to n
    for (int i = start; i <= n; i++) {
        combination.push_back(i);
        generate_combinations(n, k-1, combination, i);
        combination.pop_back();
    }
}

int main() {
    int n = 5, k = 5;
    vector<int> combination;
    generate_combinations(n, k, combination, 1);
    return 0;
}
