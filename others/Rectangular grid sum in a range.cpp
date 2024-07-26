#include<bits/stdc++.h>
using namespace std;

// To find the rectangular grid sum in a range with complexity O(1)

class NumMatrix {
    private:
    vector<vector<int>> prefixSum;

    public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefixSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum[row2 + 1][col2 + 1] - prefixSum[row1][col2 + 1] - prefixSum[row2 + 1][col1] + prefixSum[row1][col1];
    }
};

int main()
{
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                  {5, 6, 3, 2, 1},
                                  {1, 2, 0, 1, 5},
                                  {4, 1, 0, 1, 7},
                                  {1, 0, 3, 0, 5}};

    NumMatrix numMatrix(matrix); // 0'base indexing 

    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl; // Output: 8
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl; // Output: 11
    cout << numMatrix.sumRegion(1, 1, 2, 3) << endl; // Output: 14

    return 0;
}
